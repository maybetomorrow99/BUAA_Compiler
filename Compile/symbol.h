#pragma once
#include "stdafx.h"

typedef enum {
	UNDEFINEKD, CONSTKD, VARKD, PARAKD, ARRAYKD, FUNCKD
} SymbolKind;


typedef enum {
	VOIDTP, INTTP, CHARTP, STRINGTP
} SymbolType;

extern string KindStr[];
extern string TypeStr[];

class SymbolItem {
public:
	SymbolItem(){}
	string name;		//��������
	SymbolKind kind;	//const/ var/ para/ array/ func
	SymbolType type;	//void/ int/ char/ string
	int value;			//������ֵ
	int addr;			//��ַƫ����
	int para;			//��ʾ�����Ĳ������������鳤��
	SymbolItem(string name, SymbolKind kind, SymbolType type, int value, int addr, int para);
};

class SymbolTable {
public:
	SymbolTable() { offset = 0; curFuncAddr = 0; }
	vector<SymbolItem> items;
	int curFuncAddr;				//��ǰ�����ڷ��ű��е�λ��
	vector<int> funcIndex;			//����������
	int offset;

	void insert(string name, SymbolKind kind, SymbolType type, int value);
	bool inTable(string name);
	bool paraInTable(string name);
	bool locInTable(string name);
	SymbolItem search(string name);
	SymbolItem searchFunc(string name);
	int getFuncAddr(string name);
	SymbolItem getCurFunc();
	bool isGlobal(string name);
	bool isConst(string name);
	bool isVar(string name);
	bool isArray(string name);
	bool isPara(string name);
	bool isFunc(string name);
	bool updateFuncPara(string name, int para);
	void updateFuncVal();
	void updateCurFuncAddr(string fname);
	void changeVarType(string name);
	void printTable(string path);

};