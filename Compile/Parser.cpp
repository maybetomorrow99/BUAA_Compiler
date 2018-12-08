#include "parser.h"

SymbolTable symTab;
vector<Quaternary> quaterList;
vector<string> stringPool;

void Parser::getToken() {
	if (tokens.size()) {
		curToken = tokens.front();
		tokens.pop();
	}
	else {
		curToken = lexer.getToken();
	}
}


void Parser::pushToken(Token t) {
	tmpTokens.push(t);
}


void Parser::clearToken() {
	while (!tmpTokens.empty()) tmpTokens.pop();
}


void Parser::retract() {
	tokens = tmpTokens;
	clearToken();
}


/*
���ɱ�����
*/
string Parser::genVar() {
	string s = "$temp" + to_string(tempIndex++);
	return s;
}


/*
���ɱ�ǩ
*/
string Parser::genLab() {
	string s = "$label" + to_string(labelIndex++);
	return s;
}


/*
���볣�����У�����ֵΪ��Ӧ���ַ���
*/
int Parser::insertString(string str) {
	for (int i = 0; i < stringPool.size(); i++) {
		if (str == stringPool[i]) {
			return i;
		}
	}
	stringPool.push_back(str);
	return stringPool.size() - 1;
}


//�����������⣬ÿ���ӳ���ε����һ����getToken()
/*
<����>    :: = ��<����˵��>�ݣ�<����˵��>��{ <�з���ֵ��������> | <�޷���ֵ��������> }<������>
<����˵��> first = {const}
<����˵��> first = {int, char}
<�з���ֵ��������> first = {int, char}
<�޷���ֵ��������> first = {void}
<������> first ={void}
*/
void Parser::program() {
	getToken();

	//����˵��
	if (curToken.type == CONST) {
		constDecl();
	}

	//����˵�����з���ֵ��������
	if (curToken.type == INT || curToken.type == CHAR) {
		pushToken(curToken);
		getToken();
		if (curToken.type == ID) {
			pushToken(curToken);
			getToken();
			//����˵����token���ݵ���ʶ��λ��
			if (curToken.type == COMMA || curToken.type == SEMI || curToken.type == LBRK) {
				pushToken(curToken);
				retract();
				getToken();
				varDecl();
			}
			//�з���ֵ�������壬token���ݵ���ʶ��λ��
			else if (curToken.type == LPAR || curToken.type == LBRA) {
				pushToken(curToken);	//�˴������д���������һ��
				retract();
				getToken();
			}
		}
		else {
			error(UNKNOWN, lexer.lineNum);
		}
	}
	
	//{ <�з���ֵ��������> | <�޷���ֵ��������> }
	while (curToken.type == INT || curToken.type == CHAR || curToken.type == VOID) {
		//�з���ֵ����
		if (curToken.type == INT || curToken.type == CHAR) {
			pushToken(curToken);
			getToken();
			if (curToken.type == ID) {
				pushToken(curToken);
				getToken();
				if (curToken.type == LPAR || curToken.type == LBRA) {
					pushToken(curToken);
					retract();
					getToken();
					funcWithVal();
				}
				else {
					//int f��û������
					error(0, lexer.lineNum);
				}
			}
			else {
				error(MISSING_IDEN, lexer.lineNum);
			}
		}
		//�޷���ֵ������main����
		else {
			pushToken(curToken);
			getToken();
			//main������token���ݵ�void
			if (curToken.type == MAIN) {
				pushToken(curToken);
				retract();
				getToken();
				break;
			}
			//�޷���ֵ����
			else if (curToken.type == ID) {
				pushToken(curToken);
				retract();
				getToken();
				funcWithNoVal();
			}
			else {
				error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
			}
		}
	}

	//main����
	if (curToken.type == VOID) {
		pushToken(curToken);
		getToken();
		if (curToken.type == MAIN) {
			pushToken(curToken);
			retract();
			getToken();
			mainFunc();
		}
	}
	else {
		error(MISSING_MAIN, lexer.lineNum);
	}
	
	cout << setw(4) << left << lexer.lineNum<< "This is a program" << endl;
}


/*
<����˵��> ::=  const<��������>;{ const<��������>;}
*/
void Parser::constDecl() {
	if (curToken.type == CONST) {
		getToken();
		if (curToken.type == INT || curToken.type == CHAR) {
			constDef();

			if (curToken.type == SEMI) {

				getToken();
			}
			else {
				error(MISSING_SEMI, lexer.lineNum);
			}
		}
		
	}
	else {
		error(MISSING_CONS, lexer.lineNum);
	}
	while (curToken.type == CONST) {
		getToken();
		if (curToken.type == INT || curToken.type == CHAR) {
			constDef();
			if (curToken.type == SEMI) {
				getToken();
			}
			else {
				error(MISSING_SEMI, lexer.lineNum);
				break;
			}
		}
		else {
			error(UNKNOWN, lexer.lineNum);
		}
	}
	cout << setw(4) << left << lexer.lineNum<< "This is a constant declaration" << endl;
}


