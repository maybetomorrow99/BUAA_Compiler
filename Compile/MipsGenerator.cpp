#include "mips.h"

MipsGenerator::MipsGenerator(string asmPath) {
	mipsout.open(asmPath);
}

/*
判断该局部变量是否在寄存器中
目前，将所有的临时变量放在内存中，将局部变量/常量（不包括参数）的前8个放在寄存器中，对应寄存器t2-t9
*/
bool MipsGenerator::inReg(string name) {
	if (name[0] == '$')
		return false;
	int addr = symTab.search(name).addr;
	int para = symTab.getCurFunc().para;
	SymbolKind kind = symTab.search(name).kind;
	if ((kind == VARKD || kind == CONSTKD) && addr < para * 4 + 8 * 4) {
		return true;
	}
	return false;
}


/*
变量寄存器从t2开始
将局部变量/常量的前8个放入寄存器中
因为在符号表中函数表项还占有一个位置，所以要先-4
*/
int MipsGenerator::getRegNum(string name) {
	int addr = symTab.search(name).addr;
	int para = symTab.getCurFunc().para;
	return 2 + (addr - 4 - para * 4) / 4;
}


/*
获取变量相对于fp的偏移，注意变量也有可能是参数
TODO:目前先给所有的变量都开辟空间，只不过靠前部分的变量实际上存储在寄存器中
*/
int MipsGenerator::getOffset(string name) {
	if (symTab.isPara(name))
		return symTab.search(name).addr - 4;	//此处和符号表中相差4，因为在符号表中函数表项还占有一个位置
	return symTab.search(name).addr + 32 * 4 - 4;	
}


/*
根据四元式生成Mips代码
*/
void MipsGenerator::genMips() {
	mipsout << "#" << curq.toString() << endl;
	if (curq.oper == "CON") {
		mipsCON();
	}
	else if (curq.oper == "VAR") {
		mipsVAR();
	}
	else if (curq.oper == "ARY") {
		mipsARY();
	}
	else if (curq.oper == "FUNC") {
		mipsFUNC();
	}
	else if (curq.oper == "ADD" || curq.oper == "SUB" || curq.oper == "MUL" || curq.oper == "DIV") {
		mipsCal();
	}
	else if (curq.oper == "PARA") {
		mipsPARA();
	}
	else if (curq.oper == "CALL") {
		mipsCALL();
	}
	else if (curq.oper == "PUSH") {
		mipsPUSH();
	}
	else if (curq.oper == "VOF") {
		mipsVOF();
	}
	else if (curq.oper == "LI") {
		mipsLI();
	}
	else if (curq.oper == "LVAR") {
		mipsLVAR();
	}
	else if (curq.oper == "SARY") {
		mipsSARY();
	}
	else if (curq.oper == "LARY") {
		mipsLARY();
	}
	else if (curq.oper == "PC") {
		mipsPC();
	}
	else if (curq.oper == "PI") {
		mipsPI();
	}
	else if (curq.oper == "READ") {
		mipsREAD();
	}
	else if (curq.oper == "RET") {
		mipsRET();
	}
	else if (curq.oper == "REN") {
		mipsREN();
	}
	else if (curq.oper == "BGT") {
		mipsBGT();
	}
	else if (curq.oper == "BGE") {
		mipsBGE();
	}
	else if (curq.oper == "BEQ") {
		mipsBEQ();
	}
	else if (curq.oper == "BLE") {
		mipsBLE();
	}
	else if (curq.oper == "BLT") {
		mipsBLT();
	}
	else if (curq.oper == "BNE") {
		mipsBNE();
	}
	else if (curq.oper == "JUMP") {
		mipsJUMP();
	}
	else if (curq.oper == "LAB") {
		mipsLAB();
	}
}


