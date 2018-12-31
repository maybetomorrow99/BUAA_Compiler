#include "mips.h"
#include "dag.h"
#define IS_VAR(name) ((name[0] >= 'a' && name[0] <= 'z') || name[0] == '_')
#define IS_NUM(name) (name[0] >= '0' && name[0] <= '9')
#define IS_TEMP(name) (name[0] == '$')

typedef pair<string, int> PAIR;

MipsGenerator::MipsGenerator(string asmPath) {
	mipsout.open(asmPath);
}


/*
降序排列用
*/
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second > rhs.second;
}


/*
引用计数，在每个函数计数结束后，进行排序
*/
void MipsGenerator::referCount() {
	string oper;
	string fname;
	vector<string> ref;
	map<string, int> refCountMap;
	bool firstFlag = true;	//记录是否是第一个FUNC，此时不插入表中

	for (unsigned int i = 0; i < quaterList.size(); i++) {
		ref.clear();
		oper = quaterList[i].oper;
		if (oper == "FUNC") {
			if (firstFlag) {
				fname = quaterList[i].res;
				symTab.updateCurFuncAddr(fname);
				firstFlag = false;
				continue;
			}

			//排序后加入
			//cout << fname;
			vector<PAIR> refCountVec(refCountMap.begin(), refCountMap.end());
			sort(refCountVec.begin(), refCountVec.end(), cmp_by_value);
			/*for (unsigned int j = 0; j < refCountVec.size(); j++) {
				cout << refCountVec[j].first << " : " << refCountVec[j].second << endl;
			}*/
			refCountMap.clear();
			funcRefCountMap[fname] = refCountVec;

			fname = quaterList[i].res;
			symTab.updateCurFuncAddr(fname);
		}
		// 1 2 res
		else if (oper == "ADD" || oper == "SUB" || oper == "MUL" || oper == "DIV") {
			ref.push_back(quaterList[i].op1);
			ref.push_back(quaterList[i].op2);
			ref.push_back(quaterList[i].res);
		}
		// 1   res
		else if (oper == "LVAR") {
			ref.push_back(quaterList[i].op1);
			ref.push_back(quaterList[i].res);
		}
		//   2 res
		else if (oper == "SARY" || oper == "LARY") {
			ref.push_back(quaterList[i].op2);
			ref.push_back(quaterList[i].res);
		}
		// 1 2
		else if (oper == "BGT" || oper == "BGE" || oper == "BEQ"
			|| oper == "BLE" || oper == "BLT" || oper == "BNE") {
			ref.push_back(quaterList[i].op1);
			ref.push_back(quaterList[i].op2);
		}
		//    res
		else if (oper == "PUSH" || oper == "VOF" || oper == "LI" 
			|| oper == "PRT" || oper == "READ" || oper == "RET") {
			ref.push_back(quaterList[i].res);
		}
		
		for (unsigned int j = 0; j < ref.size(); j++) {
			if (IS_VAR(ref[j])) {
				int kind = symTab.search(ref[j]).kind;
				if (kind != ARRAYKD && kind != CONSTKD)
					refCountMap[ref[j]] += 1;
			}
		}
	}

	//排序
	vector<PAIR> refCountVec(refCountMap.begin(), refCountMap.end());
	sort(refCountVec.begin(), refCountVec.end(), cmp_by_value);
	funcRefCountMap[fname] = refCountVec;

	for (map < string, vector<PAIR> >::iterator it = funcRefCountMap.begin(); it != funcRefCountMap.end(); it++) {
		cout << "===== "<< it->first << " =====" << endl;
		refCountVec = it->second;
		for (unsigned int i = 0; i < refCountVec.size(); ++i) {
			cout << refCountVec[i].first << " : " << refCountVec[i].second << endl;
		}
	}
}


/*
将该编号对应的临时寄存器写回内存
*/
void MipsGenerator::writeToMem(int index) {
	
}

