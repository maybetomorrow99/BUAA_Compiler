#pragma once
#include "stdafx.h"

class Quaternary {
public:
	Quaternary() {};
	Quaternary(string oper, string op1, string op2, string res);
	string oper;
	string op1;
	string op2;
	string res;
	string toString();
};
