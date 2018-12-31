#pragma once
#include "parser.h"


extern vector<int> blockIndex;	//�洢ÿ��������������䣬����ҿ�Ϊ������

void divideBlock();
void mergeLVAR();
void dagInit();

class Node {
public:
	string name;
	int id;
	Node* lchild;
	Node* rchild;
	bool is_mid;
	vector<string> var_names;
	
};