/*
判断该局部变量是否在寄存器中
目前，将所有的临时变量放在内存中，将局部变量/常量（不包括参数）的前8个放在寄存器中，对应寄存器t2-t9
*/
bool MipsGenerator::inReg(string name) {
	if (name[0] == '$')
		return false;
	int addr = symTab.search(name).addr;
	int para = symTab.getCurFunc().para;
	SymbolKind kind = symTab.search(name).kind;
	if ((kind == VARKD || kind == CONSTKD) && addr < para * 4 + 8 * 4) {
		return true;
	}
	return false;
}



/*
检测局部变量是否在寄存器中，通过检查引用计数得知结果
*/
bool MipsGenerator::varInReg(string name) {
	vector<PAIR> refCountVec;
	refCountVec = funcRefCountMap[name];
	if (refCountVec.size() <= 8)
		return true;
	else {
		for (unsigned int i = 0; i < refCountVec.size(); ++i) {
			if (refCountVec[i].first == name)
				return true;
			//cout << refCountVec[i].first << ":" << refCountVec[i].second << endl;
		}
	}
	return false;
}


/*
获取局部变量对应的全局寄存器编号，此时应已经确认局部变量在寄存器中
*/
int MipsGenerator::getVarRegNum(string name) {
	vector<PAIR> refCountVec;
	refCountVec = funcRefCountMap[symTab.getCurFunc().name];
	for (unsigned int i = 0; i < refCountVec.size(); ++i) {
		if (refCountVec[i].first == name) {
			return i;
		}
	}
	return 0;
}


/*
变量寄存器从t2开始
将局部变量/常量的前8个放入寄存器中
因为在符号表中函数表项还占有一个位置，所以要先-4
*/
int MipsGenerator::getRegNum(string name) {
	int addr = symTab.search(name).addr;
	int para = symTab.getCurFunc().para;
	return 2 + (addr - 4 - para * 4) / 4;
}


/*
获取变量相对于fp的偏移，注意变量也有可能是参数
TODO:目前先给所有的变量都开辟空间，只不过靠前部分的变量实际上存储在寄存器中
*/
int MipsGenerator::getOffset(string name) {
	if (symTab.isPara(name))
		return symTab.search(name).addr - 4;	//此处和符号表中相差4，因为在符号表中函数表项还占有一个位置
	return symTab.search(name).addr + 32 * 4 - 4;	
}

/*
申请一个临时寄存器
*/
int MipsGenerator::applyReg(string name) {
	int index;
	if (regpool.isFull) {
		index = regpool.findLongestReg();
		cout << "find" << index;
		//将该寄存器中的值写回内存
		index = regpool.applyReg(name);
		cout << "res" << index << endl;
	}
	else {
		index = regpool.applyReg(name);
	}
	return index;
}



/*
传入名字，将该变量名所对应的寄存器返回，此处用于提取值，返回的每个寄存器都是有值的
如果有，返回$寄存器，
如果没有在寄存器中，从内存中将其lw出来，再返回$寄存器
如果是数字、临时变量、局部变量，寄存器中存的是值
如果是全局变量，寄存器中存的是全局变量的地址
TODO:此处先不考虑数组
*/
string MipsGenerator::getRegWithVal(string name) {
	int index;
	int addr;
	if (IS_NUM(name)) {	//临时数字
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
			mipsout << "li " << name << ", $t" << index << endl;
		}
		return "$t" + to_string(index);
	}
	else if (IS_TEMP(name)) {	//临时变量
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
			addr = -getOffset(name);
			mipsout << "lw $t" << index << ", " << addr << "($fp)" << endl;
		}
		return "$t" + to_string(index);
	}
	else if (symTab.isGlobal(name)) {	//全局变量
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
			mipsout << "la $t" << index << ", " << name << endl;
			mipsout << "lw $t" << index << ", 0($t" << index << ")" << endl;
		}
		return "$t" + to_string(index);
	}
	else {		//局部变量
		if (varInReg(name)) {			//有分配好的寄存器
			index = getVarRegNum(name);
			return "$s" + to_string(index);
		}
		else {							//不在寄存器中，就等价于临时变量处理
			if ((index = regpool.searchReg(name)) == -1) {
				index = applyReg(name);
				addr = -getOffset(name);
				mipsout << "lw $t" << index << ", " << addr << "($fp)" << endl;
			}
			return "$t" + to_string(index);
		}
	}
}


