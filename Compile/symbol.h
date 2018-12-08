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
	string name;		//表项名字
	SymbolKind kind;	//const/ var/ para/ array/ func
	SymbolType type;	//void/ int/ char/ string
	int value;			//常量的值
	int addr;			//地址偏移量
	int para;			//表示函数的参数个数或数组长度
	SymbolItem(string name, SymbolKind kind, SymbolType type, int value, int addr, int para);
};

class SymbolTable {
public:
	SymbolTable() { offset = 0; curFuncAddr = 0; }
	vector<SymbolItem> items;
	int curFuncAddr;				//当前函数在符号表中的位置
	vector<int> funcIndex;			//函数索引表
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