#include "mips.h"

MipsGenerator::MipsGenerator(string asmPath) {
	mipsout.open(asmPath);
}

/*
�жϸþֲ������Ƿ��ڼĴ�����
Ŀǰ�������е���ʱ���������ڴ��У����ֲ�������ǰ8�����ڼĴ����У���Ӧ�Ĵ���t2-t9
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
*/
int MipsGenerator::getRegNum(string name) {
	int addr = symTab.search(name).addr;
	int para = symTab.getCurFunc().para;
	return 2 + (addr - para * 4) / 4;
}


/*
��ȡ���������fp��ƫ��
TODO:Ŀǰ�ȸ����еı��������ٿռ䣬ֻ������ǰ���ֵı���ʵ���ϴ洢�ڼĴ�����
*/
int MipsGenerator::getOffset(string name) {
	return symTab.search(name).addr + 32 * 4;
}


/*
������Ԫʽ����Mips����
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

	mipsout << ".text" << endl;

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
	symTab.updateCurFuncAddr(fname);
	mipsout << fname << ":" << endl;

	//����ջ�ռ�
	mipsout << "subi $sp, $sp, " << fsize + 32 * 4 << endl;
	//mipsout << "sw $ra, 0($sp)" << endl;	//TODO:����ra������ת��
}


/*
ADD	��	��	��	�ӷ�
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
SUB	��	��	��	����
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
MUL	��	��	��	�˷�
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
DIV	��	��	��	����
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
	symTab.updateCurFuncAddr(fname);
	mipsout << "jal " << fname << endl;
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
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t0 $" << regNum << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
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
��Ҫ�ж���ȫ�ֱ������Ǿֲ���������Ϊ���ʽ��ԭ�򣬵�ʽ�ұ�һ������ʱ����
*/
void MipsGenerator::mipsLVAR() {
	string op1name = curq.op1;
	string resname = curq.res;
	int op1addr = -getOffset(op1name);

	//��ȡ��ʱ����
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;

	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t0 $" << regNum << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
}


/*
SARY ��	��	��	����Ԫ�ظ�ֵ
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
PI			��	�������
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
}

void MipsGenerator::mipsREAD() {

}


/*
RET			��	���ر��ʽ��ֵ
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
BGT��	��	��	���ڱȽ���ת
a > b ==> BGT a b lab
*/
void MipsGenerator::mipsBGT() {

}


/*
BGE ��	��	��	���ڵ��ڱȽ���ת
a >= b ==> BGE a b lab
*/
void MipsGenerator::mipsBGE() {

}


/*
BEQ	��	��	��	������ת
a==b ==> BEQ a b lab
*/
void MipsGenerator::mipsBEQ() {

}


/*
BLE	��	��	��	С�ڵ��ڱȽ���ת
a <= b ==> BLE a b lab
*/
void MipsGenerator::mipsBLE() {

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