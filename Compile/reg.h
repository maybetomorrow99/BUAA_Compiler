#pragma once
#include "global.h"

class Reg {
public:
	string name;
	int kind;	//0-数字， 1-临时变量， 2-局部变量， 3-全局变量
	bool busy;
};


class RegPool {
public:
	RegPool() { capacity = 10;  isFull = false; time = 0; }
	Reg regs[10];
	int capacity;
	bool isFull;
	int time;	//采用FIFO轮转寄存器, time用于取模%10

	void clearRegs();
	int applyReg(string name);
	int findLongestReg();
	int getKind(string name);
	int searchReg(string name);
};