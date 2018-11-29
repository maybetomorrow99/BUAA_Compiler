#include "stdafx.h"
#include "lexer.h"
#include "parser.h"

using namespace std;

int main() {
	Parser parser;
	string path;
	
	string quaterPath = "./out/quater.txt";
	string asmPath = "";

	path = "./in/in1.c";
	//cin >> path;

	if (_access(path.data(), 0) == -1) {
		cout << "File doesn't exist!" << endl;
		return 0;
	}
	parser.lexer.fin.open(path, ios::in | ios::binary);
	parser.lexer.fout.open("./out/out.txt");
	parser.program();
	parser.symTab.printTable();
	parser.printQuater(quaterPath);
	if (parser.lexer.ecount > 1)
		cout << "Compile failed!" << endl;
	else
		cout << "Compiled successfully" << endl;
	cout << "Parser has been completed" << endl;
	system("Pause");
	return 0;
}