/*
全局变量部分，包括常量定义、变量定义
CON	√	√	√	常量定义
const int a = 6	==> CON int 6 a
VAR	√		√	单一变量声明
int a ==> VAR int a
ARY	√	√	√	数组变量声明
int a[100] ==> ARY int 100 a
字符串常量
*/
int MipsGenerator::mipsGlobal() {
	int index = 0;
	mipsout << ".data" << endl;
	curq = quaterList[0];
	while (curq.oper != "FUNC") {
		if (curq.oper == "CON") {
			mipsout << curq.res << ": .word " << curq.op2 << endl;
		}
		else if (curq.oper == "VAR") {
			mipsout << curq.res << ": .space 4" << endl;
		}
		else {	//curq.oper == "ARY"
			mipsout << curq.res << ": .word 0: " << curq.op2 << endl;
		}
		curq = quaterList[++index];
	}

	//字符串常量
	for (int i = 0; i < stringPool.size(); i++) {
		mipsout << "$string" << i << ": .asciiz \"" << stringPool[i] << "\"" << endl;
	}
	mipsout << "$enter: .asciiz \"\\n\"" << endl;

	mipsout << ".text" << endl;
	mipsout << "j main" << endl;
	return index;

}

/*
CON	√	√	√	常量定义	
const int a = 6	==> CON int 6 a
*/
void MipsGenerator::mipsCON() {
	string cname = curq.res;
	int value = atoi(curq.op2.c_str());
	int addr = -getOffset(cname);;
	if (inReg(cname)) {
		int regNum = getRegNum(cname);
		mipsout << "li $t" << regNum << ", " << value << endl;
	}
	else {
		mipsout << "li $t0, " << value << endl;
		mipsout << "sw $t0, " << addr << "($fp)" << endl;
	}
}


/*
VAR	√		√	单一变量声明
int a ==> VAR int a
*/
void MipsGenerator::mipsVAR() {

}


/*
ARY	√	√	√	数组变量声明
int a[100] ==> ARY int 100 a
*/
void MipsGenerator::mipsARY() {
	
}


/*
FUNC	√		√	函数声明
int foo ==> FUNC int foo
*/
void MipsGenerator::mipsFUNC() {
	string fname = curq.res;
	int fsize = symTab.searchFunc(fname).value;
	int para = symTab.searchFunc(fname).para;
	symTab.updateCurFuncAddr(fname);
	mipsout << fname << ":" << endl;

	//分配栈空间
	mipsout << "add $fp, $sp, " << para * 4 << endl;
	mipsout << "subi $sp, $sp, " << fsize - para * 4 + 32 * 4 << endl;
	//mipsout << "sw $ra, 0($sp)" << endl;	//TODO:保存ra是用跳转？
}


/*
ADD	√	√	√	加法
SUB	√	√	√	减法
MUL	√	√	√	乘法
DIV	√	√	√	除法
x = a - b ==> ADD a b x
参与sub运算的应该都是临时变量
*/
void MipsGenerator::mipsCal() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//读取a
	if (inReg(op1name)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(op1name);
		mipsout << "move $t0 $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int op1addr = -getOffset(op1name);
		mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	}

	//读取b
	if (inReg(op2name)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(op2name);
		mipsout << "move $t1 $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	}

	//计算x
	if (curq.oper == "ADD") {
		mipsout << "add $t0, $t0, $t1" << endl;
	}
	else if (curq.oper == "SUB") {
		mipsout << "sub $t0, $t0, $t1" << endl;
	}
	else if (curq.oper == "MUL") {
		mipsout << "mult $t0, $t1" << endl;
		mipsout << "mflo $t0" << endl;
	}
	else {	//curq.oper == "DIV"
		mipsout << "div $t0, $t1" << endl;
		mipsout << "mflo $t0" << endl;
	}

	//读取等式左边并赋值
	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
}


/*
PARA √		√	函数参数定义
int foo(int a) ==> PARA int a
*/
void MipsGenerator::mipsPARA() {
	
}


/*
CALL		√	函数调用
x = tar(a, b) ==> CALL tar
*/
void MipsGenerator::mipsCALL() {
	string fname = curq.res;
	//symTab.updateCurFuncAddr(fname);
	int para = symTab.searchFunc(fname).para;

	//此时参数已经使sp的位置下降
	for (int i = 8; i <= 25; i++) {	//保存临时寄存器等
		mipsout << "sw $" << i << ", " << -i * 4 << "($sp)" << endl;
	}
	mipsout << "sw $fp ," << -30 * 4 << "($sp)" << endl;
	mipsout << "sw $ra ," << -31 * 4 << "($sp)" << endl;

	mipsout << "jal " << fname << endl;

	for (int i = 8; i <=25 ; i++) {
		mipsout << "lw $" << i << ", " << -para * 4 - i * 4 << "($sp)" << endl;
	}
	mipsout << "lw $fp ," << -para * 4 - 30 * 4 << "($sp)" << endl;
	mipsout << "lw $ra ," << -para * 4 - 31 * 4 << "($sp)" << endl;
}