/*
传入名字，将该变量名所对应的寄存器返回，此处用于存值，返回的每个寄存器中的值认为是无意义的
如果有，返回$寄存器，
如果没有在寄存器中，申请一个新的寄存器
如果是临时变量、局部变量，寄存器中对应的就是变量的值，全局变量也是
*/
string MipsGenerator::getReg(string name) {
	int index;
	if (IS_TEMP(name)) {	//临时变量
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
		}
		return "$t" + to_string(index);
	}
	else if (symTab.isGlobal(name)) {	//全局变量
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
			mipsout << "la $t" << index << name << endl;
		}
		return "$t" + to_string(index);
	}
	else {		//局部变量
		if (varInReg(name)) {			//有分配好的寄存器
			index = getVarRegNum(name);
			return "$s" + to_string(index);
		}
		else {							//不在寄存器中，就等价于临时变量处理
			if ((index = regpool.searchReg(name)) == -1) {
				index = applyReg(name);
			}
			return "$t" + to_string(index);
		}
	}
}


/*
根据四元式生成Mips代码
*/
void MipsGenerator::genMips() {
	mipsout << "# " << curq.toString() << endl;
	if (curq.oper == "CON") {
		mipsCON();
	}
	else if (curq.oper == "VAR") {
		mipsVAR();
	}
	else if (curq.oper == "ARY") {
		mipsARY();
	}
	else if (curq.oper == "FUNC") {
		mipsFUNC();
	}
	else if (curq.oper == "ADD" || curq.oper == "SUB") {
		mipsCalADDSUB();
	}
	else if (curq.oper == "MUL" || curq.oper == "DIV") {
		mipsCalMULDIV();
	}
	else if (curq.oper == "PARA") {
		mipsPARA();
	}
	else if (curq.oper == "CALL") {
		mipsCALL();
	}
	else if (curq.oper == "PUSH") {
		mipsPUSH();
	}
	else if (curq.oper == "VOF") {
		mipsVOF();
	}
	else if (curq.oper == "LI") {
		mipsLI();
	}
	else if (curq.oper == "LVAR") {
		mipsLVAR();
	}
	else if (curq.oper == "SARY") {
		mipsSARY();
	}
	else if (curq.oper == "LARY") {
		mipsLARY();
	}
	else if (curq.oper == "PRT") {
		mipsPRT();
	}
	else if (curq.oper == "READ") {
		mipsREAD();
	}
	else if (curq.oper == "RET") {
		mipsRET();
	}
	else if (curq.oper == "REN") {
		mipsREN();
	}
	else if (curq.oper == "BGT") {
		mipsBGT();
	}
	else if (curq.oper == "BGE") {
		mipsBGE();
	}
	else if (curq.oper == "BEQ") {
		mipsBEQ();
	}
	else if (curq.oper == "BLE") {
		mipsBLE();
	}
	else if (curq.oper == "BLT") {
		mipsBLT();
	}
	else if (curq.oper == "BNE") {
		mipsBNE();
	}
	else if (curq.oper == "JUMP") {
		mipsJUMP();
	}
	else if (curq.oper == "LAB") {
		mipsLAB();
	}
}


/*
全局变量部分，包括常量定义、变量定义
CON	√	√	√	常量定义
const int a = 6	==> CON int 6 a
VAR	√		√	单一变量声明
int a ==> VAR int a
ARY	√	√	√	数组变量声明
int a[100] ==> ARY int 100 a
字符串常量
*/
int MipsGenerator::mipsGlobal() {
	int index = 0;
	mipsout << ".data" << endl;
	curq = quaterList[0];
	while (curq.oper != "FUNC") {
		if (curq.oper == "CON") {
			mipsout << curq.res << ": .word " << curq.op2 << endl;
		}
		else if (curq.oper == "VAR") {
			mipsout << curq.res << ": .space 4" << endl;
		}
		else {	//curq.oper == "ARY"
			mipsout << curq.res << ": .word 0: " << curq.op2 << endl;
		}
		curq = quaterList[++index];
	}

	//字符串常量
	for (unsigned int i = 0; i < stringPool.size(); i++) {
		mipsout << "$string" << i << ": .asciiz \"" << stringPool[i] << "\"" << endl;
	}
	mipsout << "$enter: .asciiz \"\\n\"" << endl;

	mipsout << ".text" << endl;
	mipsout << "j main" << endl;
	return index;

}

