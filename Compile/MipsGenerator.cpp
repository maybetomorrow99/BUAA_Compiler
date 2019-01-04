#include "mips.h"
#include "dag.h"
#define IS_VAR(name) ((name[0] >= 'a' && name[0] <= 'z') || name[0] == '_')
#define IS_NUM(name) ((name[0] >= '0' && name[0] <= '9') || name[0] == '-')
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
			if (IS_VAR(ref[j]) && !symTab.isGlobal(ref[j])) {
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

	/*for (map < string, vector<PAIR> >::iterator it = funcRefCountMap.begin(); it != funcRefCountMap.end(); it++) {
		cout << "===== "<< it->first << " =====" << endl;
		refCountVec = it->second;
		for (unsigned int i = 0; i < refCountVec.size(); ++i) {
			cout << refCountVec[i].first << " : " << refCountVec[i].second << endl;
		}
	}*/
}


/*
���ֲ������Ƿ��ڼĴ����У�ͨ��������ü�����֪���
*/
bool MipsGenerator::varInReg(string name) {
	if (symTab.isConst(name)) {
		return false;
	}

	vector<PAIR> refCountVec;
	refCountVec = funcRefCountMap[symTab.getCurFunc().name];
	if (refCountVec.size() <= 8)
		return true;
	else {
		for (int i = 0; i < 8; ++i) {
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
	return -1;
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
		//���üĴ����е�ֵд���ڴ�
		reg2Mem(index);
		index = regpool.applyReg(name);
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
	string arrayAddrReg;
	if (IS_NUM(name)) {	//��ʱ����
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
			mipsout << "li $t" << index << ", "<< name << endl;
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
			mipsout << "la $a3, " << name << endl;
			mipsout << "lw $t" << index << ", 0($a3)" << endl;
			//arrayAddrReg = getReg("000");
			//mipsout << "la " << arrayAddrReg << ", " << name << endl;
			//mipsout << "lw $t" << index << ", 0(" << arrayAddrReg << ")" << endl;
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
�������ʱ�������ֲ��������Ĵ����ж�Ӧ�ľ��Ǳ�����ֵ��ȫ�ֱ���Ҳ�ǣ����ֻ��Ϊ���и���Ӧ
*/
string MipsGenerator::getReg(string name) {
	int index;
	if (IS_NUM(name)) {			//�˴���ʵ�����ֵ��������������һ���ԼĴ���
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
		}
		return "$t" + to_string(index);
	}
	else if (IS_TEMP(name)) {	//��ʱ����
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
		}
		return "$t" + to_string(index);
	}
	else if (symTab.isGlobal(name)) {	//ȫ�ֱ���
		if ((index = regpool.searchReg(name)) == -1) {
			index = applyReg(name);
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
���Ĵ����е�����д�뵽�ڴ浱��
int kind;	//0-���֣� 1-��ʱ������ 2-�ֲ������� 3-ȫ�ֱ���
*/
void MipsGenerator::reg2Mem(int index) {
	Reg reg = regpool.regs[index];
	int addr;
	string arrayAddrReg;
	if (reg.kind == 1) {
		addr = -getOffset(reg.name);
		mipsout << "sw $t" << index << ", " << addr << "($fp)" << endl;
	}
	else if (reg.kind == 2) {
		addr = -getOffset(reg.name);
		mipsout << "sw $t" << index << ", " << addr << "($fp)" << endl;
	}
	else if(reg.kind == 3){
		mipsout << "la $a3, " << reg.name << endl;
		mipsout << "sw $t" << index << ", 0($a3)" << endl;
		//arrayAddrReg = getReg("000");
		//mipsout << "la " << arrayAddrReg << ", " << reg.name << endl;
		//mipsout << "sw $t" << index << ", 0(" << arrayAddrReg << ")" << endl;
	}
}

/*
��ռĴ���
option = 0�� ��� $8-$25�Ĵ���, �������ڴ棬�ں���������ʼʱʹ��
option = 1, ��� $8-$25�Ĵ���, ����Ӧ���ݴ����ڴ���, �ڵ�����������֮ǰʹ��
option = 2, ��� $8-$25�Ĵ���, ��ȫ�ֱ��������ڴ�,���಻���룬��������ʱʹ��
option = 3, ��� $t0-$t9��ʱ�����Ĵ���������ȫ�ּĴ���(�����ڿ��ʹ��)��
			��t�Ĵ����еľֲ�������ȫ�ֱ�������switch����������д���ڴ�
*/
void MipsGenerator::clearRegs(int option) {
	string fname = symTab.getCurFunc().name;
	string name;
	int addr;
	unsigned int maxVarNum;
	if (option == 0) {

	}
	else if (option == 1) {
		//�������ü�����
		vector<PAIR> refCountVec;
		refCountVec = funcRefCountMap[symTab.getCurFunc().name];
		maxVarNum = ((refCountVec.size() < 8)) ? refCountVec.size() : 8;
		for (unsigned int i = 0; i < maxVarNum; ++i) {
			name = refCountVec[i].first;
			addr = -getOffset(name);
			mipsout << "sw $s" << i << ", " << addr << "($fp)" << endl;
		}

		for (int i = 0; i < 10; i++) {
			if (regpool.regs[i].busy) {
				reg2Mem(i);
			}
		}
	}
	else if (option == 2) {
		for (int i = 0; i < 10; i++) {
			if (regpool.regs[i].busy && regpool.regs[i].kind == 3) {
				reg2Mem(i);
			}
		}
	}
	else {	//option == 3
		mipsout << "#clearReg(3)" << endl;
		for (int i = 0; i < 10; i++) {
			if (regpool.regs[i].busy) {
				if (regpool.regs[i].kind == 2 || regpool.regs[i].kind == 3) {
					reg2Mem(i);
				}
				else if (regpool.regs[i].kind == 1 && symTab.search(regpool.regs[i].name).para == 1) {
					reg2Mem(i);
				}
			}
			
		}
	}
	regpool.clearRegs();
}


/*
�ָ��ֳ��������ü�����ǰ�˸����ص��Ĵ�����
*/
void MipsGenerator::recovery() {
	string fname = symTab.getCurFunc().name;
	string name;
	int addr;
	unsigned int maxVarNum;

	//�������ü�����
	vector<PAIR> refCountVec;
	refCountVec = funcRefCountMap[symTab.getCurFunc().name];
	maxVarNum = ((refCountVec.size() < 8)) ? refCountVec.size() : 8;
	for (unsigned int i = 0; i < maxVarNum; ++i) {
		name = refCountVec[i].first;
		addr = -getOffset(name);
		mipsout << "lw $s" << i << ", " << addr << "($fp)" << endl;
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
	mipsout << "addu $fp, $sp, " << para * 4 << endl;
	mipsout << "subi $sp, $sp, " << fsize - para * 4 + 32 * 4 << endl;
	
	//���мĴ����Ĳ�������ʼֵ
	unsigned int maxVarNum;
	string name;
	int addr;
	vector<PAIR> refCountVec;
	refCountVec = funcRefCountMap[symTab.getCurFunc().name];
	maxVarNum = ((refCountVec.size() < 8)) ? refCountVec.size() : 8;
	for (unsigned int i = 0; i < maxVarNum; ++i) {
		name = refCountVec[i].first;
		if (symTab.isPara(name)) {
			addr = -getOffset(name);
			mipsout << "lw $s" << i << ", " << addr << "($fp)" << endl;
		}
	}
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
			mipsout << "addi " << reg3 << ", " << reg2 << ", " << op1name << endl;
		}
		else if (IS_NUM(op2name)) {
			mipsout << "addi " << reg3 << ", " << reg1 << ", " << op2name << endl;
		}
		else {
			mipsout << "addu " << reg3 << ", " << reg1 << ", " << reg2 << endl;
		}
	}
	else if (curq.oper == "SUB") {
		if (IS_NUM(op1name)) {
			reg1 = getRegWithVal(op1name);
			mipsout << "subu " << reg3 << ", " << reg1 << ", " << reg2 << endl;
		}
		else if (IS_NUM(op2name)) {
			mipsout << "subi " << reg3 << ", " << reg1 << ", " << op2name << endl;
		}
		else {
			mipsout << "subu " << reg3 << ", " << reg1 << ", " << reg2 << endl;
		}
	}

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
		mipsout << "mul "<< reg3 << ", " << reg1 << ", " << reg2 << endl;
		//mipsout << "mflo " << reg3 << endl;
	}
	else {	//curq.oper == "DIV"
		mipsout << "div " << reg1 << ", " << reg2 << endl;
		mipsout << "mflo " << reg3 << endl;
	}



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
	//for (int i = 4; i <= 25; i++) {	//������ʱ�Ĵ�����
	//	mipsout << "sw $" << i << ", " << -i * 4 << "($sp)" << endl;
	//}

	mipsout << "#clearRegs(1)" << endl;
	clearRegs(1);
	mipsout << "sw $fp ," << -30 * 4 << "($sp)" << endl;
	mipsout << "sw $ra ," << -31 * 4 << "($sp)" << endl;

	mipsout << "jal " << fname << endl;

	
	mipsout << "lw $fp ," << -para * 4 - 30 * 4 << "($sp)" << endl;
	mipsout << "lw $ra ," << -para * 4 - 31 * 4 << "($sp)" << endl;
	recovery();

	/*for (int i = 4; i <= 25; i++) {
		mipsout << "lw $" << i << ", " << -para * 4 - i * 4 << "($sp)" << endl;
	}*/

}


/*
PUSH			��	��������
x = tar(a, b)  ==> PUSH a
*/
void MipsGenerator::mipsPUSH() {
	string name = curq.res;
	string reg;
	
	reg = getRegWithVal(name);
	mipsout << "sw " << reg << ", ($sp)" << endl;
	mipsout << "subi $sp, $sp, 4" << endl;
}


/*
VOF	��		��	���ܺ�������ֵ
x = tar(a, b)	VOF tar x
�������Ƹ�ֵ���Ⱥ����Ϊ��ʱ����
*/
void MipsGenerator::mipsVOF() {
	string resname = curq.res;
	string reg;
	reg = getReg(resname);
	
	mipsout << "move " << reg << ", $v0" << endl;

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
	string reg1;
	string reg3;
	//��ȡ��ʽ�ұ�
	reg1 = getRegWithVal(op1name);

	//��ȡ��ʽ���
	reg3 = getReg(resname);

	mipsout << "move " << reg3 << ", " << reg1 << endl;

}


//TODO: ����������
/*
SARY ��	��	��	����Ԫ�ظ�ֵ
array[i] = x ==> SARY array i x
i �� xӦ�ö��Ǿֲ�����
*/
void MipsGenerator::mipsSARY() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string resname = curq.res;
	string reg1;
	string reg2;
	string reg3;

	//��ȡi��reg2������ƫ�ƣ�ƫ�ƺ��ֵ��ַΪa2
	reg2 = getRegWithVal(op2name);
	mipsout << "sll $a2, " << reg2 << ", 2" << endl;

	//��ȡ�����ַ��reg1
	//reg1 = getReg("000");
	if (symTab.isGlobal(op1name)) {	//ȫ�ֱ���������ĵ�ַ���Ḵ�ã���v1��
		mipsout << "la $a3, " << op1name << endl;
		mipsout << "addu $a3, $a3, $a2" << endl;
		//mipsout << "sra " << reg2 << ", " << reg2 << ", 2" << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����������ֻ������
		int op1addr = -getOffset(op1name);
		mipsout << "addi $a3, $fp, " << op1addr << endl;
		mipsout << "subu $a3, $a3, $a2" << endl;
		//mipsout << "sra " << reg2 << ", " << reg2 << ", 2" << endl;
	}

	//ȡֵx��reg3���������鸳ֵ
	reg3 = getRegWithVal(resname);
	mipsout << "sw " << reg3 << ", ($a3)" << endl;
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
	string reg1;
	string reg2;
	string reg3;

	//��ȡi��reg2
	reg2 = getRegWithVal(op2name);
	mipsout << "sll $a2, " << reg2 << ", 2" << endl;

	//��ȡ�����ַ��reg1
	//reg1 = getReg("000");
	if (symTab.isGlobal(op1name)) {	//ȫ�ֱ���������ĵ�ַ���Ḵ�ã���v1��
		mipsout << "la $a3, " << op1name << endl;
		mipsout << "addu $a3, $a3, $a2"<< endl;
		//mipsout << "sra " << reg2 << ", " << reg2 << ", 2" << endl;
	}
	else {							//�ǲ��ڼĴ����еľֲ�����������ֻ������
		int op1addr = -getOffset(op1name);
		mipsout << "addi $a3, $fp, " << op1addr << endl;
		mipsout << "subu $a3, $a3, $a2" << endl;
		//mipsout << "sra " << reg2 << ", " << reg2 << ", 2" << endl;
	}

	//ȡֵx��reg3
	reg3 = getReg(resname);
	mipsout << "lw " << reg3 << ", ($a3)" << endl;
}


/*
PRT	 	��	��	���			
0 ֻ�������� 1 ֻ���ַ��� 2 �ַ���������
*/
void MipsGenerator::mipsPRT() {
	if (curq.op1 == "0") {
		string name = curq.res;
		if (IS_NUM(name)) {
			mipsout << "li $v0, 1" << endl;
			mipsout << "li $a0, " << name << endl;
		}
		else {
			SymbolType type = symTab.search(name).type;
			string reg;

			if (type == INTTP)
				mipsout << "li $v0, 1" << endl;
			else
				mipsout << "li $v0, 11" << endl;

			reg = getRegWithVal(name);
			mipsout << "move $a0, " << reg << endl;
		}
		
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
		mipsout << "la $a0, " << "$enter" << endl;
		mipsout << "syscall" << endl;
	}
	else {
		mipsout << "li $v0, 4" << endl;
		mipsout << "la $a0, $string" << curq.op2 << endl;
		mipsout << "syscall" << endl;

		string name = curq.res;
		SymbolType type = symTab.search(name).type;
		string reg;

		if (type == INTTP)
			mipsout << "li $v0, 1" << endl;
		else
			mipsout << "li $v0, 11" << endl;

		reg = getRegWithVal(name);
		mipsout << "move $a0, " << reg << endl;
		mipsout << "syscall" << endl;

		mipsout << "li $v0, 4" << endl;
		mipsout << "la $a0, " << "$enter" << endl;
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
	string reg;

	if (type == INTTP)
		mipsout << "li $v0, 5" << endl;
	else
		mipsout << "li $v0, 12" << endl;
	mipsout << "syscall" << endl;

	reg = getReg(resname);
	mipsout << "move " << reg << ", $v0" << endl;
}


/*
RET			��	���ر��ʽ��ֵ
return a; ==> RET a
*/
void MipsGenerator::mipsRET() {
	string name = curq.res;
	int fsize = symTab.getCurFunc().value;
	int para = symTab.getCurFunc().para;
	string reg;

	if (IS_NUM(name))
		mipsout << "li $v0, " << name << endl;
	else {
		reg = getRegWithVal(name);
		mipsout << "move $v0, " << reg << endl;
	}

	clearRegs(2);
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

	clearRegs(2);
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
	string reg1 = getRegWithVal(op1name);
	string reg2 = getRegWithVal(op2name);
	clearRegs(3);
	mipsout << "bgt " << reg1 << ", " << reg2 << ", " << label << endl;
}


/*
BGE ��	��	��	���ڵ��ڱȽ���ת
a >= b ==> BGE a b lab
*/
void MipsGenerator::mipsBGE() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	string reg1 = getRegWithVal(op1name);
	string reg2 = getRegWithVal(op2name);
	clearRegs(3);
	mipsout << "bge " << reg1 << ", " << reg2 << ", " << label << endl;
	
}


/*
BEQ	��	��	��	������ת
a==b ==> BEQ a b lab
*/
void MipsGenerator::mipsBEQ() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	string reg1 = getRegWithVal(op1name);
	string reg2 = getRegWithVal(op2name);
	clearRegs(3);
	mipsout << "beq " << reg1 << ", " << reg2 << ", " << label << endl;
}


/*
BLE	��	��	��	С�ڵ��ڱȽ���ת
a <= b ==> BLE a b lab
*/
void MipsGenerator::mipsBLE() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	string reg1 = getRegWithVal(op1name);
	string reg2 = getRegWithVal(op2name);
	clearRegs(3);
	mipsout << "ble " << reg1 << ", " << reg2 << ", " << label << endl;;
}


