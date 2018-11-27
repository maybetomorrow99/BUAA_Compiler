#include "stdafx.h"
#include "symbol.h"
#include "error.h"

SymbolItem::SymbolItem(string name, SymbolKind kind, SymbolType type, 
						int value, int addr, int level, int para) {
	this->name = name;
	this->kind = kind;
	this->type = type;
	this->value = value;
	this->addr = addr;
	this->level = level;
	this->para = para;
}


/*
Insert into into the symbol table
*/
void SymbolTable::insert(string name, SymbolKind kind, SymbolType type, int level, int value) {
	if (kind == CONSTKD) {
		items.push_back(SymbolItem(name, kind, type, value, offset, level, 0));
		offset += 4;
	}
	else if (kind == VARKD || kind == PARAKD) {
		items.push_back(SymbolItem(name, kind, type, value, offset, level, 0));
		offset += 4;
	}
	else if (kind == ARRAYKD) {	//此时value表示数组长度
		items.push_back(SymbolItem(name, kind, type, 0, offset, level, value));
		offset += value * 4;
	}
	else if (kind == FUNCKD) {	//此时value表示参数个数
		offset = 0;
		items.push_back(SymbolItem(name, kind, type, 0, offset, level, value));
		offset += 4;
	} 
	else {
		error(0, 0);
	}
}

bool SymbolTable::isConst(string name) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == name && items[i].kind == CONSTKD) {
			return true;
		}
	}
	return false;
}

bool SymbolTable::isVar(string name) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == name && items[i].kind == VARKD) {
			return true;
		}
	}
	return false;
}

bool SymbolTable::isArray(string name) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == name && items[i].kind == ARRAYKD) {
			return true;
		}
	}
	return false;
}

bool SymbolTable::isPara(string name) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == name && items[i].kind == PARAKD) {
			return true;
		}
	}
	return false;
}

bool SymbolTable::isFunc(string name, SymbolType type) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == name && items[i].kind == FUNCKD && items[i].type == type) {
			return true;
		}
	}
	return false;
}