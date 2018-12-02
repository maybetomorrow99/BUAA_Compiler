#include "mips.h"

MipsGenerator::MipsGenerator(string asmPath) {
	mipsout.open(asmPath);
}

/*
�жϸþֲ������Ƿ��ڼĴ�����
Ŀǰ�������е���ʱ���������ڴ��У����ֲ�����/��������������������ǰ8�����ڼĴ����У���Ӧ�Ĵ���t2-t9
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
�����Ĵ�����t2��ʼ
���ֲ�����/������ǰ8������Ĵ�����
��Ϊ�ڷ��ű��к������ռ��һ��λ�ã�����Ҫ��-4
*/
int MipsGenerator::getRegNum(string name) {
	int addr = symTab.search(name).addr;
	int para = symTab.getCurFunc().para;
	return 2 + (addr - 4 - para * 4) / 4;
}


/*
��ȡ���������fp��ƫ�ƣ�ע�����Ҳ�п����ǲ���
TODO:Ŀǰ�ȸ����еı��������ٿռ䣬ֻ������ǰ���ֵı���ʵ���ϴ洢�ڼĴ�����
*/
int MipsGenerator::getOffset(string name) {
	if (symTab.isPara(name))
		return symTab.search(name).addr - 4;	//�˴��ͷ��ű������4����Ϊ�ڷ��ű��к������ռ��һ��λ��
	return symTab.search(name).addr + 32 * 4 - 4;	
}


/*
������Ԫʽ����Mips����
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
ȫ�ֱ������֣������������塢��������
CON	��	��	��	��������
const int a = 6	==> CON int 6 a
VAR	��		��	��һ��������
int a ==> VAR int a
ARY	��	��	��	�����������
int a[100] ==> ARY int 100 a
�ַ�������
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

	//�ַ�������
	for (int i = 0; i < stringPool.size(); i++) {
		mipsout << "$string" << i << ": .asciiz \"" << stringPool[i] << "\"" << endl;
	}
	mipsout << "$enter: .asciiz \"\\n\"" << endl;

	mipsout << ".text" << endl;
	mipsout << "j main" << endl;
	return index;

}

/*
CON	��	��	��	��������	
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
VAR	��		��	��һ��������
int a ==> VAR int a
*/
void MipsGenerator::mipsVAR() {

}


/*
ARY	��	��	��	�����������
int a[100] ==> ARY int 100 a
*/
void MipsGenerator::mipsARY() {
	
}


/*
FUNC	��		��	��������
int foo ==> FUNC int foo
*/
void MipsGenerator::mipsFUNC() {
	string fname = curq.res;
	int fsize = symTab.searchFunc(fname).value;
	int para = symTab.searchFunc(fname).para;
	symTab.updateCurFuncAddr(fname);
	mipsout << fname << ":" << endl;

	//����ջ�ռ�
	mipsout << "add $fp, $sp, " << para * 4 << endl;
	mipsout << "subi $sp, $sp, " << fsize - para * 4 + 32 * 4 << endl;
	//mipsout << "sw $ra, 0($sp)" << endl;	//TODO:����ra������ת��
}


/*
ADD	��	��	��	�ӷ�
SUB	��	��	��	����
MUL	��	��	��	�˷�
DIV	��	��	��	����
x = a - b ==> ADD a b x
����sub�����Ӧ�ö�����ʱ����
*/
void MipsGenerator::mipsCal() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//��ȡa
	if (inReg(op1name)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(op1name);
		mipsout << "move $t0 $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int op1addr = -getOffset(op1name);
		mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	}

	//��ȡb
	if (inReg(op2name)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(op2name);
		mipsout << "move $t1 $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	}

	//����x
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

	//��ȡ��ʽ��߲���ֵ
	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
}


/*
PARA ��		��	������������
int foo(int a) ==> PARA int a
*/
void MipsGenerator::mipsPARA() {
	
}


