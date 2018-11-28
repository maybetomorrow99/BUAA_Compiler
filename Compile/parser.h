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
	int intNum();
	SymbolItem expression();
	SymbolItem item();
	SymbolItem factor();
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
	SymbolItem funcWithValState();
	void funcWithNoValState();
	void valParaTab();
	void assignState();
	void scanfState();
	void printfState();
	void returnState();

	void printQuater();

private:
	Token curToken;
	queue<Token> tokens;
	queue<Token> tmpTokens;
	void pushToken(Token t);
	void clearToken();
	void retract();

	int tempIndex;
	string genVar();

	string genLab();

	string name;		//����
	SymbolKind kind;	//const/ var/ para/ array/ func
	SymbolType type;	//void/ int/ char/ string
	int value;			//������ֵ
	int addr;			//��ַƫ����
	int para;
};