/*
PUSH			√	函数传参
x = tar(a, b)  ==> PUSH a
*/
void MipsGenerator::mipsPUSH() {	//TODO:a一定是临时变量
	string name = curq.res;
	int addr = -getOffset(name);
	
	mipsout << "lw $t0, " << addr << "($fp)" << endl;
	mipsout << "sw $t0, ($sp)" << endl;
	mipsout << "subi $sp, $sp, 4" << endl;
}


/*
VOF	√		√	接受函数返回值
x = tar(a, b)	VOF tar x
操作类似赋值，等号左边为临时变量
*/
void MipsGenerator::mipsVOF() {
	string resname = curq.res;

	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $v0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $" << regNum << ", $v0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $v0, " << resaddr << "($fp)" << endl;
	}
}


/*
LI	√		√	立即数赋值
x = 1 ==> LI 1 x
*/
void MipsGenerator::mipsLI() {
	string value = curq.op1;
	string name = curq.res;
	int addr = -getOffset(name);
	
	mipsout << "li $t0, " << value << endl;
	mipsout << "sw $t0, " << addr << "($fp)" << endl;
}


/*
LVAR √		√
变量赋值	x = y	LVAR y x
需要判断是全局变量还是局部变量，对两边都要判断
*/
void MipsGenerator::mipsLVAR() {
	string op1name = curq.op1;
	string resname = curq.res;

	//读取等式右边
	if (symTab.isGlobal(op1name)) {	//是全局变量
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op1name)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(op1name);
		mipsout << "move $t0 $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int op1addr = -getOffset(op1name);
		mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	}

	//读取等式左边
	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum<< ", $t0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
}


/*
SARY √	√	√	数组元素赋值
array[i] = x ==> SARY arrary i x
i 和 x应该都是局部变量
*/
void MipsGenerator::mipsSARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//读取i到t0
	if (symTab.isGlobal(op2name)) {	//是全局变量
		mipsout << "la $t1, " << op2name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op2name)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(op2name);
		mipsout << "move $t0 $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t0, " << op2addr << "($fp)" << endl;
	}

	//将t0改为相对数组偏移量
	mipsout << "mul $t0, $t0, 4" << endl;

	//读取array地址并加上偏移，最终地址为t0
	if (symTab.isGlobal(op1name)) {	//是全局变量
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "add $t0, $t0, $t1 " << endl;
	}
	else {							//是不在寄存器中的局部变量，数组只能这样
		int op1addr = -getOffset(op1name);
		mipsout << "addi $t1, $fp, " << op1addr << endl;
		mipsout << "sub $t0, $t1, $t0" << endl;
	}

	//读取等式右边的值到t0,x只能为局部变量
	if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t1 $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "lw $t1, " << resaddr << "($fp)" << endl;
	}

	//赋值
	mipsout << "sw $t1, ($t0)" << endl;
}


/*
LARY	√	√	√
取数组元素	x = array[i]	LARY array i x
x和i应该为局部变量
*/
void MipsGenerator::mipsLARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//读取i到t0
	if (symTab.isGlobal(op2name)) {	//是全局变量
		mipsout << "la $t1, " << op2name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op2name)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(op2name);
		mipsout << "move $t0 $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t0, " << op2addr << "($fp)" << endl;
	}

	//将t0改为相对数组偏移量
	mipsout << "mul $t0, $t0, 4" << endl;

	//读取array地址并加上偏移，最终地址为t0
	if (symTab.isGlobal(op1name)) {	//是全局变量
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "add $t0, $t0, $t1 " << endl;
	}
	else {							//是不在寄存器中的局部变量，数组只能这样
		int op1addr = -getOffset(op1name);
		mipsout << "addi $t1, $fp, " << op1addr << endl;
		mipsout << "sub $t0, $t1, $t0" << endl;
	}

	//取值到t0
	mipsout << "lw $t0, ($t0)" << endl;

	//读取等式左边并赋值
	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}

}