/*
CON	√	√	√	常量定义	
const int a = 6	==> CON int 6 a
常量只在内存中
*/
void MipsGenerator::mipsCON() {
	string cname = curq.res;
	int value = atoi(curq.op2.c_str());
	int addr = -getOffset(cname);;
	mipsout << "li $t"<< applyReg(cname) <<", " << value << endl;
	mipsout << "sw $t0, " << addr << "($fp)" << endl;
}


/*
VAR	√		√	单一变量声明
int a ==> VAR int a
*/
void MipsGenerator::mipsVAR() {

}


/*
ARY	√	√	√	数组变量声明
int a[100] ==> ARY int 100 a
*/
void MipsGenerator::mipsARY() {
	
}


/*
FUNC	√		√	函数声明
int foo ==> FUNC int foo
*/
void MipsGenerator::mipsFUNC() {
	string fname = curq.res;
	int fsize = symTab.searchFunc(fname).value;
	int para = symTab.searchFunc(fname).para;
	symTab.updateCurFuncAddr(fname);
	mipsout << fname << ":" << endl;

	//分配栈空间
	mipsout << "add $fp, $sp, " << para * 4 << endl;
	mipsout << "subi $sp, $sp, " << fsize - para * 4 + 32 * 4 << endl;
	//mipsout << "sw $ra, 0($sp)" << endl;	//TODO:保存ra是用跳转？
}


/*
ADD	√	√	√	加法
SUB	√	√	√	减法
MUL	√	√	√	乘法
DIV	√	√	√	除法
x = a - b ==> ADD a b x
参与运算的可能有数字、临时变量、局部变量、全局变量
*/
void MipsGenerator::mipsCalADDSUB() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	string reg1;
	string reg2;
	string reg3;

	//读取a
	if (!IS_NUM(op1name)) {
		reg1 = getRegWithVal(op1name);
	}


	//读取b
	if (IS_NUM(op2name)) {
		if (IS_NUM(op1name)) {
			return;
		}
	}
	else {
		reg2 = getRegWithVal(op2name);
	}

	//计算x
	reg3 = getReg(resname);

	if (curq.oper == "ADD") {
		if (IS_NUM(op1name)) {
			mipsout << "add " << reg3 << ", " << reg2 << ", " << op1name << endl;
		}
		else if (IS_NUM(op2name)) {
			mipsout << "add " << reg3 << ", " << reg1 << ", " << op2name << endl;
		}
		else {
			mipsout << "add " << reg3 << ", " << reg1 << ", " << reg2 << endl;
		}
	}
	else if (curq.oper == "SUB") {
		if (IS_NUM(op1name)) {
			mipsout << "sub " << reg3 << ", " << reg2 << ", " << op1name << endl;
		}
		else if (IS_NUM(op2name)) {
			mipsout << "sub " << reg3 << ", " << reg1 << ", " << op2name << endl;
		}
		else {
			mipsout << "sub " << reg3 << ", " << reg1 << ", " << reg2 << endl;
		}
	}

	//值目前在寄存器中，到时候会有人存回去
	//读取等式左边并赋值
	/*
	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
	*/
}