/*
<��������>   ::=   int<��ʶ��>��<����>{,<��ʶ��>��<����>}
				| char<��ʶ��>��<�ַ�>{,<��ʶ��>��<�ַ�>}
*/
void Parser::constDef() {
	if (curToken.type == INT) {
		getToken();
		if (curToken.type != ID) {
			error(MISSING_IDEN, lexer.lineNum);
		}
		name = curToken.str;
		getToken();
		if (curToken.type != EQU) {
			error(MISSING_EQUAL_SIGN, lexer.lineNum);
		}

		getToken();
		value = intNum();

		if (!symTab.locInTable(name)) {
			symTab.insert(name, CONSTKD, INTTP, value);
			quaterList.push_back(Quaternary("CON", "int", to_string(value), name));
		}
		else {
			error(IDENT_REDEF, lexer.lineNum);
		}

		while (curToken.type == COMMA) {
			getToken();
			if (curToken.type != ID) {
				error(MISSING_IDEN, lexer.lineNum);
			}
			name = curToken.str;
			getToken();
			if (curToken.type != EQU) {
				error(MISSING_EQUAL_SIGN, lexer.lineNum);
			}

			getToken();
			value = intNum();
			if (!symTab.locInTable(name)) {
				symTab.insert(name, CONSTKD, INTTP, value);
				quaterList.push_back(Quaternary("CON", "int", to_string(value), name));
			}
			else {
				error(IDENT_REDEF, lexer.lineNum);
			}
		}							
	}
	else if (curToken.type == CHAR) {

		getToken();
		if (curToken.type != ID) {
			//error
			error(MISSING_IDEN, lexer.lineNum);
		}
		name = curToken.str;

		getToken();
		if (curToken.type != EQU) {
			error(MISSING_EQUAL_SIGN, lexer.lineNum);
		}
		getToken();
		if (curToken.type != SIGCHAR) {
			error(MISSING_CHAR, lexer.lineNum);
		}
		
		value = curToken.str[0];
		if (!symTab.locInTable(name)) {
			symTab.insert(name, CONSTKD, CHARTP, value);
			quaterList.push_back(Quaternary("CON", "char", to_string(value), name));
		}
		else {
			error(IDENT_REDEF, lexer.lineNum);
		}

		getToken();
		while (curToken.type == COMMA) {
			getToken();
			if (curToken.type != ID) {
				//error
				error(MISSING_IDEN, lexer.lineNum);
			}
			name = curToken.str;

			getToken();
			if (curToken.type != EQU) {
				error(MISSING_EQUAL_SIGN, lexer.lineNum);
			}

			getToken();
			if (curToken.type != SIGCHAR) {
				error(MISSING_CHAR, lexer.lineNum);
			}

			value = curToken.str[0];
			if (!symTab.locInTable(name)) {
				symTab.insert(name, CONSTKD, CHARTP, value);
				quaterList.push_back(Quaternary("CON", "char", to_string(value), name));
			}
			else {
				error(IDENT_REDEF, lexer.lineNum);
			}
			 
			getToken();
		}
	}
	else {
		//error
		error(MISSING_IDEN, lexer.lineNum);
	}

	cout << setw(4) << left << lexer.lineNum<< "This is a constant definition" << endl;
}


/*
<����˵��>  ::= <��������>;{<��������>;}
*/
void Parser::varDecl() {
	varDef();
	if (curToken.type == SEMI) {
		getToken();
		while (curToken.type == INT || curToken.type == CHAR) {
			pushToken(curToken);
			getToken();
			if (curToken.type == ID) {
				pushToken(curToken);
				getToken();
				if (curToken.type == COMMA || curToken.type == SEMI || curToken.type == LBRK) {
					pushToken(curToken);
					retract();
					getToken();
					varDef();
					if (curToken.type == SEMI) {
						getToken();
					}
					else {
						error(MISSING_SEMI, lexer.lineNum);
					}
				}
				//�з���ֵ�������壬token���ݵ���ʶ��λ��
				else if (curToken.type == LPAR || curToken.type == LBRA) {
					pushToken(curToken);	//�˴������д���������һ��
					retract();
					getToken();
					break;
				}
			}
		}
	}

	cout << setw(4) << left << lexer.lineNum<< "This is a variable declaration" << endl;
}


/*
<��������>  ::= <���ͱ�ʶ��>(<��ʶ��>|<��ʶ��>��[��<�޷�������>��]��){,(<��ʶ��>|<��ʶ��>��[��<�޷�������>��]��) } 
//<�޷�������>��ʾ����Ԫ�صĸ�������ֵ�����0
*/
void Parser::varDef() {
	if (curToken.type == INT || curToken.type == CHAR) {
		type = curToken.type == INT ? INTTP : CHARTP;

		getToken();
		if (curToken.type != ID) {
			error(MISSING_IDEN, lexer.lineNum);
		}
		name = curToken.str;

		getToken();
		if (curToken.type == LBRK) {
			getToken();
			if (curToken.type == NUM) {
				value = atoi(curToken.str.c_str());
				getToken();
				if (curToken.type == RBRK) {
					if (!symTab.locInTable(name)) {
						symTab.insert(name, ARRAYKD, type, value);
						quaterList.push_back(Quaternary("ARY", (type == INTTP ? "int" : "char"), to_string(value), name));
					}
					else {
						error(IDENT_REDEF, lexer.lineNum);
					}

					getToken();
				}
			}
		}
		else {	//�˴�δ���д�����ֱ�Ӳ�����ű�
			if (!symTab.locInTable(name)) {
				symTab.insert(name, VARKD, type, 0);
				quaterList.push_back(Quaternary("VAR", (type == INTTP ? "int" : "char"), "", name));
			}
			else {
				error(IDENT_REDEF, lexer.lineNum);
			}
		}

		while (curToken.type == COMMA) {
			getToken();
			if (curToken.type != ID) {
				//error
				error(MISSING_IDEN, lexer.lineNum);
			}
			name = curToken.str;

			getToken();
			if (curToken.type == LBRK) {
				getToken();
				if (curToken.type == NUM) {
					value = atoi(curToken.str.c_str());
					getToken();
					if (curToken.type == RBRK) {
						if (!symTab.locInTable(name)) {
							symTab.insert(name, ARRAYKD, type, value);
							quaterList.push_back(Quaternary("ARY", (type == INTTP ? "int" : "char"), to_string(value), name));
						}
						else {
							error(IDENT_REDEF, lexer.lineNum);
						}

						getToken();
					}

				}
			}
			else {
				if (!symTab.locInTable(name)) {
					symTab.insert(name, VARKD, type, 0);
					quaterList.push_back(Quaternary("VAR", (type == INTTP ? "int" : "char"), "", name));
				}
				else {
					error(IDENT_REDEF, lexer.lineNum);
				}
			}
		}
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}

	cout << setw(4) << left << lexer.lineNum<< "This is a variable definitions" << endl;
}


