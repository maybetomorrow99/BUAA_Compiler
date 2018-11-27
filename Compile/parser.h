#pragma once
#include "stdafx.h"
#include "lexer.h"
#include "error.h"
#include "symbol.h"
#include "quaternary.h"

void parser_test();

class Parser {
public:
	Lexer lexer;
	SymbolTable symTab;
	vector<Quaternary> quaterList;

	void getToken();
	void program();
	void constDecl();
	void constDef();
	void varDecl();
	void varDef();
	void funcWithVal();
	void funcWithNoVal();
	void mainFunc();
	void intNum();
	void expression();
	void item();
	void factor();
	void declHeader();
	void paraTab();
	void compState();
	void stateCol();
	void statement();
	void ifState();
	void condition();
	void whileState();
	void switchState();
	void caseState();
	void funcWithValState();
	void funcWithNoValState();
	void valParaTab();
	void assignState();
	void scanfState();
	void printfState();
	void returnState();
private:
	
	Token curToken;
	queue<Token> tokens;
	queue<Token> tmpTokens;
	void pushToken(Token t);
	void clearToken();
	void retract();
};