/*
MUL	√	√	√	乘法
DIV	√	√	√	除法
x = a - b ==> ADD a b x
参与运算的可能有数字、临时变量、局部变量、全局变量
*/
void MipsGenerator::mipsCalMULDIV() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	string reg1;
	string reg2;
	string reg3;


	if (IS_NUM(op2name) && IS_NUM(op1name))	//返回是因为已经算过了
		return;

	//读取a
	reg1 = getRegWithVal(op1name);


	//读取b
	reg2 = getRegWithVal(op2name);

	//计算x
	reg3 = getReg(resname);

	if (curq.oper == "MUL") {
		mipsout << "mult " << reg1 << ", " << reg2 << endl;
		mipsout << "mflo " << reg3 << endl;
	}
	else {	//curq.oper == "DIV"
		mipsout << "div " << reg1 << ", " << reg2 << endl;
		mipsout << "mflo " << reg3 << endl;
	}


	//值目前在寄存器中，到时候会有人存回去
	//读取等式左边并赋值
	/*
	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
	*/
}

/*
PARA √		√	函数参数定义
int foo(int a) ==> PARA int a
*/
void MipsGenerator::mipsPARA() {
	
}


/*
CALL		√	函数调用
x = tar(a, b) ==> CALL tar
*/
void MipsGenerator::mipsCALL() {
	string fname = curq.res;
	//symTab.updateCurFuncAddr(fname);
	int para = symTab.searchFunc(fname).para;

	//此时参数已经使sp的位置下降
	for (int i = 4; i <= 25; i++) {	//保存临时寄存器等
		mipsout << "sw $" << i << ", " << -i * 4 << "($sp)" << endl;
	}
	mipsout << "sw $fp ," << -30 * 4 << "($sp)" << endl;
	mipsout << "sw $ra ," << -31 * 4 << "($sp)" << endl;

	mipsout << "jal " << fname << endl;

	for (int i = 4; i <=25 ; i++) {
		mipsout << "lw $" << i << ", " << -para * 4 - i * 4 << "($sp)" << endl;
	}
	mipsout << "lw $fp ," << -para * 4 - 30 * 4 << "($sp)" << endl;
	mipsout << "lw $ra ," << -para * 4 - 31 * 4 << "($sp)" << endl;
}


/*
PUSH			√	函数传参
x = tar(a, b)  ==> PUSH a
*/
void MipsGenerator::mipsPUSH() {	//TODO:a一定是临时变量
	string name = curq.res;
	int addr = -getOffset(name);
	
	mipsout << "lw $t0, " << addr << "($fp)" << endl;
	mipsout << "sw $t0, ($sp)" << endl;
	mipsout << "subi $sp, $sp, 4" << endl;
}


/*
VOF	√		√	接受函数返回值
x = tar(a, b)	VOF tar x
操作类似赋值，等号左边为临时变量
*/
void MipsGenerator::mipsVOF() {
	string resname = curq.res;

	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $v0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $" << regNum << ", $v0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $v0, " << resaddr << "($fp)" << endl;
	}
}


/*
LI	√		√	立即数赋值
x = 1 ==> LI 1 x
*/
void MipsGenerator::mipsLI() {
	string value = curq.op1;
	string name = curq.res;
	string reg = getReg(name);

	mipsout << "li " << reg << ", " << value << endl;
}


/*
LVAR √		√
变量赋值	x = y	LVAR y x
需要判断是全局变量还是局部变量，对两边都要判断
*/
void MipsGenerator::mipsLVAR() {
	string op1name = curq.op1;
	string resname = curq.res;

	//读取等式右边
	if (symTab.isGlobal(op1name)) {	//是全局变量
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op1name)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(op1name);
		mipsout << "move $t0, $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int op1addr = -getOffset(op1name);
		mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	}

	//读取等式左边
	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum<< ", $t0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
}


/*
SARY √	√	√	数组元素赋值
array[i] = x ==> SARY array i x
i 和 x应该都是局部变量
*/
void MipsGenerator::mipsSARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//读取i到t0
	if (symTab.isGlobal(op2name)) {	//是全局变量
		mipsout << "la $t1, " << op2name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op2name)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(op2name);
		mipsout << "move $t0, $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t0, " << op2addr << "($fp)" << endl;
	}

	//将t0改为相对数组偏移量
	mipsout << "mul $t0, $t0, 4" << endl;

	//读取array地址并加上偏移，最终地址为t0
	if (symTab.isGlobal(op1name)) {	//是全局变量
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "add $t0, $t0, $t1 " << endl;
	}
	else {							//是不在寄存器中的局部变量，数组只能这样
		int op1addr = -getOffset(op1name);
		mipsout << "addi $t1, $fp, " << op1addr << endl;
		mipsout << "sub $t0, $t1, $t0" << endl;
	}

	//读取等式右边的值到t0,x只能为局部变量
	if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t1, $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "lw $t1, " << resaddr << "($fp)" << endl;
	}

	//赋值
	mipsout << "sw $t1, ($t0)" << endl;
}