/*
<�з���ֵ��������>  ::=  <����ͷ��>��(��<������>��)�� ��{��<�������>��}��|<����ͷ��>��{��<�������>��}��
<����ͷ��>   ::=  int<��ʶ��>|char<��ʶ��>
//��һ��ѡ��Ϊ�в�����������ڶ���ѡ��Ϊ�޲��������
*/
void Parser::funcWithVal() {
	retFlag = false;
	//����ͷ��
	string fname;
	if (curToken.type == INT || curToken.type == CHAR) {
		type = (curToken.type == INT) ? INTTP : CHARTP;

		getToken();
		if (curToken.type == ID) {
			name = curToken.str;
			fname = name;

			getToken();
		}
		else {
			error(MISSING_IDEN, lexer.lineNum);
		}
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}

	if (curToken.type == LPAR) {	//�в���
		if (!symTab.inTable(name)) {
			symTab.insert(name, FUNCKD, type, 0);
			quaterList.push_back(Quaternary("FUNC", (type == INTTP ? "int" : "char"), "", name));
		}
		else {
			error(IDENT_REDEF, lexer.lineNum);
		}

		getToken();
		paraTab();	//�������м�¼�˲�������
		symTab.updateFuncPara(fname, value);

		if (curToken.type != RPAR) {
			error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
		}
		getToken();
		if (curToken.type != LBRA) {
			error(MISSING_LEFT_BRACE, lexer.lineNum);
		}
		getToken();
		compState();
		if (curToken.type != RBRA) {
			error(MISSING_RIGHT_BRACE, lexer.lineNum);
		}

		getToken();
	}
	else if (curToken.type == LBRA) {	//�޲���
		if (!symTab.inTable(name)) {
			symTab.insert(name, FUNCKD, type, 0);
			quaterList.push_back(Quaternary("FUNC", (type == INTTP ? "int" : "char"), "", name));
		}
		else {
			error(IDENT_REDEF, lexer.lineNum);
		}

		getToken();
		compState();
		if (curToken.type != RBRA) {
			error(MISSING_LEFT_BRACE, lexer.lineNum);
		}

		getToken();
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}
	if (!retFlag) {
		error(0, lexer.lineNum);
	}
	symTab.updateFuncVal();
	cout << setw(4) << left << lexer.lineNum<< "This is a function definition with return value" << endl;
}


/*
<�޷���ֵ��������>  ::= void<��ʶ��>(��<������>��)����{��<�������>��}��| void<��ʶ��>{��<�������>��}��
//��һ��ѡ��Ϊ�в�����������ڶ���ѡ��Ϊ�޲��������
*/
void Parser::funcWithNoVal() {
	retFlag = false;
	string fname;

	if (curToken.type != VOID) {
		error(UNKNOWN, lexer.lineNum);
	}

	type = VOIDTP;

	getToken();
	if (curToken.type != ID) {
		error(MISSING_IDEN, lexer.lineNum);
	}
	name = curToken.str;
	fname = name;

	getToken();
	if (curToken.type == LPAR) {	//�в���
		if (!symTab.inTable(name)) {
			symTab.insert(name, FUNCKD, type, 0);
			quaterList.push_back(Quaternary("FUNC", "void", "", name));
		}
		else {
			error(IDENT_REDEF, lexer.lineNum);
		}

		getToken();
		paraTab();
		symTab.updateFuncPara(fname, value);

		if (curToken.type != RPAR) {
			error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
		}
		getToken();
		if (curToken.type != LBRA) {
			error(MISSING_LEFT_BRACE, lexer.lineNum);
		}
		getToken();
		compState();
		if (curToken.type != RBRA) {
			error(MISSING_RIGHT_BRACE, lexer.lineNum);
		}

		getToken();
	}
	else if (curToken.type == LBRA) {	//�޲���
		if (!symTab.inTable(name)) {
			symTab.insert(name, FUNCKD, type, 0);
			quaterList.push_back(Quaternary("FUNC", "void", "", name));
		}
		else {
			error(IDENT_REDEF, lexer.lineNum);
		}

		getToken();
		compState();
		if (curToken.type != RBRA) {
			error(MISSING_RIGHT_BRACE, lexer.lineNum);
		}

		getToken();
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}


	/*if (!retFlag) {
		quaterList.push_back(Quaternary("REN", "", "", ""));
	}*/

	//Ĭ�����޷���ֵ������������return;
	quaterList.push_back(Quaternary("REN", "", "", ""));
	symTab.updateFuncVal();

	cout << setw(4) << left << lexer.lineNum<< "This is a function definition without return value" << endl;
}