/*
PC			√	输出字符串
printf("hello")	PC 1
*/
void MipsGenerator::mipsPC() {
	mipsout << "li $v0, 4" << endl;
	mipsout << "la $a0, $string" << curq.res << endl;
	mipsout << "syscall" << endl;

	mipsout << "li $v0, 4" << endl;
	mipsout << "la $a0," << "$enter" << endl;
	mipsout << "syscall" << endl;
}


/*
PI			√	输出整数或字符
printf(x)	PI x
x为临时变量
*/
void MipsGenerator::mipsPI() {
	string name = curq.res;
	int addr = -getOffset(name);
	SymbolType type = symTab.search(name).type;
	
	if (type == INTTP)
		mipsout << "li $v0, 1" << endl;
	else
		mipsout << "li $v0, 11" << endl;

	mipsout << "lw $a0, " << addr << "($fp)" << endl;
	mipsout << "syscall" << endl;
	
	mipsout << "li $v0, 4" << endl;
	mipsout << "la $a0," << "$enter" << endl;
	mipsout << "syscall" << endl;
}


/*
READ			√	读取整数或字符
scanf(a)	RI a
*/
void MipsGenerator::mipsREAD() {
	string resname = curq.res;
	SymbolType type = symTab.search(resname).type;
	
	if (type == INTTP)
		mipsout << "li $v0, 5" << endl;
	else
		mipsout << "li $v0, 12" << endl;
	mipsout << "syscall" << endl;

	//读取等式左边
	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $v0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $v0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $v0, " << resaddr << "($fp)" << endl;
	}
}


/*
RET			√	返回表达式的值
return a; ==> RET a
*/
void MipsGenerator::mipsRET() {
	string name = curq.res;
	int addr = -getOffset(name);
	int fsize = symTab.getCurFunc().value;
	int para = symTab.getCurFunc().para;
	mipsout << "lw $v0, " << addr << "($fp)" << endl;
	mipsout << "addi $sp, $sp, " << fsize + 32 * 4 << endl;
	mipsout << "jr $ra" << endl;
}


/*
REN				返回空
return;	REN
*/
void MipsGenerator::mipsREN() {
	//cout << symTab.getCurFunc().name << endl;
	if (symTab.getCurFunc().name == "main") {
		mipsout << "li $v0," << 10 << endl;
		mipsout << "syscall" << endl;
		return;
	}
	int fsize = symTab.getCurFunc().value;
	int para = symTab.getCurFunc().para;
	mipsout << "addi $sp, $sp, " << fsize + 32 * 4 << endl;
	mipsout << "jr $ra" << endl;
}


/*
BGT√	√	√	大于比较跳转
a > b ==> BGT a b lab
*/
void MipsGenerator::mipsBGT() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "bgt $t0, $t1, " << label << endl;
}


/*
BGE √	√	√	大于等于比较跳转
a >= b ==> BGE a b lab
*/
void MipsGenerator::mipsBGE() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "bge $t0, $t1, " << label << endl;
}


/*
BEQ	√	√	√	等于跳转
a==b ==> BEQ a b lab
*/
void MipsGenerator::mipsBEQ() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "beq $t0, $t1, " << label << endl;
}


/*
BLE	√	√	√	小于等于比较跳转
a <= b ==> BLE a b lab
*/
void MipsGenerator::mipsBLE() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "ble $t0, $t1, " << label << endl;
}


/*
BLT √	√	√	小于比较跳转
a < b ==> BLT a b lab
*/
void MipsGenerator::mipsBLT() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "blt $t0, $t1, " << label << endl;
}


/*
BNE	√	√	√	不等于跳转
a != b ==> BNE a b lab
*/
void MipsGenerator::mipsBNE() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "bne $t0, $t1, " << label << endl;
}


/*
JUMP			√	无条件跳转
JUMP Lable1
*/
void MipsGenerator::mipsJUMP() {
	mipsout << "j " << curq.res << endl;
}


/*
LAB			√	设置标签
LAB Lable1
*/
void MipsGenerator::mipsLAB() {
	mipsout << curq.res << ":" << endl;
}



void MipsGenerator::startWorking() {
	int glbIndex;
	glbIndex = mipsGlobal();
	for (int i = glbIndex; i < quaterList.size(); i++) {
		curq = quaterList[i];
		genMips();
	}
}