/*
LARY	√	√	√
取数组元素	x = array[i]	LARY array i x
x和i应该为局部变量
*/
void MipsGenerator::mipsLARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//读取i到t0
	if (symTab.isGlobal(op2name)) {	//是全局变量
		mipsout << "la $t1, " << op2name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op2name)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(op2name);
		mipsout << "move $t0, $t" << regNum << endl;
	}
	else {							//是不在寄存器中的局部变量
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t0, " << op2addr << "($fp)" << endl;
	}

	//将t0改为相对数组偏移量
	mipsout << "mul $t0, $t0, 4" << endl;

	//读取array地址并加上偏移，最终地址为t0
	if (symTab.isGlobal(op1name)) {	//是全局变量
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "add $t0, $t0, $t1 " << endl;
	}
	else {							//是不在寄存器中的局部变量，数组只能这样
		int op1addr = -getOffset(op1name);
		mipsout << "addi $t1, $fp, " << op1addr << endl;
		mipsout << "sub $t0, $t1, $t0" << endl;
	}

	//取值到t0
	mipsout << "lw $t0, ($t0)" << endl;

	//读取等式左边并赋值
	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}

}


/*
PC			√	输出字符串
printf("hello")	PC 1
*/
void MipsGenerator::mipsPC() {
	mipsout << "li $v0, 4" << endl;
	mipsout << "la $a0, $string" << curq.res << endl;
	mipsout << "syscall" << endl;

	mipsout << "li $v0, 4" << endl;
	mipsout << "la $a0," << "$enter" << endl;
	mipsout << "syscall" << endl;
}


/*
PI			√	输出整数或字符
printf(x)	PI x
x为临时变量
TODO:x可能为任意变量，此处需要修改
*/
void MipsGenerator::mipsPI() {
	string name = curq.res;
	int addr = -getOffset(name);
	SymbolType type = symTab.search(name).type;
	
	if (type == INTTP)
		mipsout << "li $v0, 1" << endl;
	else
		mipsout << "li $v0, 11" << endl;

	mipsout << "lw $a0, " << addr << "($fp)" << endl;
	mipsout << "syscall" << endl;
	
	mipsout << "li $v0, 4" << endl;
	mipsout << "la $a0," << "$enter" << endl;
	mipsout << "syscall" << endl;
}


/*
PRT	 	√	√	输出			
0 只有整数， 1 只有字符串 2 字符串和整数
*/
void MipsGenerator::mipsPRT() {
	if (curq.op1 == "0") {
		string name = curq.res;
		int addr = -getOffset(name);
		SymbolType type = symTab.search(name).type;

		if (type == INTTP)
			mipsout << "li $v0, 1" << endl;
		else
			mipsout << "li $v0, 11" << endl;

		mipsout << "lw $a0, " << addr << "($fp)" << endl;
		mipsout << "syscall" << endl;

		mipsout << "li $v0, 4" << endl;
		mipsout << "la $a0," << "$enter" << endl;
		mipsout << "syscall" << endl;
	}
	else if (curq.op1 == "1") {
		mipsout << "li $v0, 4" << endl;
		mipsout << "la $a0, $string" << curq.res << endl;
		mipsout << "syscall" << endl;

		mipsout << "li $v0, 4" << endl;
		mipsout << "la $a0," << "$enter" << endl;
		mipsout << "syscall" << endl;
	}
	else {
		mipsout << "li $v0, 4" << endl;
		mipsout << "la $a0, $string" << curq.op2 << endl;
		mipsout << "syscall" << endl;

		string name = curq.res;
		int addr = -getOffset(name);
		SymbolType type = symTab.search(name).type;

		if (type == INTTP)
			mipsout << "li $v0, 1" << endl;
		else
			mipsout << "li $v0, 11" << endl;

		mipsout << "lw $a0, " << addr << "($fp)" << endl;
		mipsout << "syscall" << endl;

		mipsout << "li $v0, 4" << endl;
		mipsout << "la $a0," << "$enter" << endl;
		mipsout << "syscall" << endl;
	}
}


