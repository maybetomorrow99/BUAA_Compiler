#pragma once
#include "stdafx.h"

#define TABLESIZE 512

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
	vector<SymbolItem> items;
	bool isFunc(string name, SymbolType type);
	void insert(string name, SymbolKind kind, SymbolType type, int value, int para);

};