#pragma once
#include "parser.h"
#include "reg.h"

class MipsGenerator {
public:
	ofstream mipsout;
	map < string, vector<pair<string, int> > > funcRefCountMap;
	RegPool regpool;

	MipsGenerator(string asmPath);

	void referCount();


	bool inReg(string name);

	bool varInReg(string name);

	int getVarRegNum(string name);

	string getReg(string name);

	int getRegNum(string name);

	int getOffset(string name);

	int applyReg(string name);

	string getRegWithVal(string name);

	void reg2Mem(int index);

	void clearRegs(int option);

	void recovery();

	void genMips();
	int mipsGlobal();
	void mipsCON();
	void mipsVAR();
	void mipsARY();
	void mipsFUNC();
	void mipsCalADDSUB();
	void mipsCalMULDIV();
	void mipsPARA();
	void mipsCALL();
	void mipsPUSH();
	void mipsVOF();
	void mipsLI();
	void mipsLVAR();
	void mipsSARY();
	void mipsLARY();
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