/*
READ			√	读取整数或字符
scanf(a)	RI a
*/
void MipsGenerator::mipsREAD() {
	string resname = curq.res;
	SymbolType type = symTab.search(resname).type;
	
	if (type == INTTP)
		mipsout << "li $v0, 5" << endl;
	else
		mipsout << "li $v0, 12" << endl;
	mipsout << "syscall" << endl;

	//读取等式左边
	if (symTab.isGlobal(resname)) {	//是全局变量
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $v0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//是在寄存器中的局部变量
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $v0" << endl;
	}
	else {							//不在寄存器中的局部变量
		int resaddr = -getOffset(resname);
		mipsout << "sw $v0, " << resaddr << "($fp)" << endl;
	}
}


/*
RET			√	返回表达式的值
return a; ==> RET a
*/
void MipsGenerator::mipsRET() {
	string name = curq.res;
	int addr = -getOffset(name);
	int fsize = symTab.getCurFunc().value;
	int para = symTab.getCurFunc().para;
	mipsout << "lw $v0, " << addr << "($fp)" << endl;
	mipsout << "addi $sp, $sp, " << fsize + 32 * 4 << endl;
	mipsout << "jr $ra" << endl;
}


/*
REN				返回空
return;	REN
*/
void MipsGenerator::mipsREN() {
	//cout << symTab.getCurFunc().name << endl;
	if (symTab.getCurFunc().name == "main") {
		mipsout << "li $v0," << 10 << endl;
		mipsout << "syscall" << endl;
		return;
	}
	int fsize = symTab.getCurFunc().value;
	int para = symTab.getCurFunc().para;
	mipsout << "addi $sp, $sp, " << fsize + 32 * 4 << endl;
	mipsout << "jr $ra" << endl;
}


/*
BGT√	√	√	大于比较跳转
a > b ==> BGT a b lab
*/
void MipsGenerator::mipsBGT() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "bgt $t0, $t1, " << label << endl;
}


/*
BGE √	√	√	大于等于比较跳转
a >= b ==> BGE a b lab
*/
void MipsGenerator::mipsBGE() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "bge $t0, $t1, " << label << endl;
}


/*
BEQ	√	√	√	等于跳转
a==b ==> BEQ a b lab
*/
void MipsGenerator::mipsBEQ() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "beq $t0, $t1, " << label << endl;
}


/*
BLE	√	√	√	小于等于比较跳转
a <= b ==> BLE a b lab
*/
void MipsGenerator::mipsBLE() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "ble $t0, $t1, " << label << endl;
}


/*
BLT √	√	√	小于比较跳转
a < b ==> BLT a b lab
*/
void MipsGenerator::mipsBLT() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "blt $t0, $t1, " << label << endl;
}


/*
BNE	√	√	√	不等于跳转
a != b ==> BNE a b lab
*/
void MipsGenerator::mipsBNE() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	int op1addr = -getOffset(op1name);
	int op2addr = -getOffset(op2name);
	mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	mipsout << "lw $t1, " << op2addr << "($fp)" << endl;
	mipsout << "bne $t0, $t1, " << label << endl;
}


/*
JUMP			√	无条件跳转
JUMP Lable1
*/
void MipsGenerator::mipsJUMP() {
	mipsout << "j " << curq.res << endl;
}


/*
LAB			√	设置标签
LAB Lable1
*/
void MipsGenerator::mipsLAB() {
	mipsout << curq.res << ":" << endl;
}



void MipsGenerator::startWorking() {
	int glbIndex;
	glbIndex = mipsGlobal();
	for (unsigned int i = glbIndex; i < quaterList.size(); i++) {
		curq = quaterList[i];
		genMips();
	}
}