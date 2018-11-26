#include "symbol.h"

SymbolItem::SymbolItem(string name, SymbolKind kind, SymbolType type, int value, int para) {
	this->name = name;
	this->kind = kind;
	this->type = type;
	this->value = para;
	this->para = para;

}


bool SymbolTable::isFunc(string name, SymbolType type) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == name && items[i].kind == FUNCKD && items[i].type == type) {
			return true;
		}
	}
	return false;
}

void SymbolTable::insert(string name, SymbolKind kind, SymbolType type, int value, int para) {
	SymbolItem item = SymbolItem(name, kind, type, 0, 0);
	items.push_back(item);
}