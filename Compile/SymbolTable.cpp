#include "stdafx.h"
#include "symbol.h"
#include "error.h"



string KindStr[] = {
	"undefine", "const", "var", "para", "array", "func"
};


string TypeStr[] = {
	"void", "int ", "char", "string"
};

SymbolItem::SymbolItem(string name, SymbolKind kind, SymbolType type, 
						int value, int addr, int para) {
	this->name = name;
	this->kind = kind;
	this->type = type;
	this->value = value;
	this->addr = addr;
	this->para = para;
}


/*
Insert into into the symbol table
*/
void SymbolTable::insert(string name, SymbolKind kind, SymbolType type, int value) {
	if (kind == CONSTKD) {
		items.push_back(SymbolItem(name, kind, type, value, offset, 0));
		offset += 4;
	}
	else if (kind == VARKD || kind == PARAKD) {
		items.push_back(SymbolItem(name, kind, type, value, offset, 0));
		offset += 4;
	}
	else if (kind == ARRAYKD) {	//此时value表示数组长度
		items.push_back(SymbolItem(name, kind, type, 0, offset, value));
		offset += value * 4;
	}
	else if (kind == FUNCKD) {	//此时value表示参数个数
		funcIndex.push_back(items.size());
		offset = 0;
		items.push_back(SymbolItem(name, kind, type, 0, offset, value));
		offset += 4;
	} 
	else {
		error(0, 0);
	}
}

bool SymbolTable::inTable(string name) {
	for (int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return true;
	}
	if (funcIndex.size()) {
		for (int i = 0; i < funcIndex[0]; i++) {
			if (items[i].name == name)
				return true;
		}
	}
	return false;
}

SymbolItem SymbolTable::search(string name) {
	for (int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return items[i];
	}
	if (funcIndex.size()) {
		for (int i = 0; i < funcIndex[0]; i++) {
			if (items[i].name == name)
				return items[i];
		}
	}
}

bool SymbolTable::isConst(string name) {
	if (inTable(name)) {
		SymbolItem item = search(name);
		if (item.kind == CONSTKD)
			return true;
	}
	return false;
}

bool SymbolTable::isVar(string name) {
	if (inTable(name)) {
		SymbolItem item = search(name);
		if (item.kind == VARKD)
			return true;
	}
	return false;
}

bool SymbolTable::isArray(string name) {
	if (inTable(name)) {
		SymbolItem item = search(name);
		if (item.kind == ARRAYKD)
			return true;
	}
	return false;
}

bool SymbolTable::isPara(string name) {
	if (inTable(name)) {
		SymbolItem item = search(name);
		if (item.kind == PARAKD)
			return true;
	}
	return false;
}

bool SymbolTable::isFunc(string name, SymbolType type) {
	for (int i = 0; i < funcIndex.size(); i++) {
		if (items[funcIndex[i]].name == name && items[funcIndex[i]].kind == FUNCKD && items[funcIndex[i]].type == type) {
			return true;
		}
	}
	return false;
}

void SymbolTable::printTable() {
	cout << "name      kind      type      value     addr      para" << endl;
	for (int i = 0; i < items.size(); i++) {
		SymbolItem item = items[i];
		cout << setw(10) << left << item.name;
		cout << setw(10) << left << KindStr[item.kind];
		cout << setw(10) << left << TypeStr[item.type];
		cout << setw(10) << left << item.value;
		cout << setw(10) << left << item.addr;
		cout << setw(10) << left << item.para << endl;
	}
}