#pragma once
#include "stdafx.h"

class Quaternary {
public:
	string oper;
	string op1;
	string op2;
	string res;
	Quaternary(string oper, string op1, string op2, string res);
	string toString();
};
