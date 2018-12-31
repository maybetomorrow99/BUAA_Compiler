#pragma once
#include "stdafx.h"
#include "parser.h"

class MipsGenerator {
public:
	ofstream mipsout;
	map < string, vector<pair<string, int> > > funcRefCountMap;
	MipsGenerator(string asmPath);

	void referCount();

	bool inReg(string name);

	bool varInReg(string name);

	int getVarReg(string name);

	int getRegNum(string name);

	int getOffset(string name);

	void genMips();
	int mipsGlobal();
	void mipsCON();
	void mipsVAR();
	void mipsARY();
	void mipsFUNC();
	void mipsCal();
	void mipsPARA();
	void mipsCALL();
	void mipsPUSH();
	void mipsVOF();
	void mipsLI();
	void mipsLVAR();
	void mipsSARY();
	void mipsLARY();
	void mipsPC();
	void mipsPI();
	void mipsPRT();
	void mipsREAD();
	void mipsRET();
	void mipsREN();
	void mipsBGT();
	void mipsBGE();
	void mipsBEQ();
	void mipsBLE();
	void mipsBLT();
	void mipsBNE();
	void mipsJUMP();
	void mipsLAB();

	void startWorking();
private:
	Quaternary curq;		//当前四元式
};

class Reg {
public:
	string name;
	int kind;
	bool busy;
};

class RegPool {
	Reg regs[10];
	bool isFull;
};