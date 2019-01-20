#include "lexer.h"
#include "parser.h"
#include "mips.h"
#include "dag.h"
#include "parser_old.h"
#include "mips_old.h"

using namespace std;

int main() {
	string srcpath;
	string lexerPathBefore = "./out/lexerBefore.txt";
	string lexerPathAfter = "./out/lexerAfter.txt";
	string parserPathBefore = "./out/parserBefore.txt";
	string parserPathAfter = "./out/parserAfter.txt";
	string symPathBefore = "./out/symbolBefore.txt";
	string symPathAfter = "./out/symbolAfter.txt";
	string quaterPathBefore = "./out/quaterBefore.txt";
	string quaterPathAfter = "./out/quaterAfter.txt";
	string asmPathBefore = "./out/resultBefore.asm";
	string asmPathAfter = "./out/resultAfter.asm";
	bool OldFlag = true;
	bool OptFlag = true;

	

	//srcpath = "./in/error5.c";
	cin >> srcpath;

	if (_access(srcpath.data(), 0) == -1) {
		cout << "File doesn't exist!" << endl;
		return 0;
	}

	if (OldFlag) {
		Parser_old parser_old;
		MipsGenerator_old generator_old(asmPathBefore);
		parser_old.lexer.fin.open(srcpath, ios::in | ios::binary);
		parser_old.lexer.fout.open(lexerPathBefore);
		parser_old.fout.open(parserPathBefore);
		parser_old.program();

		if (parser_old.lexer.ecount > 0) {
			cout << "Lexer_old analysis failed!" << endl;
		}
		else {
			cout << "Lexer_old analysis succeeded." << endl;
		}
		symTab.printTable(symPathBefore);
		printQuater(quaterPathBefore);
		if (errcount > 0) {
			cout << "Parser_old analysis failed!" << endl;
		}
		else {
			cout << "Parser_old analysis succeeded." << endl;
			generator_old.startWorking();
			cout << "Compiled_old successfully" << endl;
		}
		symTab.clear();
		quaterList.clear();
		stringPool.clear();
	}

	if (OptFlag) {
		Parser parser;
		MipsGenerator generator(asmPathAfter);
		parser.lexer.fin.open(srcpath, ios::in | ios::binary);
		parser.lexer.fout.open(lexerPathAfter);
		parser.fout.open(parserPathAfter);
		parser.program();

		if (parser.lexer.ecount > 0) {
			cout << "Lexer analysis failed!" << endl;
		}
		else {
			cout << "Lexer analysis succeeded." << endl;
		}

		dagInit();

		generator.referCount();
		symTab.printTable(symPathAfter);
		printQuater(quaterPathAfter);

		divideBlock();

		if (errcount > 0) {
			cout << "Parser analysis failed!" << endl;
		}
		else {
			cout << "Parser analysis succeeded." << endl;
			generator.startWorking();
			cout << "Compiled successfully" << endl;
		}
	}
	

	system("Pause");
	return 0;
}