/*
<����ͷ��>   ::=  int<��ʶ��>|char<��ʶ��>
*/
void Parser::declHeader() {
	if (curToken.type == INT || curToken.type == CHAR) {
		getToken();
		if (curToken.type == ID) {
			getToken();
		}
		else {
			error(MISSING_IDEN, lexer.lineNum);
		}
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}

	cout << setw(4) << left << lexer.lineNum<< "This is a declaration header" << endl;
}


/*
<������>    ::= void main��(����)�� ��{��<�������>��}��
*/
void Parser::mainFunc() {
	if (curToken.type != VOID) {
		error(UNKNOWN, lexer.lineNum);
	}
	getToken();
	if (curToken.type != MAIN) {
		error(MISSING_MAIN, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	if (curToken.type != RPAR) {
		error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LBRA) {
		error(MISSING_LEFT_BRACE, lexer.lineNum);
	}
	getToken();

	symTab.insert("main", FUNCKD, VOIDTP, 0);
	quaterList.push_back(Quaternary("FUNC", "void", "", "main"));

	compState();
	if (curToken.type != RBRA) {
		error(MISSING_LEFT_BRACE, lexer.lineNum);
	}

	symTab.updateFuncVal();
	cout << setw(4) << left << lexer.lineNum<< "This is main function" << endl;
}


/*
<����>        ::= �ۣ�������<�޷�������>
*/
int Parser::intNum() {
	int sign = 1;
	if (curToken.type == PLUS || curToken.type == MINUS) {
		if (curToken.type == MINUS)
			sign = -1;
		getToken();
	}
	if (curToken.type == NUM) {
		sign *= atoi(curToken.str.c_str());
		getToken();
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}
	return sign;
	//cout << setw(4) << left << lexer.lineNum<< "This is a integer" << endl;
}


/*
<���ʽ>    ::= �ۣ�������<��>{<�ӷ������><��>}  
[+|-]ֻ�����ڵ�һ��<��>
����ֵΪһ���µı���
*/
SymbolItem Parser::expression() {
	SymbolItem itemSym1, itemSym2;
	int sign = 0;
	if (curToken.type == PLUS || curToken.type == MINUS) {
		sign = curToken.type;
		getToken();
	}
	itemSym1 = item();
	if (sign == MINUS) {
		itemSym2.name = genVar();
		itemSym2.type = INTTP;
		symTab.insert(itemSym2.name, VARKD, INTTP, 0);
		quaterList.push_back(Quaternary("LI", to_string(0), "", itemSym2.name));
		quaterList.push_back(Quaternary("SUB", itemSym2.name, itemSym1.name, itemSym1.name));
	}

	while (curToken.type == PLUS || curToken.type == MINUS) {
		sign = curToken.type;
		getToken();
		itemSym2 = item();

		if (sign == PLUS)
			quaterList.push_back(Quaternary("ADD", itemSym1.name, itemSym2.name, itemSym1.name));
		else
			quaterList.push_back(Quaternary("SUB", itemSym1.name, itemSym2.name, itemSym1.name));
	}
	
	cout << setw(4) << left << lexer.lineNum<< "This is an expression" << endl;
	return itemSym1;
}


/*
<��>     ::= <����>{<�˷������><����>}
*/
SymbolItem Parser::item() {
	SymbolItem factorSym1, factorSym2;
	factorSym1 = factor();
	while (curToken.type == MULT || curToken.type == DIV) {
		int sign = curToken.type;
		getToken();
		factorSym2 = factor();

		//����һ������
		if (sign == MULT)
			quaterList.push_back(Quaternary("MUL", factorSym1.name, factorSym2.name, factorSym1.name));
		else
			quaterList.push_back(Quaternary("DIV", factorSym1.name, factorSym2.name, factorSym1.name));

		//��������֮������һ��ΪINTTP
		symTab.changeVarType(factorSym1.name);
	}

	cout << setw(4) << left << lexer.lineNum<< "This is a item" << endl;
	return factorSym1;
}


/*
<����>    ::= <��ʶ��>��<��ʶ��>��[��<���ʽ>��]����<����>|<�ַ�>��<�з���ֵ�����������>|��(��<���ʽ>��)��
*/
SymbolItem Parser::factor() {
	//<��ʶ��>��<��ʶ��>��[��<���ʽ>��]��|<�з���ֵ�����������>
	SymbolItem factorSym;
	SymbolItem arrayIndex;
	if (curToken.type == ID) { //***TODO
		pushToken(curToken);
		 
		string idName = curToken.str;
		if (!symTab.inTable(idName)) {
			error(IDENT_NOT_DEF, lexer.lineNum);
		}
		
		getToken();
		if (curToken.type == LBRK) {		//<��ʶ��>��[��<���ʽ>��]��
			clearToken();
			getToken();

			//�������ֵ�ŵ�һ���±�����
			factorSym.name = genVar();
			factorSym.type = symTab.search(idName).type;
			symTab.insert(factorSym.name, VARKD, factorSym.type, 0);
			quaterList.push_back(Quaternary("VAR", (type == INTTP ? "int" : "char"), "", factorSym.name));

			arrayIndex = expression();
			if (curToken.type == RBRK) {
				getToken();

				//ȡ����ֵ
				quaterList.push_back(Quaternary("LARY", idName, arrayIndex.name, factorSym.name));
			}
			else {
				error(MISSING_RIGHT_BRACKET, lexer.lineNum);
			}
		}
		else if (curToken.type == LPAR) {	//<�з���ֵ�����������>�в���
			pushToken(curToken);
			retract();
			getToken();

			factorSym = funcWithValState();
			factorSym.type = symTab.searchFunc(idName).type;
			symTab.insert(factorSym.name, VARKD, factorSym.type, 0);

			//���ܺ�������ֵ
			quaterList.push_back(Quaternary("VOF", idName, "", factorSym.name));
		}
		else if (symTab.isFunc(idName)) {	//<�з���ֵ�����������>�޲���������Ǻ���������Ҫ����
			pushToken(curToken);
			retract();
			getToken();

			factorSym = funcWithValState();
			type = symTab.searchFunc(idName).type;
			symTab.insert(factorSym.name, VARKD, type, 0);

			//���ܺ�������ֵ
			quaterList.push_back(Quaternary("VOF", idName, "", factorSym.name));
		}
		else {					//<��ʶ��>
			clearToken();
			
			factorSym.name = genVar();
			factorSym.type = symTab.search(idName).type;
			symTab.insert(factorSym.name, VARKD, factorSym.type, 0);
			quaterList.push_back(Quaternary("LVAR", idName, "", factorSym.name));
		}

	}
	//����
	else if (curToken.type == PLUS || curToken.type == MINUS || curToken.type == NUM) {
		value = intNum();
		factorSym.name = genVar();
		factorSym.type = INTTP;
		symTab.insert(factorSym.name, VARKD, INTTP, value);
		quaterList.push_back(Quaternary("LI", to_string(value), "", factorSym.name));
	}
	else if (curToken.type == SIGCHAR) {	//�ַ�
		factorSym.name = genVar();
		factorSym.type = CHARTP;
		symTab.insert(factorSym.name, VARKD, CHARTP, curToken.str[0]);
		quaterList.push_back(Quaternary("LI", to_string(curToken.str[0]), "", factorSym.name));
		getToken();
	}
	else if (curToken.type == LPAR) {		//���ʽ
		getToken();
		factorSym = expression();
		symTab.insert(factorSym.name, VARKD, INTTP, 0);	//TODO:�˴����������⣬���ʽ�����Ͳ�һ��������

		if (curToken.type == RPAR) {
			getToken();
		}
		else {
			error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
		}
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}

	
	cout << setw(4) << left << lexer.lineNum<< "This is a factor" << endl;
	return factorSym;
}


/*
<������>    ::=  <���ͱ�ʶ��><��ʶ��>{,<���ͱ�ʶ��><��ʶ��>}
*/
void Parser::paraTab() {
	value = 0;
	if (curToken.type == INT || curToken.type == CHAR) {
		type = curToken.type == INT ? INTTP : CHARTP;

		getToken();
		if (curToken.type == ID) {
			name = curToken.str;
			value++;

			//�˴�Ӧ�ò�������ȫ�ֱ����ض������⣬����ֻ�����뺯���ڲ�����
			if (!symTab.paraInTable(name)) {
				symTab.insert(name, PARAKD, type, 0);
				quaterList.push_back(Quaternary("PARA", (type == INTTP ? "int" : "char"), "", name));
			}
			else {
				error(IDENT_REDEF, lexer.lineNum);
			}

			getToken();

		}
		else {
			error(MISSING_IDEN, lexer.lineNum);
		}
	}
	while (curToken.type == COMMA) {
		getToken();
		if (curToken.type == INT || curToken.type == CHAR) {
			type = curToken.type == INT ? INTTP : CHARTP;

			getToken();
			if (curToken.type == ID) {
				name = curToken.str;
				value++;

				if (!symTab.paraInTable(name)) {
					symTab.insert(name, PARAKD, type, 0);
					quaterList.push_back(Quaternary("PARA", (type == INTTP ? "int" : "char"), "", name));
				}
				else {
					error(IDENT_REDEF, lexer.lineNum);
				}

				getToken();
			}
			else {
				error(MISSING_IDEN, lexer.lineNum);
			}
		}
		else {
			error(UNKNOWN, lexer.lineNum);
		}
	}

	cout << setw(4) << left << lexer.lineNum<< "This is a parameters table" << endl;
}


/*
<�������>   ::=  ��<����˵��>�ݣ�<����˵��>��<�����>
<����˵��> first = {const}
<����˵��> first = {int, char}
<�����> first = {if, do, {, switch, id, scanf, printf, ;, return}
*/
void Parser::compState() {
	if (curToken.type == CONST) {
		constDecl();
	}
	if (curToken.type == INT || curToken.type == CHAR) {
		varDecl();
	}
	if (curToken.type == IF || curToken.type == DO || curToken.type == LBRA || curToken.type == SWITCH ||
		curToken.type == ID || curToken.type == SCANF || curToken.type == PRINTF ||
		curToken.type == SEMI || curToken.type == RETURN) {
		stateCol();
	}
 	else if (curToken.type == RBRA) {
		//�����Ϊ��
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}
	cout << setw(4) << left << lexer.lineNum<< "This is a compound statement" << endl;
}


/*
<�����>   ::=��<���>��
*/
void Parser::stateCol() {
	while (curToken.type == IF || curToken.type == DO || curToken.type == LBRA || curToken.type == SWITCH ||
		curToken.type == ID || curToken.type == SCANF || curToken.type == PRINTF ||
		curToken.type == SEMI || curToken.type == RETURN) {
		statement();
	}
	cout << setw(4) << left << lexer.lineNum<< "This is a statement column" << endl;
}


/*
<���>    ::= <�������>��<ѭ�����>| ��{��<�����>��}����<������>|<�з���ֵ�����������>;
					  |<�޷���ֵ�����������>;��<��ֵ���>;��<�����>;��<д���>;��<��>;��<�������>;
<�������> first = {if}
<ѭ�����> first = {do}
��{��<�����>��}��first = {'{'}
<������> first = {switch}
<�з���ֵ�����������> first = {��ʶ��}
<�޷���ֵ�����������> first = {��ʶ��}
<��ֵ���> first = {��ʶ��}
<�����> first = {scanf}
<д���> first = {printf}
<��>; first = {;}
<�������> first = {return}
*/
void Parser::statement() {
	string name;
	switch (curToken.type) {
	case IF:
		ifState();
		break;
	case DO:
		whileState();
		break;
	case SWITCH:
		switchState();
		break;
	case LBRA:
		getToken();
		stateCol();
		if (curToken.type != RBRA) {
			error(MISSING_RIGHT_BRACE, lexer.lineNum);
		}
		getToken();
		break;
	case ID:	//�������û�ֵ
		name = curToken.str;
		pushToken(curToken);
		getToken();

		if (curToken.type == LPAR) {	//���������в�����TODO
			pushToken(curToken);
			retract();
			getToken();
			if (symTab.isFunc(name)) {
				if(symTab.searchFunc(name).type == VOIDTP)
					funcWithNoValState();
				else
					funcWithValState();
			}
		}
		else {
			//��ֵ�����޷���ֵ�޲�������������䣬TODO*****
			pushToken(curToken);
			retract();
			getToken();

			if (symTab.isFunc(name)) {
				if (symTab.searchFunc(name).type == VOIDTP)
					funcWithNoValState();
				else
					funcWithValState();
			}
			else
				assignState();
		}
		if (curToken.type != SEMI) {
			error(MISSING_SEMI, lexer.lineNum);
		}
		getToken();
		break;
	case SCANF:
		scanfState();
		if (curToken.type != SEMI) {
			error(MISSING_SEMI, lexer.lineNum);
		}
		getToken();
		break;
	case PRINTF:
		printfState();
		if (curToken.type != SEMI) {
			error(MISSING_SEMI, lexer.lineNum);
		}
		getToken();
		break;
	case SEMI:
		if (curToken.type != SEMI) {
			error(MISSING_SEMI, lexer.lineNum);
		}
		getToken();
		break;
	case RETURN:
		returnState();
		if (curToken.type != SEMI) {
			error(MISSING_SEMI, lexer.lineNum);
		}
		getToken();
		break;
	default:
		error(UNKNOWN, lexer.lineNum);
		break;
	}
}


/*
<�������>  ::=  if ��(��<����>��)��<���>else <���>
*/
void Parser::ifState() {
	string label1, label2;
	label1 = genLab();
	label2 = genLab();
	if (curToken.type != IF) {
		error(UNKNOWN, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	condition(label1);
	if (curToken.type != RPAR) {
		error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	statement();
	if (curToken.type != ELSE) {
		error(MISSING_ELSE, lexer.lineNum);
	}

	quaterList.push_back(Quaternary("JUMP", "", "", label2));
	quaterList.push_back(Quaternary("LAB", "", "", label1));
	getToken();
	statement();
	quaterList.push_back(Quaternary("LAB", "", "", label2));

	cout << setw(4) << left << lexer.lineNum<< "This is a if statement" << endl;
}


/*
<����>    ::=  <���ʽ><��ϵ�����><���ʽ>��<���ʽ> //���ʽΪ0����Ϊ�٣�����Ϊ��
*/
void Parser::condition(string label) {
	SymbolItem exprSym1, exprSym2;
	int tokenType;
	exprSym1 = expression();
	if (curToken.type == LSS || curToken.type == LEQ || curToken.type == GTR ||
		curToken.type == GEQ || curToken.type == NEQ || curToken.type == EQEQ) {
		tokenType = curToken.type;
		getToken();
		exprSym2 = expression();
		switch (tokenType) {
		case LSS:
			quaterList.push_back(Quaternary("BGE", exprSym1.name, exprSym2.name, label));
			break;
		case LEQ:
			quaterList.push_back(Quaternary("BGT", exprSym1.name, exprSym2.name, label));
			break;
		case GTR:
			quaterList.push_back(Quaternary("BLE", exprSym1.name, exprSym2.name, label));
			break;
		case GEQ:
			quaterList.push_back(Quaternary("BLT", exprSym1.name, exprSym2.name, label));
			break;
		case NEQ:
			quaterList.push_back(Quaternary("BEQ", exprSym1.name, exprSym2.name, label));
			break;
		case EQEQ:
			quaterList.push_back(Quaternary("BNE", exprSym1.name, exprSym2.name, label));
			break;
		default:
			break;
		}
	}
	else {
		SymbolItem symTemp0;
		symTemp0.name = genVar();
		symTemp0.type = INTTP;
		symTab.insert(symTemp0.name, VARKD, INTTP, 0);
		quaterList.push_back(Quaternary("LI", to_string(0), "", symTemp0.name));
		quaterList.push_back(Quaternary("BEQ", exprSym1.name, symTemp0.name, label));
	}

 	cout << setw(4) << left << lexer.lineNum<< "This is a condition" << endl;
}


/*
<ѭ�����>   ::=  do<���>while ��(��<����>��)��
*/
void Parser::whileState() {
	string label1, label2, label3;
	label1 = genLab();
	label2 = genLab();
	label3 = genLab();
	if (curToken.type != DO) {
		error(UNKNOWN, lexer.lineNum);
	}
	
	quaterList.push_back(Quaternary("LAB", "", "", label2));

	getToken();
	statement();

	quaterList.push_back(Quaternary("LAB", "", "", label1));
	if (curToken.type != WHILE) {
		error(MISSING_WHIL, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	condition(label3);
	if (curToken.type != RPAR) {
		error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
	}

	quaterList.push_back(Quaternary("JUMP", "", "", label2));
	quaterList.push_back(Quaternary("LAB", "", "", label3));

	getToken();
	
	cout << setw(4) << left << lexer.lineNum<< "This is a while statement" << endl;
}


/*
<������>  ::=  switch ��(��<���ʽ>��)�� ��{��<�����><ȱʡ> ��}��
<�����>   ::=  <��������>{<��������>}
<ȱʡ>   ::=  default : <���>
*/
void Parser::switchState() {
	SymbolItem exprSym;
	string labelEnd;
	labelEnd = genLab();

	if (curToken.type != SWITCH) {
		error(UNKNOWN, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	exprSym  = expression();
	if (curToken.type != RPAR) {
		error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	//�����
	if (curToken.type == LBRA) {
		getToken();
		while (curToken.type == CASE) {
			caseState(exprSym, labelEnd);
		}

		//ȱʡ
		if (curToken.type != DEFAULT) {
			error(UNKNOWN, lexer.lineNum);
		}
		getToken();
		if (curToken.type != COLON) {
			error(MISSING_COLO, lexer.lineNum);
		}
		getToken();
		statement();
		if (curToken.type != RBRA) {
			error(MISSING_RIGHT_BRACE, lexer.lineNum);
		}
		else {

			quaterList.push_back(Quaternary("LAB", "", "", labelEnd));
			getToken();
		} 
	}
	cout << setw(4) << left << lexer.lineNum<< "This is a switch statement" << endl;
}


/*
<��������>  ::=  case<����>��<���>
<����>   ::=  <����>|<�ַ�>
*/
void Parser::caseState(SymbolItem exprSym, string lableEnd) {
	string label;
	SymbolItem constSym;
	constSym.name = genVar();
	label = genLab();

	if (curToken.type == CASE) {
		getToken();
		if (curToken.type == SIGCHAR) {
			symTab.insert(constSym.name, VARKD, CHARTP, curToken.str[0]);
			quaterList.push_back(Quaternary("LI", to_string(curToken.str[0]), "", constSym.name));

			getToken();
		}
		else {
			value = intNum();

			symTab.insert(constSym.name, VARKD, INTTP, value);
			quaterList.push_back(Quaternary("LI", to_string(value), "", constSym.name));
		}


		if (curToken.type == COLON) {
			quaterList.push_back(Quaternary("BNE", exprSym.name, constSym.name, label));
			
			getToken();
			statement();
		}
		else {
			error(MISSING_COLO, lexer.lineNum);
		}

		quaterList.push_back(Quaternary("JUMP", "", "", lableEnd));
		quaterList.push_back(Quaternary("LAB", "", "", label));
	}
}


/*
<�з���ֵ�����������> ::= <��ʶ��>��(��<ֵ������>��)��|<��ʶ��> 
//��һ��ѡ��Ϊ�в�����������ڶ���ѡ��Ϊ�޲��������
*/
SymbolItem Parser::funcWithValState() {//TODO:����ֵ����û��ȷ�������ϲ�ȷ����
	SymbolItem retValSym;
	string idName;
	retValSym.name = genVar();
	retValSym.type = INTTP;

	if (curToken.type != ID) {
		error(MISSING_IDEN, lexer.lineNum);
	}

	idName = curToken.str;
	getToken();
	if (curToken.type == LPAR) {
		getToken();
		valParaTab();
		if (curToken.type == RPAR) {
			getToken();
		}
		else {
			error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
		}
	}

	quaterList.push_back(Quaternary("CALL", "", "", idName));

	cout << setw(4) << left << lexer.lineNum<< "This is a function call statement with return value " << endl;
	return retValSym;
}


/*
<�޷���ֵ�����������> ::= <��ʶ��>��(��<ֵ������>��)��|<��ʶ��> //��һ��ѡ��Ϊ�в�����������ڶ���ѡ��Ϊ�޲��������
*/
void Parser::funcWithNoValState() {
	string idName;

	if (curToken.type != ID) {
		error(MISSING_IDEN, lexer.lineNum);
	}

	idName = curToken.str;
	getToken();
	if (curToken.type == LPAR) {
		getToken();
		valParaTab();
		if (curToken.type == RPAR) {
			getToken();
		}
		else {
			error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
		}
	}

	quaterList.push_back(Quaternary("CALL", "", "", idName));
	cout << setw(4) << left << lexer.lineNum<< "This is a function call statement without return value " << endl;
}


/*
<ֵ������>   ::= <���ʽ>{,<���ʽ>}
*/
void Parser::valParaTab() {	//TODO:����������
	SymbolItem valParaSym;
	valParaSym = expression();
	quaterList.push_back(Quaternary("PUSH", "", "", valParaSym.name));

	while (curToken.type == COMMA) {
		getToken();
		valParaSym = expression();
		quaterList.push_back(Quaternary("PUSH", "", "", valParaSym.name));
	}
	
	cout << setw(4) << left << lexer.lineNum<< "This is a value parameter table" << endl;
}


/*
<��ֵ���>   ::=  <��ʶ��>��<���ʽ>|<��ʶ��>��[��<���ʽ>��]��=<���ʽ>
*/
void Parser::assignState() {
	SymbolItem exprSym, arrayIndex;
	if (curToken.type != ID) {
		error(MISSING_IDEN, lexer.lineNum);
	}

	string idName = curToken.str;

	getToken();
	if (curToken.type == EQU) {
		getToken();
		exprSym = expression();

		quaterList.push_back(Quaternary("LVAR", exprSym.name, "", idName));
	}
	else if (curToken.type == LBRK) {
		getToken();
		arrayIndex = expression();
		if (curToken.type != RBRK) {
			error(MISSING_RIGHT_BRACKET, lexer.lineNum);
		}
		getToken();
		if (curToken.type != EQU) {
			error(MISSING_EQUAL_SIGN, lexer.lineNum);
		}
		getToken();
		exprSym = expression();

		quaterList.push_back(Quaternary("SARY", idName, arrayIndex.name, exprSym.name));
	}
	else {
		error(0, lexer.lineNum);
	}
	
	cout << setw(4) << left << lexer.lineNum<< "This is a assign statement" << endl;
}


/*
<�����>    ::=  scanf ��(��<��ʶ��>{,<��ʶ��>}��)��
*/
void Parser::scanfState() {
	if (curToken.type != SCANF) {
		error(UNKNOWN, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	if (curToken.type != ID) {
		error(MISSING_IDEN, lexer.lineNum);
	}
	
	quaterList.push_back(Quaternary("READ", "", "", curToken.str));
	getToken();
	while (curToken.type == COMMA) {
		getToken();
		if (curToken.type == ID) {
			quaterList.push_back(Quaternary("READ", "", "", curToken.str));

			getToken();
		}
		else {
			error(MISSING_IDEN, lexer.lineNum);
		}
	}
	if (curToken.type != RPAR) {
		error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
	}
	getToken();

	cout << setw(4) << left << lexer.lineNum<< "This is a scanf statement" << endl;
}


/*
<д���>    ::=  printf��(��<�ַ���>,<���ʽ>��)��|printf ��(��<�ַ���>��)��|printf ��(��<���ʽ>��)��
*/
void Parser::printfState() {
	SymbolItem exprSym;
	if (curToken.type != PRINTF) {
		error(UNKNOWN, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	if (curToken.type == STRING) {
		int indexStr = insertString(curToken.str);

		getToken();
		if (curToken.type == COMMA) {
			getToken();
			exprSym = expression();
			quaterList.push_back(Quaternary("PRT", "2", to_string(indexStr), exprSym.name));
		}
		else {
			quaterList.push_back(Quaternary("PRT", "1", "", to_string(indexStr)));
		}
	}
	else {
		exprSym = expression();
		quaterList.push_back(Quaternary("PRT", "0", "", exprSym.name));
	}

	if (curToken.type != RPAR) {
		error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
	}
	getToken();

	cout << setw(4) << left << lexer.lineNum<< "This is a printf statement" << endl;
}


/*
<�������>   ::=  return[��(��<���ʽ>��)��]
*/
void Parser::returnState() {
	SymbolItem retValSym;
	if (curToken.type != RETURN) {
		error(MISSING_RETU, lexer.lineNum);
	}
	getToken();
	if (curToken.type == LPAR) {
		getToken();
		retValSym = expression();

		if (curToken.type == RPAR) {
			getToken();
			quaterList.push_back(Quaternary("RET", "", "", retValSym.name));
		}
		else {
			error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
		}
	}
	else {		//return;��return
		quaterList.push_back(Quaternary("REN", "", "", ""));
	}
	retFlag = true;
	cout << setw(4) << left << lexer.lineNum  << "This is a return statement" << endl;
}


void printQuater(string path) {
	ofstream fout;
	fout.open(path);
	//fout << "\nThis is quaternary list " << endl;
	for (int i = 0; i < quaterList.size(); i++) {
		Quaternary quater = quaterList[i];
		fout << setw(10) << left << quater.oper;
		fout << setw(10) << left << quater.op1;
		fout << setw(10) << left << quater.op2;
		fout << setw(10) << left << quater.res << endl;
	}
}


void parser_test() {
	Parser parser;
	string path;
	path = "./in/in1.c";
	//cin >> path;
	if (_access(path.data(), 0) == -1) {
		cout << "File doesn't exist!" << endl;
		return;
	}
	parser.lexer.fin.open(path, ios::in | ios::binary);
	parser.lexer.fout.open("./out/out.txt");
	parser.program();
	if (parser.lexer.ecount > 1)
		cout << "Compile failed!" << endl;
	else
		cout << "Compiled successfully" << endl;
}