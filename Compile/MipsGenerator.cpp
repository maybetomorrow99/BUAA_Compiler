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
����������
*/
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second > rhs.second;
}


/*
���ü�������ÿ���������������󣬽�������
*/
void MipsGenerator::referCount() {
	string oper;
	string fname;
	vector<string> ref;
	map<string, int> refCountMap;
	bool firstFlag = true;	//��¼�Ƿ��ǵ�һ��FUNC����ʱ���������

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

			//��������
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

	//����
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
���ñ�Ŷ�Ӧ����ʱ�Ĵ���д���ڴ�
*/
void MipsGenerator::writeToMem(int index) {
	
}

/*
�жϸþֲ������Ƿ��ڼĴ�����
Ŀǰ�������е���ʱ���������ڴ��У����ֲ�����/��������������������ǰ8�����ڼĴ����У���Ӧ�Ĵ���t2-t9
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
���ֲ������Ƿ��ڼĴ����У�ͨ��������ü�����֪���
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
��ȡ�ֲ�������Ӧ��ȫ�ּĴ�����ţ���ʱӦ�Ѿ�ȷ�Ͼֲ������ڼĴ�����
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
�����Ĵ�����t2��ʼ
���ֲ�����/������ǰ8������Ĵ�����
��Ϊ�ڷ��ű��к������ռ��һ��λ�ã�����Ҫ��-4
*/
int MipsGenerator::getRegNum(string name) {
	int addr = symTab.search(name).addr;
	int para = symTab.getCurFunc().para;
	return 2 + (addr - 4 - para * 4) / 4;
}


/*
��ȡ���������fp��ƫ�ƣ�ע�����Ҳ�п����ǲ���
TODO:Ŀǰ�ȸ����еı��������ٿռ䣬ֻ������ǰ���ֵı���ʵ���ϴ洢�ڼĴ�����
*/
int MipsGenerator::getOffset(string name) {
	if (symTab.isPara(name))
		return symTab.search(name).addr - 4;	//�˴��ͷ��ű������4����Ϊ�ڷ��ű��к������ռ��һ��λ��
	return symTab.search(name).addr + 32 * 4 - 4;	
}

/*
����һ����ʱ�Ĵ���
*/
int MipsGenerator::applyReg(string name) {
	int index;
	if (regpool.isFull) {
		index = regpool.findLongestReg();
		cout << "find" << index;
		//���üĴ����е�ֵд���ڴ�
		index = regpool.applyReg(name);
		cout << "res" << index << endl;
	}
	else {
		index = regpool.applyReg(name);
	}
	return index;
}



/*
�������֣����ñ���������Ӧ�ļĴ������أ��˴�������ȡֵ�����ص�ÿ���Ĵ���������ֵ��
����У�����$�Ĵ�����
���û���ڼĴ����У����ڴ��н���lw�������ٷ���$�Ĵ���
��������֡���ʱ�������ֲ��������Ĵ����д����ֵ
�����ȫ�ֱ������Ĵ����д����ȫ�ֱ����ĵ�ַ
TODO:�˴��Ȳ���������
*/
string MipsGenerator::getRegWithVal(string name) {
	int index;
	int addr;
	if (IS_NUM(name)) {	//��ʱ����
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
			mipsout << "li " << name << ", $t" << index << endl;
		}
		return "$t" + to_string(index);
	}
	else if (IS_TEMP(name)) {	//��ʱ����
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
			addr = -getOffset(name);
			mipsout << "lw $t" << index << ", " << addr << "($fp)" << endl;
		}
		return "$t" + to_string(index);
	}
	else if (symTab.isGlobal(name)) {	//ȫ�ֱ���
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
			mipsout << "la $t" << index << ", " << name << endl;
			mipsout << "lw $t" << index << ", 0($t" << index << ")" << endl;
		}
		return "$t" + to_string(index);
	}
	else {		//�ֲ�����
		if (varInReg(name)) {			//�з���õļĴ���
			index = getVarRegNum(name);
			return "$s" + to_string(index);
		}
		else {							//���ڼĴ����У��͵ȼ�����ʱ��������
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
�������֣����ñ���������Ӧ�ļĴ������أ��˴����ڴ�ֵ�����ص�ÿ���Ĵ����е�ֵ��Ϊ���������
����У�����$�Ĵ�����
���û���ڼĴ����У�����һ���µļĴ���
�������ʱ�������ֲ��������Ĵ����ж�Ӧ�ľ��Ǳ�����ֵ��ȫ�ֱ���Ҳ��
*/
string MipsGenerator::getReg(string name) {
	int index;
	if (IS_TEMP(name)) {	//��ʱ����
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
		}
		return "$t" + to_string(index);
	}
	else if (symTab.isGlobal(name)) {	//ȫ�ֱ���
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
			mipsout << "la $t" << index << name << endl;
		}
		return "$t" + to_string(index);
	}
	else {		//�ֲ�����
		if (varInReg(name)) {			//�з���õļĴ���
			index = getVarRegNum(name);
			return "$s" + to_string(index);
		}
		else {							//���ڼĴ����У��͵ȼ�����ʱ��������
			if ((index = regpool.searchReg(name)) == -1) {
				index = applyReg(name);
			}
			return "$t" + to_string(index);
		}
	}
}


