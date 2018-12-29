#pragma once
#include "stdafx.h"
#include "parser.h"


extern vector<int> blockIndex;	//存储每个基本块的入口语句，左闭右开为基本块

void divideBlock();
void mergeLVAR();
void dagInit();

class Node {
public:
	
};