/*
CALL		��	��������
x = tar(a, b) ==> CALL tar
*/
void MipsGenerator::mipsCALL() {
	string fname = curq.res;
	//symTab.updateCurFuncAddr(fname);
	int para = symTab.searchFunc(fname).para;

	//��ʱ�����Ѿ�ʹsp��λ���½�
	for (int i = 8; i <= 25; i++) {	//������ʱ�Ĵ�����
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
PUSH			��	��������
x = tar(a, b)  ==> PUSH a
*/
void MipsGenerator::mipsPUSH() {	//TODO:aһ������ʱ����
	string name = curq.res;
	int addr = -getOffset(name);
	
	mipsout << "lw $t0, " << addr << "($fp)" << endl;
	mipsout << "sw $t0, ($sp)" << endl;
	mipsout << "subi $sp, $sp, 4" << endl;
}


/*
VOF	��		��	���ܺ�������ֵ
x = tar(a, b)	VOF tar x
�������Ƹ�ֵ���Ⱥ����Ϊ��ʱ����
*/
void MipsGenerator::mipsVOF() {
	string resname = curq.res;

	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $v0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $" << regNum << ", $v0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $v0, " << resaddr << "($fp)" << endl;
	}
}


/*
LI	��		��	��������ֵ
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
LVAR ��		��
������ֵ	x = y	LVAR y x
��Ҫ�ж���ȫ�ֱ������Ǿֲ������������߶�Ҫ�ж�
*/
void MipsGenerator::mipsLVAR() {
	string op1name = curq.op1;
	string resname = curq.res;

	//��ȡ��ʽ�ұ�
	if (symTab.isGlobal(op1name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op1name)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(op1name);
		mipsout << "move $t0 $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int op1addr = -getOffset(op1name);
		mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	}

	//��ȡ��ʽ���
	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum<< ", $t0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
}


/*
SARY ��	��	��	����Ԫ�ظ�ֵ
array[i] = x ==> SARY arrary i x
i �� xӦ�ö��Ǿֲ�����
*/
void MipsGenerator::mipsSARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//��ȡi��t0
	if (symTab.isGlobal(op2name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op2name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op2name)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(op2name);
		mipsout << "move $t0 $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t0, " << op2addr << "($fp)" << endl;
	}

	//��t0��Ϊ�������ƫ����
	mipsout << "mul $t0, $t0, 4" << endl;

	//��ȡarray��ַ������ƫ�ƣ����յ�ַΪt0
	if (symTab.isGlobal(op1name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "add $t0, $t0, $t1 " << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����������ֻ������
		int op1addr = -getOffset(op1name);
		mipsout << "addi $t1, $fp, " << op1addr << endl;
		mipsout << "sub $t0, $t1, $t0" << endl;
	}

	//��ȡ��ʽ�ұߵ�ֵ��t0,xֻ��Ϊ�ֲ�����
	if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t1 $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "lw $t1, " << resaddr << "($fp)" << endl;
	}

	//��ֵ
	mipsout << "sw $t1, ($t0)" << endl;
}


/*
LARY	��	��	��
ȡ����Ԫ��	x = array[i]	LARY array i x
x��iӦ��Ϊ�ֲ�����
*/
void MipsGenerator::mipsLARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//��ȡi��t0
	if (symTab.isGlobal(op2name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op2name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op2name)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(op2name);
		mipsout << "move $t0 $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t0, " << op2addr << "($fp)" << endl;
	}

	//��t0��Ϊ�������ƫ����
	mipsout << "mul $t0, $t0, 4" << endl;

	//��ȡarray��ַ������ƫ�ƣ����յ�ַΪt0
	if (symTab.isGlobal(op1name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "add $t0, $t0, $t1 " << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����������ֻ������
		int op1addr = -getOffset(op1name);
		mipsout << "addi $t1, $fp, " << op1addr << endl;
		mipsout << "sub $t0, $t1, $t0" << endl;
	}

	//ȡֵ��t0
	mipsout << "lw $t0, ($t0)" << endl;

	//��ȡ��ʽ��߲���ֵ
	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}

}


/*
PC			��	����ַ���
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
PI			��	����������ַ�
printf(x)	PI x
xΪ��ʱ����
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
READ			��	��ȡ�������ַ�
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

	//��ȡ��ʽ���
	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $v0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $v0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $v0, " << resaddr << "($fp)" << endl;
	}
}


/*
RET			��	���ر��ʽ��ֵ
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
REN				���ؿ�
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
BGT��	��	��	���ڱȽ���ת
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
BGE ��	��	��	���ڵ��ڱȽ���ת
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
BEQ	��	��	��	������ת
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
BLE	��	��	��	С�ڵ��ڱȽ���ת
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
BLT ��	��	��	С�ڱȽ���ת
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
BNE	��	��	��	��������ת
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
JUMP			��	��������ת
JUMP Lable1
*/
void MipsGenerator::mipsJUMP() {
	mipsout << "j " << curq.res << endl;
}


/*
LAB			��	���ñ�ǩ
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