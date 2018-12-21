#include "error.h"

int errcount = 0;

void error(int errid, int lineNum) {
	errcount++;
	cout << setw(4) << left << errcount;
	switch (errid) {
	case 0:  cout << "Unknown"; break;
	case 1:  cout << "Missing right single quote"; break;
	case 2:  cout << "Missing right double quotes"; break;
	case 3:  cout << "The characters in single quotes are not within the specified range."; break;
	case 4:  cout << "Exclamation mark appears separately"; break;
	case 5:  cout << "invalid symbol"; break;
	case 6:  cout << "String too long"; break;
	case 7:  cout << "The number is too large"; break;
	case 8:  cout << "Missing semicolon"; break;
	case 9:  cout << "Missing identifier"; break;
	case 10:  cout << "Missing equal sign"; break;
	case 11:  cout << "Missing character"; break;
	case 12:  cout << "Missing type"; break;
	case 13:  cout << "Missing right parenthesis"; break;
	case 14:  cout << "Missing right bracket"; break;
	case 15:  cout << "Missing right brace"; break;
	case 16:  cout << "Missing left parenthesis"; break;
	case 17:  cout << "Missing left bracket"; break;
	case 18:  cout << "Missing left brace"; break;
	case 19:  cout << "Missing main"; break;
	case 20:  cout << "Missing else"; break;
	case 21:  cout << "Missing constant"; break;
	case 22:  cout << "Missing operator"; break;
	case 23:  cout << "Missing letter"; break;
	case 24:  cout << "Missing case"; break;
	case 25:  cout << "Missing colon"; break;
	case 26:  cout << "Missing while"; break;
	case 27:  cout << "Missing return"; break;
	case 28:  cout << "Expression error"; break;
	case 29:  cout << "Identifier is not defined"; break;
	case 30:  cout << "Identifier redefinition"; break;
	case 31:  cout << "The identifier is too long"; break;
	case 32:  cout << "Missing return value"; break;
	case 33:  cout << "Parameter type does not match"; break;
	case 34:  cout << "The number of parameters does not match"; break;
	case 35:  cout << "Return value error"; break;
	case 36:  cout << "Constant not initialized"; break;
	case 37:  cout << "Variable not initialized"; break;
	case 38:  cout << "Symbol table overflow"; break;
	case 39:  cout << "Array overflow"; break;
	case 40:  cout << "Case constant repeat"; break;
	case 41:  cout << "Array index is not int"; break;
	case 42:  cout << "Assignment variable type are different"; break;
	case 43:  cout << "The expression in the condition is not an integer"; break;
	case 44:  cout << "Case constant type is incorrect"; break;
	case 45:  cout << "Assign to const"; break;
	case 46:  cout << "Missing integer"; break;
	case 47:  cout << "Parameterless function with parentheses"; break;
	case 48:  cout << "Missing default"; break;
	case 49:  cout << "Statement error"; break;
	default:  cout << "Unknown";
	}
	cout << " at line " << lineNum << endl;
}
