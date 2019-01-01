#include "reg.h"
#define IS_NUM(name) ((name[0] >= '0' && name[0] <= '9') || name[0] == '-')
#define IS_TEMP(name) (name[0] == '$')

/*
���$t0-$t9
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
������ʱ�Ĵ������пռĴ����Ļ�������ʱ�Ĵ�����ţ����򷵻�-1
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
����FIFOѰ�����类����ļĴ��������������˴���time
*/
int RegPool::findLongestReg() {
	int index = time;
	regs[index].busy = false;
	return index;
}


/*
��ȡ�����ƶ�Ӧ�����ͣ���������
0-���֣� 1-��ʱ������ 2-�ֲ������� 3-ȫ�ֱ���
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
	else {	//�ֲ�����
		return 2;
	}
}


/*
��ѯ�����ڲ��ڼĴ�������
*/
int RegPool::searchReg(string name) {
	for (int i = 0; i < capacity; i++) {
		if (regs[i].busy && regs[i].name == name) {
			return i;
		}
	}
	return -1;
}