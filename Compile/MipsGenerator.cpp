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
		else {
			mipsout << curq.res << ": .word 0: " << curq.op2 << endl;
		}
		curq = quaterList[++index];
	}

	//字符串常量
	for (int i = 0; i < stringPool.size(); i++) {
		mipsout << "$string" << i << ": .asciiz \"" << stringPool[i] << "\"" << endl;
	}
	return index;
}

/*
CON	√	√	√	常量定义	
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
	symTab.curFuncAddr = symTab.getFuncAddr(fname);
	mipsout << fname << ":" << endl;

	//分配栈空间
	mipsout << "subi $sp, $sp, " << fsize << endl;
	mipsout << "sw $ra, 0($sp)" << endl;	//TODO:保存ra是用跳转？
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
	mipsout << "jal " << curq.res << endl;
}


/*
PUSH			√	函数传参
x = tar(a, b)  ==> PUSH a
*/
void MipsGenerator::mipsPUSH() {	//先进栈再出栈，x应该不会是全局变量
	
}

void MipsGenerator::mipsVOF() {

}


/*
LI	√		√	立即数赋值
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
LVAR √		√
变量赋值	x = y	LVAR y x
需要判断是全局变量还是局部变量
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

void MipsGenerator::mipsPI() {

}

void MipsGenerator::mipsREAD() {

}


/*
RET			√	返回表达式的值
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
BGTZ√	√	√	大于比较跳转
a > b ==> BGTZ a b lab
*/
void MipsGenerator::mipsBGTZ() {

}


/*
BGEZ √	√	√	大于等于比较跳转
a >= b ==> BGEZ a b lab
*/
void MipsGenerator::mipsBGEZ() {

}


/*
BEQ	√	√	√	等于跳转
a==b ==> BEQ a b lab
*/
void MipsGenerator::mipsBEQ() {

}


/*
BLEZ	√	√	√	小于等于比较跳转
a <= b ==> BLEZ a b lab
*/
void MipsGenerator::mipsBLEZ() {

}


/*
BLTZ √	√	√	小于比较跳转
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