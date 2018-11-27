#include "quaternary.h"

Quaternary::Quaternary(string oper, string op1, string op2, string res) {
	this->oper = oper;
	this->op1 = op1;
	this->op2 = op2;
	this->res = res;
}

string Quaternary::toString() {
	return oper + " " + op1 + " " + op2 + " " + res;
}
