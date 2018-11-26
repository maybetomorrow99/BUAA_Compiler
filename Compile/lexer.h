#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <iomanip>
using namespace std;
typedef enum {
	//error
	ERROR,
	// const int char void main
	CONST, INT, CHAR, VOID, MAIN,
	// if else do while switch case default
	IF, ELSE, DO, WHILE, SWITCH, CASE, DEFAULT,
	//scanf printf return
	SCANF, PRINTF, RETURN,
	//string num id char
	STRING, NUM, ID, SIGCHAR,
	// + - * /
	PLUS, MINUS, MULT, DIV,
	// ( [ { ) ] }
	LPAR, LBRK, LBRA, RPAR, RBRK, RBRA,
	// ; , :
	SEMI, COMMA, COLON,
	// = < <= > >=
	EQU, LSS, LEQ, GTR, GEQ,
	// != ==
	NEQ, EQEQ,
	// EOF
	ENDOFFILE
} TokenType;

extern std::string TokenName[];
extern std::string ReservedWords[];
void lexer_test();
const int ReservedWordsNum = 15;

class Token {
public:
	Token() { type = ERROR; lineNum = 1; str = ""; }
	TokenType type;
	int lineNum;
	std::string str;				//字符串转数值atoi(str.c_str())
};

class Lexer {
public:
	Lexer() { lineNum = 1; count = 1; ecount = 1; };
	ifstream fin;
	ofstream fout;
	int lineNum;					//行号 
	int count;
	int ecount;						//错误数
	Token getToken();
	void printToken(Token t);
private:
	string line;
	int ll;							//当前行长度
	int cc;							//字符指针
	Token token;
	bool isSpace(char ch);
	bool isNewline(char ch);
	bool isTab(char ch);
	bool isLetter(char ch);
	bool isDigit(char ch);
	TokenType reserver();
	char nextChar();
	void retract();
};

