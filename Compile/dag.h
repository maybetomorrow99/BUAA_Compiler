#pragma once
#include "parser.h"


extern vector<int> blockIndex;	//存储每个基本块的入口语句，左闭右开为基本块

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