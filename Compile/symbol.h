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
	int curFuncAddr;
	vector<int> funcIndex;			//����������
	int offset;

	void insert(string name, SymbolKind kind, SymbolType type, int value);
	bool inTable(string name);
	SymbolItem search(string name);
	bool isConst(string name);
	bool isVar(string name);
	bool isArray(string name);
	bool isPara(string name);
	bool isFunc(string name, SymbolType type);
	bool updateFuncPara(string name, int para);
	void printTable();

};