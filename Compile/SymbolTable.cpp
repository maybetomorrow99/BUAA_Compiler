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
查找标识符是否存在
查找位置包括当前层，全局变量区和函数区
*/
bool SymbolTable::inTable(string name) {
	for (unsigned int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return true;
	}
	if (funcIndex.size()) {
		for (int i = 0; i < funcIndex[0]; i++) {	//全局变量
			if (items[i].name == name)
				return true;
		}
		for (unsigned int i = 0; i < funcIndex.size(); i++) {	//函数索引表
			if (items[funcIndex[i]].name == name)
				return true;
		}
	}
	return false;
}


/*
查找参数是否被定义过，检查重定义
查找位置只包括当前层，也就是说局部变量可以覆盖全局变量和函数
*/
bool SymbolTable::paraInTable(string name) {
	for (unsigned int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return true;
	}
	return false;
}


/*
查找局部变量是否被定义过，检查重定义
查找位置包括当前层和当前函数名
也就是说不允许函数名与局部量同名
*/
bool SymbolTable::locInTable(string name) {
	for (unsigned int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return true;
	}
	return false;
}


/*
查找函数名字是否被定义过，检查重定义
查找位置包括全局层和函数区
*/
bool SymbolTable::funcDefInTable(string name) {
	if (funcIndex.size()) {
		for (int i = 0; i < funcIndex[0]; i++) {	//全局变量
			if (items[i].name == name)
				return true;
		}
		for (unsigned int i = 0; i < funcIndex.size(); i++) {	//函数索引表
			if (items[funcIndex[i]].name == name)
				return true;
		}
	}
	return false;
}



/*
查找函数是否定义过，检查未定义
查找位置包括函数区
*/
bool SymbolTable::funcInTable(string name) {
	if (funcIndex.size()) {
		for (unsigned int i = 0; i < funcIndex.size(); i++) {	//函数索引表
			if (items[funcIndex[i]].name == name)
				return true;
		}
	}
	return false;
}

/*
查找变量是否定义过，检查未定义
查找位置包括局部区和全局区
*/
bool SymbolTable::varInTable(string name) {
	for (unsigned int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return true;
	}
	if (funcIndex.size()) {
		for (int i = 0; i < funcIndex[0]; i++) {	//全局变量
			if (items[i].name == name)
				return true;
		}
	}
	return false;
}

/*
查找变量，返回表项
*/
SymbolItem SymbolTable::search(string name) {
	for (unsigned int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			return items[i];
	}
	if (funcIndex.size()) {
		for (int i = 0; i < funcIndex[0]; i++) {
			if (items[i].name == name)
				return items[i];
		}
	}
	cout << name << " Symbol Not Found" << endl;
	return SymbolItem("$notfound", UNDEFINEKD, VOIDTP, 0, 0, 0);
}


SymbolItem SymbolTable::searchFunc(string name) {
	if (isFunc(name)) {
		for (unsigned int i = 0; i < funcIndex.size(); i++) {
			if (items[funcIndex[i]].name == name && items[funcIndex[i]].kind == FUNCKD) {
				return items[funcIndex[i]];
			}
		}
	}

	cout << "Symbol Not Found" << endl;
	return SymbolItem("$notfound", UNDEFINEKD, VOIDTP, 0, 0, 0);
}

/*
获取函数在符号表中的位置
*/
int SymbolTable::getFuncAddr(string name) {
	for (unsigned int i = 0; i < funcIndex.size(); i++) {
		if (items[funcIndex[i]].name == name && items[funcIndex[i]].kind == FUNCKD) {
			return funcIndex[i];
		}
	}

	cout << name << "Func Symbol Not Found" << endl;
	return 0;
}


/*
获取当前函数在符号表中的表项
*/
SymbolItem SymbolTable::getCurFunc() {
	return items[curFuncAddr];
}


/*
获取函数指定下标的参数，用于判断参数类型是否一致
*/
SymbolItem SymbolTable::getPara(string fname, int index) {
	int funcAddr = getFuncAddr(fname);
	return items[funcAddr + index];
}


/*
判断是否是全局变量，只有在生成mips时候会用到
*/
bool SymbolTable::isGlobal(string name) {
	for (unsigned int i = curFuncAddr + 1; i < items.size(); i++) {	//局部变量和全局变量重名，则为局部变量
		if (items[i].kind == FUNCKD)					//***生成四元式的过程中，符号表已经建立完全，用items.size会查到后面的变量
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
	for (unsigned int i = 0; i < funcIndex.size(); i++) {
		if (items[funcIndex[i]].name == name && items[funcIndex[i]].kind == FUNCKD) {
			return true;
		}
	}
	return false;
}

/*
更改函数表项的参数个数
*/
bool SymbolTable::updateFuncPara(string name, int para) {
	for (unsigned int i = 0; i < funcIndex.size(); i++) {
		if (items[funcIndex[i]].name == name && items[funcIndex[i]].kind == FUNCKD ) {
			items[funcIndex[i]].para = para;
			return true;
		}
	}
	return false;
}


/*
更改函数表项的值，表示函数所需空间的大小
*/
void SymbolTable::updateFuncVal() {
	items[curFuncAddr].value = offset;
}


/*
更新curFuncAddr为当前函数在符号表中的位置
*/
void SymbolTable::updateCurFuncAddr(string fname) {
	curFuncAddr = getFuncAddr(fname);
}


/*
更新变量的value，表示局部变量的引用次数，此处不包含对数组的引用
*/
void SymbolTable::updateVarPara(string name) {
	for (unsigned int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name && items[i].kind == VARKD)
			items[i].para++;
	}
}

/*
临时变量char参与运算之后转为int，在factor级和expr级
*/
void SymbolTable::changeVarType(string name) {
	for (unsigned int i = curFuncAddr; i < items.size(); i++) {
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
	for (unsigned int i = 0; i < items.size(); i++) {
		SymbolItem item = items[i];
		fout << setw(10) << left << item.name;
		fout << setw(10) << left << KindStr[item.kind];
		fout << setw(10) << left << TypeStr[item.type];
		fout << setw(10) << left << item.value;
		fout << setw(10) << left << item.addr;
		fout << setw(10) << left << item.para << endl;
	}
}


/*
设置swithc中表达式变量的para为1，表示是一个特殊的临时变量
*/
void SymbolTable::setupSwitchPara(string name) {
	for (unsigned int i = curFuncAddr; i < items.size(); i++) {
		if (items[i].name == name)
			items[i].para = 1;
	}
}


void SymbolTable::clear() {
	items.clear();
	curFuncAddr = 0;				//当前函数在符号表中的位置
	funcIndex.clear();			//函数索引表，记录函数在符号表中的位置
	offset = 0;
}