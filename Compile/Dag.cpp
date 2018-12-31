#include "dag.h"


vector<int> blockIndex;

/*
划分基本块
*/
void divideBlock() {
	blockIndex.push_back(0);
	for (unsigned int i = 0; i < quaterList.size(); i++) {
		if (quaterList[i].oper == "FUNC" || quaterList[i].oper == "LAB") {
			blockIndex.push_back(i);
		}
		else if (quaterList[i].oper == "BGT" || quaterList[i].oper == "BGE" || quaterList[i].oper == "BEQ"
			|| quaterList[i].oper == "BLE" || quaterList[i].oper == "BLT" || quaterList[i].oper == "BNE"
			|| quaterList[i].oper == "JUMP" || quaterList[i].oper == "REN" || quaterList[i].oper == "RET") {
			blockIndex.push_back(i + 1);
		}
	}
}


/*
合并LVAR类的赋值指令
TODO:验证这一步是否有必要
LI        2                   $temp1
LVAR      $temp1              b

ADD       $temp3    c         $temp4
LVAR      $temp4              c
*/
void mergeLVAR() {
	vector<Quaternary> quaterListTemp;

	for (unsigned int i = 0; i < quaterList.size(); i++) {
		if ((quaterList[i].oper == "LI" 
			|| quaterList[i].oper == "ADD" || quaterList[i].oper == "SUB"
			|| quaterList[i].oper == "MUL" || quaterList[i].oper == "DIV") 
			&& quaterList[i + 1].oper == "LVAR") {
			if (quaterList[i].res[0] == '$' && (quaterList[i].res == quaterList[i + 1].op1)) {
				quaterList[i].res = quaterList[i + 1].res;
				vector<Quaternary>::iterator it = quaterList.begin() + i + 1;
				quaterList.erase(it);
			}
		}
	}
}

void dagInit() {
	mergeLVAR();

	divideBlock();

	//排序并去重
	sort(blockIndex.begin(), blockIndex.end());
	vector<int>::iterator iter = unique(blockIndex.begin(), blockIndex.end());
	blockIndex.erase(iter, blockIndex.end());


	for (unsigned int i = 0; i < blockIndex.size(); i++) {
		cout << blockIndex[i] + 1<< endl;
	}
	cout << "block num: " << blockIndex.size()<< endl;

}


void bulidDAG() {

}
