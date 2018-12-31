#pragma once
#include "global.h"

class Reg {
public:
	string name;
	int kind;	//0-���֣� 1-��ʱ������ 2-�ֲ������� 3-ȫ�ֱ���
	bool busy;
};


class RegPool {
public:
	RegPool() { capacity = 10;  isFull = false; time = 0; }
	Reg regs[10];
	int capacity;
	bool isFull;
	int time;	//����FIFO��ת�Ĵ���, time����ȡģ%10

	void clearRegs();
	int applyReg(string name);
	int findLongestReg();
	int getKind(string name);
	int searchReg(string name);
};