/*
������Ԫʽ����Mips����
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
ȫ�ֱ������֣������������塢��������
CON	��	��	��	��������
const int a = 6	==> CON int 6 a
VAR	��		��	��һ��������
int a ==> VAR int a
ARY	��	��	��	�����������
int a[100] ==> ARY int 100 a
�ַ�������
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

	//�ַ�������
	for (unsigned int i = 0; i < stringPool.size(); i++) {
		mipsout << "$string" << i << ": .asciiz \"" << stringPool[i] << "\"" << endl;
	}
	mipsout << "$enter: .asciiz \"\\n\"" << endl;

	mipsout << ".text" << endl;
	mipsout << "j main" << endl;
	return index;

}

/*
CON	��	��	��	��������	
const int a = 6	==> CON int 6 a
����ֻ���ڴ���
*/
void MipsGenerator::mipsCON() {
	string cname = curq.res;
	int value = atoi(curq.op2.c_str());
	int addr = -getOffset(cname);;
	mipsout << "li $t"<< applyReg(cname) <<", " << value << endl;
	mipsout << "sw $t0, " << addr << "($fp)" << endl;
}


/*
VAR	��		��	��һ��������
int a ==> VAR int a
*/
void MipsGenerator::mipsVAR() {

}


/*
ARY	��	��	��	�����������
int a[100] ==> ARY int 100 a
*/
void MipsGenerator::mipsARY() {
	
}


/*
FUNC	��		��	��������
int foo ==> FUNC int foo
*/
void MipsGenerator::mipsFUNC() {
	string fname = curq.res;
	int fsize = symTab.searchFunc(fname).value;
	int para = symTab.searchFunc(fname).para;
	symTab.updateCurFuncAddr(fname);
	mipsout << fname << ":" << endl;

	//����ջ�ռ�
	mipsout << "add $fp, $sp, " << para * 4 << endl;
	mipsout << "subi $sp, $sp, " << fsize - para * 4 + 32 * 4 << endl;
	//mipsout << "sw $ra, 0($sp)" << endl;	//TODO:����ra������ת��
}


/*
ADD	��	��	��	�ӷ�
SUB	��	��	��	����
MUL	��	��	��	�˷�
DIV	��	��	��	����
x = a - b ==> ADD a b x
��������Ŀ��������֡���ʱ�������ֲ�������ȫ�ֱ���
*/
void MipsGenerator::mipsCalADDSUB() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	string reg1;
	string reg2;
	string reg3;

	//��ȡa
	if (!IS_NUM(op1name)) {
		reg1 = getRegWithVal(op1name);
	}


	//��ȡb
	if (IS_NUM(op2name)) {
		if (IS_NUM(op1name)) {
			return;
		}
	}
	else {
		reg2 = getRegWithVal(op2name);
	}

	//����x
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

	//ֵĿǰ�ڼĴ����У���ʱ������˴��ȥ
	//��ȡ��ʽ��߲���ֵ
	/*
	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
	*/
}

