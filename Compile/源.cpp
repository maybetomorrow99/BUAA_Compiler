#include "stdafx.h"
#include "lexer.h"
#include "parser.h"
#include "mips.h"

using namespace std;

int main() {
	Parser parser;

	string srcpath;
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
	parser.lexer.fout.open("./out/out.txt");
	parser.program();
	symTab.printTable();
	printQuater(quaterPath);
	
	if (parser.lexer.ecount > 1)
		cout << "Compile failed!" << endl;
	else
		cout << "Compiled successfully" << endl;
	cout << "Parser has been completed" << endl;
	
	generator.startWorking();
	
	system("Pause");
	return 0;
}