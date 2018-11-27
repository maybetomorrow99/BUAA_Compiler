#pragma once
#include "stdafx.h"

typedef enum {
	UNDEFINEKD, CONSTKD, VARKD, PARAKD, ARRAYKD, FUNCKD
} SymbolKind;


typedef enum {
	VOIDTP, INTTP, CHARTP, STRINGTP
} SymbolType;



class SymbolItem {
public:
	string name;		
	SymbolKind kind;	//const/ var/ para/ array/ func
	SymbolType type;	//void/ int/ char/ string
	int value;			//������ֵ
	int addr;			//��ַƫ����
	int level;			//��ʾ�㼶
	int para;			//��ʾ�����Ĳ������������鳤��
	SymbolItem(string name, SymbolKind kind, SymbolType type, int value, int addr, int level, int para);
};

class SymbolTable {
public:
	SymbolTable() { offset = 0; }
	vector<SymbolItem> items;
	int offset;

	void insert(string name, SymbolKind kind, SymbolType type, int level, int value);
	bool isConst(string name);
	bool isVar(string name);
	bool isArray(string name);
	bool isPara(string name);
	bool isFunc(string name, SymbolType type);

};