#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <iomanip>

#define TABLESIZE 512

using namespace std;

typedef enum {
	UNDEFINEKD, CONSTKD, VARKD, PARAKD, ARRAYKD, FUNCKD
}SymbolKind;


typedef enum {
	VOIDTP, INTTP, CHARTP, STRINGTP
} SymbolType;



class SymbolItem {
public:
	string name;
	SymbolKind kind;	//var array
	SymbolType type;	//int char
	int value;			
	int para;
	SymbolItem(string name, SymbolKind kind, SymbolType type, int value, int para);
};

class SymbolTable {
public:
	vector<SymbolItem> items;
	bool isFunc(string name, SymbolType type);
	void insert(string name, SymbolKind kind, SymbolType type, int value, int para);

};