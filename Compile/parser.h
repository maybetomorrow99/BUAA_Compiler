#pragma once
#include <iostream>
#include "lexer.h"

using namespace std;

extern void parser_test();

class Parser {
public:
	void getToken();
	void program();
	void constDecl();
	void constDef();
	void varDecl();
	void varDef();
	void funcWithVal();
	void funcWithNoVal();
	void mainFunc();
	void expression();
	void item();
	void factor();
	void declHeader();
	void paraTab();
	void compState();
	void stateCol();
	void statement();
	void ifState();
	void whileState();
	void switchState();
	void caseState();
	void funcWithValState();
	void funcWithNoValState();
	void varParaTab();
	void assignState();
	void scanfState();
	void printfState();
	void returnState();
private:
	Lexer lexer;
	Token curToken;
	queue<Token> tokens;
	void pushToken(Token t);
};