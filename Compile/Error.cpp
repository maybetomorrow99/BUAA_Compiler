#include "error.h"

int errcount = 0;

void error(int errid, int lineNum) {
	switch (errid) {
	case 0:  cout << "Unknown" << endl; break;
	case 1:  cout << "Missing right single quote" << " at line " << lineNum << endl; break;
	case 2:  cout << "Missing right double quotes" << " at line " << lineNum << endl; break;
	case 3:  cout << "The characters in single quotes are not within the specified range." << " at line " << lineNum << endl; break;
	case 4:  cout << "Exclamation mark appears separately" << " at line " << lineNum << endl; break;
	case 5:  cout << "invalid symbol" << " at line " << lineNum << endl; break;
	case 6:  cout << "String too long" << " at line " << lineNum << endl; break;
	case 7:  cout << "The number is too large" << " at line " << lineNum << endl; break;
	case 8:  cout << "Missing semicolon" << " at line " << lineNum << endl; break;
	case 9:  cout << "Missing identifier" << " at line " << lineNum << endl; break;
	case 10:  cout << "Missing equal sign" << " at line " << lineNum << endl; break;
	case 11:  cout << "Missing character" << " at line " << lineNum << endl; break;
	case 12:  cout << "Missing reserved words" << " at line " << lineNum << endl; break;
	case 13:  cout << "Missing right parenthesis" << " at line " << lineNum << endl; break;
	case 14:  cout << "Missing right bracket" << " at line " << lineNum << endl; break;
	case 15:  cout << "Missing right brace" << " at line " << lineNum << endl; break;
	case 16:  cout << "Missing left parenthesis" << " at line " << lineNum << endl; break;
	case 17:  cout << "Missing left bracket" << " at line " << lineNum << endl; break;
	case 18:  cout << "Missing left brace" << " at line " << lineNum << endl; break;
	case 19:  cout << "Missing main" << " at line " << lineNum << endl; break;
	case 20:  cout << "Missing else" << " at line " << lineNum << endl; break;
	case 21:  cout << "Missing constant" << " at line " << lineNum << endl; break;
	case 22:  cout << "Missing operator" << " at line " << lineNum << endl; break;
	case 23:  cout << "Missing letter" << " at line " << lineNum << endl; break;
	case 24:  cout << "Missing case" << " at line " << lineNum << endl; break;
	case 25:  cout << "Missing colon" << " at line " << lineNum << endl; break;
	case 26:  cout << "Missing while" << " at line " << lineNum << endl; break;
	case 27:  cout << "Missing return" << " at line " << lineNum << endl; break;
	case 28:  cout << "Expression error" << " at line " << lineNum << endl; break;
	case 29:  cout << "Identifier is not defined" << " at line " << lineNum << endl; break;
	case 30:  cout << "Identifier redefinition" << " at line " << lineNum << endl; break;
	case 31:  cout << "The identifier is too long" << " at line " << lineNum << endl; break;
	case 32:  cout << "Program structure order is wrong" << " at line " << lineNum << endl; break;
	case 33:  cout << "Parameter type does not match" << " at line " << lineNum << endl; break;
	case 34:  cout << "The number of parameters does not match" << " at line " << lineNum << endl; break;
	case 35:  cout << "Return value error" << " at line " << lineNum << endl; break;
	case 36:  cout << "Constant not initialized" << " at line " << lineNum << endl; break;
	case 37:  cout << "Variable not initialized" << " at line " << lineNum << endl; break;
	case 38:  cout << "Symbol table overflow" << " at line " << lineNum << endl; break;
	case 39:  cout << "Array overflow" << " at line " << lineNum << endl; break;

	}
}
