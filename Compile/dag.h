#pragma once
#include "parser.h"


extern vector<int> blockIndex;	//�洢ÿ��������������䣬����ҿ�Ϊ������

void divideBlock();
void mergeLVAR();
void dagInit();

class Node {
public:
	Node() { oper = ""; name = ""; lchild = NULL; rchild = NULL; is_mid = false; }
	string name;
	string oper;
	int id;
	Node* lchild;
	Node* rchild;
	bool is_mid;
	vector<Node> parents;
	
};