/*
BLT ��	��	��	С�ڱȽ���ת
a < b ==> BLT a b lab
*/
void MipsGenerator::mipsBLT() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	string reg1 = getRegWithVal(op1name);
	string reg2 = getRegWithVal(op2name);
	clearRegs(3);
	mipsout << "blt " << reg1 << ", " << reg2 << ", " << label << endl;
}


/*
BNE	��	��	��	��������ת
a != b ==> BNE a b lab
*/
void MipsGenerator::mipsBNE() {
	string op1name = curq.op1;
	string op2name = curq.op2;
	string label = curq.res;
	string reg1 = getRegWithVal(op1name);
	string reg2 = getRegWithVal(op2name);
	clearRegs(3);
	mipsout << "bne " << reg1 << ", " << reg2 << ", " << label << endl;
}


/*
JUMP			��	��������ת
JUMP Lable1
*/
void MipsGenerator::mipsJUMP() {
	clearRegs(3);
	mipsout << "j " << curq.res << endl;
}


/*
LAB			��	���ñ�ǩ
LAB Lable1
*/
void MipsGenerator::mipsLAB() {
	clearRegs(3);
	mipsout << curq.res << ":" << endl;
}



void MipsGenerator::startWorking() {
	int glbIndex;
	glbIndex = mipsGlobal();
	for (unsigned int i = glbIndex; i < quaterList.size(); i++) {
		curq = quaterList[i];
		
		for (unsigned int j = 0; j < blockIndex.size(); j++) {
			if (i + 1 == blockIndex[j] && i + 1 < quaterList.size() 
				&& quaterList[i + 1].oper != "CALL" && quaterList[i + 1].oper != "RET"
				&& quaterList[i + 1].oper != "REN") {
				//mipsout << "#clearRegs(3)" << endl;
				//clearRegs(3);
				//break;
				//�˴��Ȳ������
			}
		}
		genMips();
	}
}