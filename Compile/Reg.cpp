#include "reg.h"
#define IS_NUM(name) ((name[0] >= '0' && name[0] <= '9') || name[0] == '-')
#define IS_TEMP(name) (name[0] == '$')

/*
清空$t0-$t9
*/
void RegPool::clearRegs() {
	for (int i = 0; i < capacity; i++) {
		regs[i].name = "";
		regs[i].kind = 0;
		regs[i].busy = false;
	}
	isFull = false;
}


/*
申请临时寄存器，有空寄存器的话返回临时寄存器编号，否则返回-1
*/
int RegPool::applyReg(string name) {
	for (int i = 0; i < capacity; i++) {
		if (!regs[i].busy) {
			regs[i].name = name;
			regs[i].kind = getKind(name);
			regs[i].busy = true;

			time = (time + 1) % 10;

			if (i == 9)
				isFull = true;
			return i;
		}
	}
	isFull = true;
	return -1;
}


/*
根据FIFO寻找最早被分配的寄存器，并弹出，此处用time
*/
int RegPool::findLongestReg() {
	int index = time;
	regs[index].busy = false;
	return index;
}


/*
获取该名称对应的类型，返回类型
0-数字， 1-临时变量， 2-局部变量， 3-全局变量
*/
int RegPool::getKind(string name) {
	if (IS_NUM(name)) {
		return 0;
	}
	else if (IS_TEMP(name)) {
		return 1;
	}
	else if (symTab.isGlobal(name)) {
		return 3;
	}
	else {	//局部变量
		return 2;
	}
}


/*
查询变量在不在寄存器池中
*/
int RegPool::searchReg(string name) {
	for (int i = 0; i < capacity; i++) {
		if (regs[i].busy && regs[i].name == name) {
			return i;
		}
	}
	return -1;
}