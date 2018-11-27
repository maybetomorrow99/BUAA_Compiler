#pragma once
#include "stdafx.h"


typedef enum {

} Operator;

class Quaternary {
public:
	Operator oper;
	std::string op1;
	std::string op2;
	std::string res;
};