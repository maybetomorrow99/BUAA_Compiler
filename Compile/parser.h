#pragma once
#include "stdafx.h"
#include "lexer.h"
#include "error.h"
#include "symbol.h"
#include "quaternary.h"

void parser_test();

class Parser {
public:
	Parser() { tempIndex = 0; labelIndex = 0; }
	Lexer lexer;
	SymbolTable symTab;
	vector<Quaternary> quaterList;
	vector<string> stringPool;

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
	void condition(string label);
	void whileState();
	void switchState();
	void caseState(SymbolItem exprSym, string labelEnd);
	SymbolItem funcWithValState();
	void funcWithNoValState();
	void valParaTab();
	void assignState();
	void scanfState();
	void printfState();
	void returnState();

	void printQuater(string path);

private:
	Token curToken;
	queue<Token> tokens;
	queue<Token> tmpTokens;
	void pushToken(Token t);
	void clearToken();
	void retract();

	int tempIndex;
	string genVar();
	int labelIndex;
	string genLab();

	int insertString(string str);

	string name;		//表项
	SymbolKind kind;	//const/ var/ para/ array/ func
	SymbolType type;	//void/ int/ char/ string
	int value;			//常量的值
	int addr;			//地址偏移量
	int para;
};