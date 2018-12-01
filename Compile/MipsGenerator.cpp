#include "mips.h"

MipsGenerator::MipsGenerator(string asmPath) {
	mipsout.open(asmPath);
}

/*
判断该局部变量是否在寄存器中
目前，将所有的临时变量放在内存中，将局部变量的前8个放在寄存器中，对应寄存器t2-t9
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
*/
int MipsGenerator::getRegNum(string name) {
	int addr = symTab.search(name).addr;
	int para = symTab.getCurFunc().para;
	return 2 + (addr - para * 4) / 4;
}


/*
获取变量相对于fp的偏移
TODO:目前先给所有的变量都开辟空间，只不过靠前部分的变量实际上存储在寄存器中
*/
int MipsGenerator::getOffset(string name) {
	return symTab.search(name).addr + 32 * 4;
}


/*
根据四元式生成Mips代码
*/
void MipsGenerator::genMips() {
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
	else if (curq.oper == "ADD") {
		mipsADD();
	}
	else if (curq.oper == "SUB") {
		mipsSUB();
	}
	else if (curq.oper == "MUL") {
		mipsMUL();
	}
	else if (curq.oper == "DIV") {
		mipsDIV();
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

	}
	else if (curq.oper == "LARY") {

	}
	else if (curq.oper == "PC") {

	}
	else if (curq.oper == "PI") {
		mipsPI();
	}
	else if (curq.oper == "READ") {

	}
	else if (curq.oper == "RET") {
		mipsRET();
	}
	else if (curq.oper == "REN") {

	}
	else if (curq.oper == "BGT") {

	}
	else if (curq.oper == "BGE") {

	}
	else if (curq.oper == "BEQ") {

	}
	else if (curq.oper == "BLE") {

	}
	else if (curq.oper == "BLT") {
		mipsBLT();
	}
	else if (curq.oper == "BNE") {

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

	mipsout << ".text" << endl;

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
	symTab.updateCurFuncAddr(fname);
	mipsout << fname << ":" << endl;

	//分配栈空间
	mipsout << "subi $sp, $sp, " << fsize + 32 * 4 << endl;
	//mipsout << "sw $ra, 0($sp)" << endl;	//TODO:保存ra是用跳转？
}


/*
ADD	√	√	√	加法
x = a + b ==> ADD a b x
*/
void MipsGenerator::mipsADD() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	int op1addr = symTab.search(op1name).addr;
	int op2addr = symTab.search(op2name).addr;
	int resaddr = symTab.search(resname).addr;
	
	mipsout << "lw $t0, " << op1addr << "($sp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($sp)" << endl;
	mipsout << "add $t2, $t0, $t1" << endl;
	mipsout << "sw $t2, " << resaddr << "($sp)" << endl;
}


/*
SUB	√	√	√	减法
x = a - b ==> SUB a b x
*/
void MipsGenerator::mipsSUB() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	int op1addr = symTab.search(op1name).addr;
	int op2addr = symTab.search(op2name).addr;
	int resaddr = symTab.search(resname).addr;

	mipsout << "lw $t0, " << op1addr << "($sp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($sp)" << endl;
	mipsout << "sub $t2, $t0, $t1" << endl;
	mipsout << "sw $t2, " << resaddr << "($sp)" << endl;
}


/*
MUL	√	√	√	乘法
x = a * b ==> MUL a b x
*/
void MipsGenerator::mipsMUL() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	int op1addr = symTab.search(op1name).addr;
	int op2addr = symTab.search(op2name).addr;
	int resaddr = symTab.search(resname).addr;

	mipsout << "lw $t0, " << op1addr << "($sp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($sp)" << endl;
	mipsout << "mult $t0, $t1" << endl;
	mipsout << "mflo $t2" << endl;
	mipsout << "sw $t2, " << resaddr << "($sp)" << endl;
}


/*
DIV	√	√	√	除法
x = a /b ==> DIV a b x
*/
void MipsGenerator::mipsDIV() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	int op1addr = symTab.search(op1name).addr;
	int op2addr = symTab.search(op2name).addr;
	int resaddr = symTab.search(resname).addr;

	mipsout << "lw $t0, " << op1addr << "($sp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($sp)" << endl;
	mipsout << "div $t2, $t0, $t1" << endl;
	mipsout << "mflo $t2" << endl;
	mipsout << "sw $t2, " << resaddr << "($sp)" << endl;
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
	symTab.updateCurFuncAddr(fname);
	mipsout << "jal " << fname << endl;
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
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t0 $" << regNum << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
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
需要判断是全局变量还是局部变量，因为表达式的原因，等式右边一定是临时变量
*/
void MipsGenerator::mipsLVAR() {
	string op1name = curq.op1;
	string resname = curq.res;
	int op1addr = -getOffset(op1name);

	//读取临时变量
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;

	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t0 $" << regNum << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
}


/*
SARY √	√	√	数组元素赋值
array[0] = 1 ==> SARY arrary 0 1
*/
void MipsGenerator::mipsSARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	int op1addr = symTab.search(op1name).addr;
	int op2addr = symTab.search(op2name).addr;
	int resaddr = symTab.search(resname).addr;


}

void MipsGenerator::mipsLARY() {

}

void MipsGenerator::mipsPC() {

}


/*
PI			√	输出整数
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
}

void MipsGenerator::mipsREAD() {

}


/*
RET			√	返回表达式的值
return a; ==> RET a
*/
void MipsGenerator::mipsRET() {
	return;
	string name = curq.res;
	int addr = getOffset(name);
	int fsize = symTab.getCurFunc().value;
	mipsout << "lw $v0, " << addr << "($sp)" << endl;
	mipsout << "lw $ra, 0($sp)" << endl;
	mipsout << "addi $sp, $sp, " << fsize << endl;
	mipsout << "jr $ra" << endl;
}

void MipsGenerator::mipsREN() {

}


/*
BGT√	√	√	大于比较跳转
a > b ==> BGT a b lab
*/
void MipsGenerator::mipsBGT() {

}


/*
BGE √	√	√	大于等于比较跳转
a >= b ==> BGE a b lab
*/
void MipsGenerator::mipsBGE() {

}


/*
BEQ	√	√	√	等于跳转
a==b ==> BEQ a b lab
*/
void MipsGenerator::mipsBEQ() {

}


/*
BLE	√	√	√	小于等于比较跳转
a <= b ==> BLE a b lab
*/
void MipsGenerator::mipsBLE() {

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