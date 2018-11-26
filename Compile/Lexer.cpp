#include "lexer.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include <algorithm> 
#include <iomanip>
using namespace std;

std::string TokenName[] = {
	"error",
	"const", "int", "char", "void", "main",
	"if", "else", "do", "while", "switch", "case", "default",
	"scan", "printf", "return",
	"string", "num", "id", "singlechar",
	"+", "-", "*", "/",
	"(", "[", "{", ")", "]", "}",
	";", ",", ":",
	"=", "<", "<=", ">", ">=",
	"!=", "=="
};
std::string TokenSymbol[] = {
	"ERROR   ",
	"CONST   ", "INT     ", "CHAR    ", "VOID    ", "MAIN    ",
	"IF      ", "ELSE    ", "DO      ", "WHILE   ", "SWITCH  ", "CASE    ", "DEFAULT ",
	"SCANF   ", "PRINTF  ", "RETURN  ",
	"STRING  ", "NUM     ", "ID      ", "SIGCHAR ",
	"PLUS    ", "MINUS   ", "MULT    ", "DIV     ",
	"LPAR    ", "LBRK    ", "LBRA    ", "RPAR    ", "RBRK    ", "RBRA    ",
	"SEMI    ", "COMMA   ", "COLON   ",
	"EQU     ", "LSS     ", "LEQ     ", "GTR     ", "GEQ     ",
	"NEQ     ", "EQEQ    ",
	"ENDOFFILE"
};

std::string ReservedWords[] = {
	"const", "int", "char", "void", "main",
	"if", "else", "do", "while", "switch", "case", "default",
	"scanf", "printf", "return"
};



void Lexer::printToken(Token t) {
	if (t.type == ERROR)
		return;
	fout << "token " << setw(4) << left << count++ << ":";
	switch (t.type) {
	case ID:
	case NUM: fout << TokenSymbol[t.type] << setw(5) << left << t.str; break;
	case SIGCHAR: fout << TokenSymbol[t.type] << "'" << t.str << "'"; break;
	case STRING: fout << TokenSymbol[t.type] << "\"" << t.str << "\""; break;
	default:
		fout << TokenSymbol[t.type] << setw(5) << left << TokenName[t.type]; break;
	}
	fout << " at line " << lineNum << endl;
}

