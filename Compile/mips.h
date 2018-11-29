#pragma once
#include "stdafx.h"
#include "parser.h"

class MipsGenerator {
public:
	ofstream mipsout;
	MipsGenerator(string asmPath);

	void genMips();
	int mipsGlobal();
	void mipsCON();
	void mipsVAR();
	void mipsARY();
	void mipsFUNC();
	void mipsADD();
	void mipsSUB();
	void mipsMUL();
	void mipsDIV();
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
	void mipsREAD();
	void mipsRET();
	void mipsREN();
	void mipsBGTZ();
	void mipsBGEZ();
	void mipsBEQ();
	void mipsBLEZ();
	void mipsBLTZ();
	void mipsBNE();
	void mipsJUMP();
	void mipsLAB();

	void startWorking();
private:
	Quaternary curq;		//当前四元式
};