/*
MUL	��	��	��	�˷�
DIV	��	��	��	����
x = a - b ==> ADD a b x
��������Ŀ��������֡���ʱ�������ֲ�������ȫ�ֱ���
*/
void MipsGenerator::mipsCalMULDIV() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	string reg1;
	string reg2;
	string reg3;


	if (IS_NUM(op2name) && IS_NUM(op1name))	//��������Ϊ�Ѿ������
		return;

	//��ȡa
	reg1 = getRegWithVal(op1name);


	//��ȡb
	reg2 = getRegWithVal(op2name);

	//����x
	reg3 = getReg(resname);

	if (curq.oper == "MUL") {
		mipsout << "mult " << reg1 << ", " << reg2 << endl;
		mipsout << "mflo " << reg3 << endl;
	}
	else {	//curq.oper == "DIV"
		mipsout << "div " << reg1 << ", " << reg2 << endl;
		mipsout << "mflo " << reg3 << endl;
	}


	//ֵĿǰ�ڼĴ����У���ʱ������˴��ȥ
	//��ȡ��ʽ��߲���ֵ
	/*
	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
	*/
}

/*
PARA ��		��	������������
int foo(int a) ==> PARA int a
*/
void MipsGenerator::mipsPARA() {
	
}


/*
CALL		��	��������
x = tar(a, b) ==> CALL tar
*/
void MipsGenerator::mipsCALL() {
	string fname = curq.res;
	//symTab.updateCurFuncAddr(fname);
	int para = symTab.searchFunc(fname).para;

	//��ʱ�����Ѿ�ʹsp��λ���½�
	for (int i = 4; i <= 25; i++) {	//������ʱ�Ĵ�����
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
PUSH			��	��������
x = tar(a, b)  ==> PUSH a
*/
void MipsGenerator::mipsPUSH() {	//TODO:aһ������ʱ����
	string name = curq.res;
	int addr = -getOffset(name);
	
	mipsout << "lw $t0, " << addr << "($fp)" << endl;
	mipsout << "sw $t0, ($sp)" << endl;
	mipsout << "subi $sp, $sp, 4" << endl;
}


/*
VOF	��		��	���ܺ�������ֵ
x = tar(a, b)	VOF tar x
�������Ƹ�ֵ���Ⱥ����Ϊ��ʱ����
*/
void MipsGenerator::mipsVOF() {
	string resname = curq.res;

	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $v0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $" << regNum << ", $v0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $v0, " << resaddr << "($fp)" << endl;
	}
}


/*
LI	��		��	��������ֵ
x = 1 ==> LI 1 x
*/
void MipsGenerator::mipsLI() {
	string value = curq.op1;
	string name = curq.res;
	string reg = getReg(name);

	mipsout << "li " << reg << ", " << value << endl;
}


/*
LVAR ��		��
������ֵ	x = y	LVAR y x
��Ҫ�ж���ȫ�ֱ������Ǿֲ������������߶�Ҫ�ж�
*/
void MipsGenerator::mipsLVAR() {
	string op1name = curq.op1;
	string resname = curq.res;

	//��ȡ��ʽ�ұ�
	if (symTab.isGlobal(op1name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op1name)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(op1name);
		mipsout << "move $t0, $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int op1addr = -getOffset(op1name);
		mipsout << "lw $t0, " << op1addr << "($fp)" << endl;
	}

	//��ȡ��ʽ���
	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum<< ", $t0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}
}


/*
SARY ��	��	��	����Ԫ�ظ�ֵ
array[i] = x ==> SARY array i x
i �� xӦ�ö��Ǿֲ�����
*/
void MipsGenerator::mipsSARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//��ȡi��t0
	if (symTab.isGlobal(op2name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op2name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op2name)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(op2name);
		mipsout << "move $t0, $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t0, " << op2addr << "($fp)" << endl;
	}

	//��t0��Ϊ�������ƫ����
	mipsout << "mul $t0, $t0, 4" << endl;

	//��ȡarray��ַ������ƫ�ƣ����յ�ַΪt0
	if (symTab.isGlobal(op1name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "add $t0, $t0, $t1 " << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����������ֻ������
		int op1addr = -getOffset(op1name);
		mipsout << "addi $t1, $fp, " << op1addr << endl;
		mipsout << "sub $t0, $t1, $t0" << endl;
	}

	//��ȡ��ʽ�ұߵ�ֵ��t0,xֻ��Ϊ�ֲ�����
	if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t1, $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "lw $t1, " << resaddr << "($fp)" << endl;
	}

	//��ֵ
	mipsout << "sw $t1, ($t0)" << endl;
}


