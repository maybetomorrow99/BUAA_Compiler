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
	int value;			//常量的值
	int addr;			//地址偏移量
	int level;			//表示层级
	int para;			//表示函数的参数个数或数组长度
	SymbolItem(string name, SymbolKind kind, SymbolType type, int value, int addr, int level, int para);
};

class SymbolTable {
public:
	vector<SymbolItem> items;
	bool isFunc(string name, SymbolType type);
	void insert(string name, SymbolKind kind, SymbolType type, int value, int para);

};