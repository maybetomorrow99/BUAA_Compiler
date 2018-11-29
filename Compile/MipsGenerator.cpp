#include "mips.h"

MipsGenerator::MipsGenerator(string asmPath) {
	mipsout.open(asmPath);
}


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

	}
	else if (curq.oper == "READ") {

	}
	else if (curq.oper == "RET") {
		mipsRET();
	}
	else if (curq.oper == "REN") {

	}
	else if (curq.oper == "BGTZ") {

	}
	else if (curq.oper == "BGEZ") {

	}
	else if (curq.oper == "BEQ") {

	}
	else if (curq.oper == "BLEZ") {

	}
	else if (curq.oper == "BLTZ") {
		mipsBLTZ();
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
		else {
			mipsout << curq.res << ": .word 0: " << curq.op2 << endl;
		}
		curq = quaterList[++index];
	}

	//�ַ�������
	for (int i = 0; i < stringPool.size(); i++) {
		mipsout << "$string" << i << ": .asciiz \"" << stringPool[i] << "\"" << endl;
	}
	return index;
}

/*
CON	��	��	��	��������	
const int a = 6	==> CON int 6 a
*/
void MipsGenerator::mipsCON() {
	string cname = curq.res;
	int value = atoi(curq.op2.c_str());
	int addr = symTab.search(cname).addr;
	
	mipsout << "li $t0, " << value << endl;
	mipsout << "sw $t0, " << addr << "($sp)" << endl;
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
	symTab.curFuncAddr = symTab.getFuncAddr(fname);
	mipsout << fname << ":" << endl;

	//����ջ�ռ�
	mipsout << "subi $sp, $sp, " << fsize << endl;
	mipsout << "sw $ra, 0($sp)" << endl;	//TODO:����ra������ת��
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
	mipsout << "jal " << curq.res << endl;
}


/*
PUSH			��	��������
x = tar(a, b)  ==> PUSH a
*/
void MipsGenerator::mipsPUSH() {	//�Ƚ�ջ�ٳ�ջ��xӦ�ò�����ȫ�ֱ���
	
}

void MipsGenerator::mipsVOF() {

}


/*
LI	��		��	��������ֵ
x = 1 ==> LI 1 x
*/
void MipsGenerator::mipsLI() {
	string value = curq.op1;
	string name = curq.res;
	int addr = symTab.search(name).addr;
	
	mipsout << "li $t0, " << value << endl;
	mipsout << "sw $t0, " << addr << "($sp)" << endl;
}


/*
LVAR ��		��
������ֵ	x = y	LVAR y x
��Ҫ�ж���ȫ�ֱ������Ǿֲ�����
*/
void MipsGenerator::mipsLVAR() {
	string op1name = curq.op1;
	string resname = curq.res;
	int op1addr = symTab.search(op1name).addr;
	int resaddr = symTab.search(resname).addr;

	if (symTab.isGlobal(resname)) {
		mipsout << "lw $t0, " << op1addr << "($sp)" << endl;
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else {
		mipsout << "lw $t0, " << op1addr << "($sp)" << endl;
		mipsout << "sw $t0, " << resaddr << "($sp)" << endl;
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

void MipsGenerator::mipsPI() {

}

void MipsGenerator::mipsREAD() {

}


/*
RET			��	���ر��ʽ��ֵ
return a; ==> RET a
*/
void MipsGenerator::mipsRET() {
	string name = curq.res;
	int addr = symTab.search(name).addr;
	int fsize = symTab.getCurFunc().value;
	mipsout << "lw $v0, " << addr << "($sp)" << endl;
	mipsout << "lw $ra, 0($sp)" << endl;
	mipsout << "addi $sp, $sp, " << fsize << endl;
	mipsout << "jr $ra" << endl;

}

void MipsGenerator::mipsREN() {

}


/*
BGTZ��	��	��	���ڱȽ���ת
a > b ==> BGTZ a b lab
*/
void MipsGenerator::mipsBGTZ() {

}


/*
BGEZ ��	��	��	���ڵ��ڱȽ���ת
a >= b ==> BGEZ a b lab
*/
void MipsGenerator::mipsBGEZ() {

}


/*
BEQ	��	��	��	������ת
a==b ==> BEQ a b lab
*/
void MipsGenerator::mipsBEQ() {

}


/*
BLEZ	��	��	��	С�ڵ��ڱȽ���ת
a <= b ==> BLEZ a b lab
*/
void MipsGenerator::mipsBLEZ() {

}


/*
BLTZ ��	��	��	С�ڱȽ���ת
a < b ==> BLTZ a b lab
*/
void MipsGenerator::mipsBLTZ() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = symTab.search(op1name).addr;
	int op2addr = symTab.search(op2name).addr;
	mipsout << "lw $t0, " << op1addr << "($sp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($sp)" << endl;
	mipsout << "bltz $t0, $t1, " << label << endl;
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