/*
LARY	��	��	��
ȡ����Ԫ��	x = array[i]	LARY array i x
x��iӦ��Ϊ�ֲ�����
*/
void MipsGenerator::mipsLARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;

	//��ȡi��t0
	if (symTab.isGlobal(op2name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op2name << endl;
		mipsout << "lw $t0, 0($t1)" << endl;
	}
	else if (inReg(op2name)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(op2name);
		mipsout << "move $t0, $t" << regNum << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����
		int op2addr = -getOffset(op2name);
		mipsout << "lw $t0, " << op2addr << "($fp)" << endl;
	}

	//��t0��Ϊ�������ƫ����
	mipsout << "mul $t0, $t0, 4" << endl;

	//��ȡarray��ַ������ƫ�ƣ����յ�ַΪt0
	if (symTab.isGlobal(op1name)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << op1name << endl;
		mipsout << "add $t0, $t0, $t1 " << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����������ֻ������
		int op1addr = -getOffset(op1name);
		mipsout << "addi $t1, $fp, " << op1addr << endl;
		mipsout << "sub $t0, $t1, $t0" << endl;
	}

	//ȡֵ��t0
	mipsout << "lw $t0, ($t0)" << endl;

	//��ȡ��ʽ��߲���ֵ
	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $t0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $t0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $t0, " << resaddr << "($fp)" << endl;
	}

}


/*
PC			��	����ַ���
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
PI			��	����������ַ�
printf(x)	PI x
xΪ��ʱ����
TODO:x����Ϊ����������˴���Ҫ�޸�
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
PRT	 	��	��	���			
0 ֻ�������� 1 ֻ���ַ��� 2 �ַ���������
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
READ			��	��ȡ�������ַ�
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

	//��ȡ��ʽ���
	if (symTab.isGlobal(resname)) {	//��ȫ�ֱ���
		mipsout << "la $t1, " << resname << endl;
		mipsout << "sw $v0, 0($t1)" << endl;
	}
	else if (inReg(resname)) {		//���ڼĴ����еľֲ�����
		int regNum = getRegNum(resname);
		mipsout << "move $t" << regNum << ", $v0" << endl;
	}
	else {							//���ڼĴ����еľֲ�����
		int resaddr = -getOffset(resname);
		mipsout << "sw $v0, " << resaddr << "($fp)" << endl;
	}
}


/*
RET			��	���ر��ʽ��ֵ
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
REN				���ؿ�
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
BGT��	��	��	���ڱȽ���ת
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
BGE ��	��	��	���ڵ��ڱȽ���ת
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
BEQ	��	��	��	������ת
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
BLE	��	��	��	С�ڵ��ڱȽ���ת
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
BLT ��	��	��	С�ڱȽ���ת
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
BNE	��	��	��	��������ת
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
JUMP			��	��������ת
JUMP Lable1
*/
void MipsGenerator::mipsJUMP() {
	mipsout << "j " << curq.res << endl;
}


/*
LAB			��	���ñ�ǩ
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