#include "stdafx.h"
#include "lexer.h"
#include "parser.h"
#include "mips.h"

using namespace std;

int main() {
	Parser parser;
	string srcpath;
	string lexerPath = "./out/lexer.txt";
	string parserPath = "./out/parser.txt";
	string symPath = "./out/symbol.txt";
	string quaterPath = "./out/quater.txt";
	string asmPath = "./out/result.asm";
	MipsGenerator generator(asmPath);

	srcpath = "./in/in1.c";
	//cin >> srcpath;

	if (_access(srcpath.data(), 0) == -1) {
		cout << "File doesn't exist!" << endl;
		return 0;
	}

	parser.lexer.fin.open(srcpath, ios::in | ios::binary);
	parser.lexer.fout.open(lexerPath);
	parser.fout.open(parserPath);
	parser.program();

	if (parser.lexer.ecount > 0) {
		cout << "Lexer analysis failed!" << endl;
		exit(0);
	}
	else {
		cout << "Lexer analysis succeeded." << endl;
	}

	symTab.printTable(symPath);
	printQuater(quaterPath);

	if (errcount > 0) {
		cout << "Parser analysis failed!" << endl;
		exit(0);
	}
	else {
		cout << "Parser analysis succeeded." << endl;
	}

	generator.startWorking();
	cout << "Compiled successfully" << endl;
	system("Pause");
	return 0;
}