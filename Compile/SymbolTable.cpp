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
	else if (kind == ARRAYKD) {	//��ʱvalue��ʾ���鳤��
		items.push_back(SymbolItem(name, kind, type, 0, offset, value));
		offset += value * 4;
	}
	else if (kind == FUNCKD) {	//��ʱvalue��ʾ��������
		curFuncAddr = items.size();
		funcIndex.push_back(items.size());
		offset = 0;
		items.push_back(SymbolItem(name, kind, type, 0, offset, value));
		offset += 4;
	} 
	else {
		error(0, 0);
	}
}


/*
���ұ�ʶ���Ƿ����
����λ�ð�����ǰ�㣬ȫ�ֱ������ͺ�����
*/
bool SymbolTable::inTable(string name) {
	for (int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return true;
	}
	if (funcIndex.size()) {
		for (int i = 0; i < funcIndex[0]; i++) {	//ȫ�ֱ���
			if (items[i].name == name)
				return true;
		}
		for (int i = 0; i < funcIndex.size(); i++) {	//����������
			if (items[funcIndex[i]].name == name)
				return true;
		}
	}
	return false;
}


/*
���Ҳ����Ƿ��Ѿ������
����λ��ֻ������ǰ�㣬Ҳ����˵�ֲ��������Ը���ȫ�ֱ����ͺ���
*/
bool SymbolTable::paraInTable(string name) {
	for (int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return true;
	}
	return false;
}


/*
���Ҿֲ������Ƿ����
����λ�ð�����ǰ��͵�ǰ������
Ҳ����˵������������ֲ���ͬ��
*/
bool SymbolTable::locInTable(string name) {
	for (int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return true;
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

SymbolItem SymbolTable::searchFunc(string name) {
	if (isFunc(name)) {
		for (int i = 0; i < funcIndex.size(); i++) {
			if (items[funcIndex[i]].name == name && items[funcIndex[i]].kind == FUNCKD) {
				return items[funcIndex[i]];
			}
		}
	}
}

/*
��ȡ�����ڷ��ű��е�λ��
*/
int SymbolTable::getFuncAddr(string name) {
	for (int i = 0; i < funcIndex.size(); i++) {
		if (items[funcIndex[i]].name == name && items[funcIndex[i]].kind == FUNCKD) {
			return funcIndex[i];
		}
	}
}


/*
��ȡ��ǰ�����ڷ��ű��еı���
*/
SymbolItem SymbolTable::getCurFunc() {
	return items[curFuncAddr];
}


/*
�ж��Ƿ���ȫ�ֱ�����ֻ��������mipsʱ����õ�
*/
bool SymbolTable::isGlobal(string name) {
	for (int i = curFuncAddr + 1; i < items.size(); i++) {	//�ֲ�������ȫ�ֱ�����������Ϊ�ֲ�����
		if (items[i].kind == FUNCKD)					//***������Ԫʽ�Ĺ����У����ű��Ѿ�������ȫ����items.size��鵽����ı���
			break;
		if (items[i].name == name)
			return false;
	}
	if (funcIndex.size()) {
		for (int i = 0; i < funcIndex[0]; i++) {
			if (items[i].name == name)
				return true;
		}
	}
	return false;
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

bool SymbolTable::isFunc(string name) {
	for (int i = 0; i < funcIndex.size(); i++) {
		if (items[funcIndex[i]].name == name && items[funcIndex[i]].kind == FUNCKD) {
			return true;
		}
	}
	return false;
}

/*
���ĺ�������Ĳ�������
*/
bool SymbolTable::updateFuncPara(string name, int para) {
	for (int i = 0; i < funcIndex.size(); i++) {
		if (items[funcIndex[i]].name == name && items[funcIndex[i]].kind == FUNCKD ) {
			items[funcIndex[i]].para = para;
			return true;
		}
	}
	return false;
}


/*
���ĺ��������ֵ����ʾ��������ռ�Ĵ�С
*/
void SymbolTable::updateFuncVal() {
	items[curFuncAddr].value = offset;
}


/*
����curFuncAddrΪ��ǰ�����ڷ��ű��е�λ��
*/
void SymbolTable::updateCurFuncAddr(string fname) {
	curFuncAddr = getFuncAddr(fname);
}


/*
��ʱ����char��������֮��תΪint����factor����expr��
*/
void SymbolTable::changeVarType(string name) {
	for (int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name && items[i].type == CHARTP) {
			items[i].type = INTTP;
			return;
		}
	}
}

void SymbolTable::printTable(string path) {
	ofstream fout;
	fout.open(path);
	fout << "name      kind      type      value     addr      para" << endl;
	for (int i = 0; i < items.size(); i++) {
		SymbolItem item = items[i];
		fout << setw(10) << left << item.name;
		fout << setw(10) << left << KindStr[item.kind];
		fout << setw(10) << left << TypeStr[item.type];
		fout << setw(10) << left << item.value;
		fout << setw(10) << left << item.addr;
		fout << setw(10) << left << item.para << endl;
	}
}