Token Lexer::getToken() {
	char ch = nextChar();
	while (isSpace(ch) || isNewline(ch) || isTab(ch)) {
		if (ch == '\n')
			lineNum++;
		ch = nextChar();
	}
	token.type = ERROR;
	token.lineNum = lineNum;
	token.str = "";
	if (isLetter(ch)) {				//判断是否是字母
		while (isLetter(ch) || isDigit(ch)) {
			token.str += ch;
			ch = nextChar();
		}
		if (ch != EOF)				//后退一个字符
			retract();
		transform(token.str.begin(), token.str.end(), token.str.begin(), ::tolower);
		token.type = reserver();	//查询是否是保留字
		if (token.type == 0) {		//字符串为标识符
			token.type = ID;

		}
	}
	else if (isDigit(ch)) {			//判断是否是数字
		while (isDigit(ch)) {
			token.str += ch;
			ch = nextChar();
		}
		if (ch != EOF)				//后退一个字符
			retract();
		token.type = NUM;			//此单词是数字
	}
	else if (ch == '\'') {			//判断是否是字符
		ch = nextChar();
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || isDigit(ch) || isLetter(ch)) {
			token.str += ch;
			ch = nextChar();
			if (ch == '\'')			
				token.type = SIGCHAR;
			else {					//字符单引号缺失
				token.type = ERROR;
				retract();
				fout << "ERROR#" << setw(4) << left << ecount++ << ":Missing single quotes " << "'" << token.str << " at line " << lineNum << endl;
			}
		}
		else {
			token.str += ch;
			token.type = ERROR;
			ch = nextChar();
			if (ch == '\'') {		//单引号内字符类型非法
				fout << "ERROR#" << setw(4) << left << ecount++ << ":Illegal character type in single quotes " << "'" << token.str << "'" << " at line " << lineNum << endl;
			}
			else {
				retract();
				fout << "ERROR#" << setw(4) << left << ecount++ << ":Missing single quotes " << "'" << token.str << " at line " << lineNum << endl;
			}
		}
	}
	else if (ch == '"') {			//判断是否是字符串
		ch = nextChar();
		while (ch == 32 || ch == 33 || (ch >= 35 && ch <= 126)) {
			token.str += ch;
			ch = nextChar();
		}
		if (ch == '"')				
			token.type = STRING;
		else {						//字符串双引号缺失
			token.type = ERROR;
			fout << "ERROR#" << setw(4) << left << ecount++ << ":Missing double quotes " << "\"" << token.str  << " at line " << lineNum << endl;
		}
	}
	else if (ch == '<') {
		ch = nextChar();
		if (ch == '=')
			token.type = LEQ;
		else {
			retract();
			token.type = LSS;
		}
	}
	else if (ch == '>') {
		ch = nextChar();
		if (ch == '=')
			token.type = GEQ;
		else {
			retract();
			token.type = GTR;
		}
	}
	else if (ch == '!') {
		ch = nextChar();
		if (ch == '=')
			token.type = NEQ;
		else {
			token.type = ERROR;
			retract();
			fout << "ERROR#" << setw(4) << left << ecount++ << ":Invalid symbol ! at line " << lineNum << endl;
		}
	}
	else if (ch == '=') {
		ch = nextChar();
		if (ch == '=')
			token.type = EQEQ;
		else {
			retract();
			token.type = EQU;
		}
	}
	else if (ch == '+') {
		token.type = PLUS;
	}
	else if (ch == '-') {
		token.type = MINUS;
	}
	else if (ch == '*') {
		token.type = MULT;
	}
	else if (ch == '/') {
		token.type = DIV;
	}
	else if (ch == '(') {
		token.type = LPAR;
	}
	else if (ch == '[') {
		token.type = LBRK;
	}
	else if (ch == '{') {
		token.type = LBRA;
	}
	else if (ch == ')') {
		token.type = RPAR;
	}
	else if (ch == ']') {
		token.type = RBRK;
	}
	else if (ch == '}') {
		token.type = RBRA;
	}
	else if (ch == ';') {
		token.type = SEMI;
	}
	else if (ch == ',') {
		token.type = COMMA;
	}
	else if (ch == ':') {
		token.type = COLON;
	}
	else if (ch == EOF) {
		token.type = ENDOFFILE;
	}
	else {							//非法字符
		fout << "ERROR#" << setw(4) << left << ecount++ << ":Invalid symbol " << ch << " at line " << lineNum << endl;
	}
	return token;
}

bool Lexer::isSpace(char ch) {
	return ch == ' ';
}

bool Lexer::isNewline(char ch) {
	return ch == '\n' || ch == '\r';
}

bool Lexer::isTab(char ch) {
	return ch == '\t';
}

bool Lexer::isLetter(char ch) {
	return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch == '_');
}

bool Lexer::isDigit(char ch) {
	return (ch >= '0' && ch <= '9');
}

TokenType Lexer::reserver() {
	for (int i = 0; i < ReservedWordsNum; i++) {
		if (token.str == ReservedWords[i]) {
			return (TokenType)(i + 1);
		}
	}
	return ERROR;
}

char Lexer::nextChar() {
	return fin.get();
}

void Lexer::retract() {
	fin.seekg(-1, ios::cur);
}

void lexer_test() {
	Lexer lexer;
	lexer.fin.open("./in/in2.c", ios::in | ios::binary);
	lexer.fout.open("./out/out2.txt");
	Token token = lexer.getToken();
	while (token.type != ENDOFFILE) {
		lexer.printToken(token);
		token = lexer.getToken();
	}
	if (lexer.ecount > 1)
		cout << "Compile failed!" << endl;
	else
		cout << "Compiled successfully" << endl;
}