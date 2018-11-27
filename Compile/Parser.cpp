#include "parser.h"

using namespace std;

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

		getToken();
		if (curToken.type != EQU) {
			error(MISSING_EQUAL_SIGN, lexer.lineNum);
		}

		getToken();
		intNum();

		while (curToken.type == COMMA) {
			getToken();
			if (curToken.type != ID) {
				error(MISSING_IDEN, lexer.lineNum);
			}

			getToken();
			if (curToken.type != EQU) {
				error(MISSING_EQUAL_SIGN, lexer.lineNum);
			}

			getToken();
			intNum();
		}							
	}
	else if (curToken.type == CHAR) {

		getToken();
		if (curToken.type != ID) {
			//error
			error(MISSING_IDEN, lexer.lineNum);
		}

		getToken();
		if (curToken.type != EQU) {
			error(MISSING_EQUAL_SIGN, lexer.lineNum);
		}
		getToken();
		if (curToken.type != SIGCHAR) {
			error(MISSING_CHAR, lexer.lineNum);
		}

		getToken();
		while (curToken.type == COMMA) {
			getToken();
			if (curToken.type != ID) {
				//error
				error(MISSING_IDEN, lexer.lineNum);
			}

			getToken();
			if (curToken.type != EQU) {
				error(MISSING_EQUAL_SIGN, lexer.lineNum);
			}

			getToken();
			if (curToken.type != SIGCHAR) {
				error(MISSING_CHAR, lexer.lineNum);
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
		getToken();
		if (curToken.type != ID) {
			error(MISSING_IDEN, lexer.lineNum);
		}
		getToken();
		if (curToken.type == LBRK) {
			getToken();
			if (curToken.type == NUM) {
				getToken();
				if (curToken.type == RBRK) {
					getToken();
				}
			}
		}

		while (curToken.type == COMMA) {
			getToken();
			if (curToken.type != ID) {
				//error
				error(MISSING_IDEN, lexer.lineNum);
			}
			getToken();
			if (curToken.type == LBRK) {
				getToken();
				if (curToken.type == NUM) {
					getToken();
					if (curToken.type == RBRK) {
						getToken();
					}
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
	//����ͷ��
	SymbolType type;
	string name;
	if (curToken.type == INT || curToken.type == CHAR) {

		if (curToken.type == INT)
			type = INTTP;
		else
			type = CHARTP;

		getToken();
		if (curToken.type == ID) {

			name = curToken.str;

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
		getToken();
		paraTab();
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

		symTab.insert(name, FUNCKD, type, 0, 1);

		getToken();
	}
	else if (curToken.type == LBRA) {	//�޲���

		getToken();
		compState();
		if (curToken.type != RBRA) {
			error(MISSING_LEFT_BRACE, lexer.lineNum);
		}

		symTab.insert(name, FUNCKD, type, 0, 0);

		getToken();
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}

	cout << setw(4) << left << lexer.lineNum<< "This is a function definition with return value" << endl;
}

/*
<�޷���ֵ��������>  ::= void<��ʶ��>(��<������>��)����{��<�������>��}��| void<��ʶ��>{��<�������>��}��
//��һ��ѡ��Ϊ�в�����������ڶ���ѡ��Ϊ�޲��������
*/
void Parser::funcWithNoVal() {
	SymbolType type;
	string name;

	if (curToken.type != VOID) {
		error(UNKNOWN, lexer.lineNum);
	}

	type = VOIDTP;

	getToken();
	if (curToken.type != ID) {
		error(MISSING_IDEN, lexer.lineNum);
	}

	name = curToken.str;

	getToken();
	if (curToken.type == LPAR) {	//�в���
		getToken();
		paraTab();
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

		symTab.insert(name, FUNCKD, type, 0, 1);

		getToken();
	}
	else if (curToken.type == LBRA) {	//�޲���
		getToken();
		compState();
		if (curToken.type != RBRA) {
			error(MISSING_RIGHT_BRACE, lexer.lineNum);
		}

		symTab.insert(name, FUNCKD, type, 0, 0);

		getToken();
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}

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
	compState();
	if (curToken.type != RBRA) {
		error(MISSING_LEFT_BRACE, lexer.lineNum);
	}

	cout << setw(4) << left << lexer.lineNum<< "This is main function" << endl;
}

/*
<����>        ::= �ۣ�������<�޷�������>
*/
void Parser::intNum() {
	if (curToken.type == PLUS || curToken.type == MINUS) {
		getToken();
	}
	if (curToken.type == NUM) {
		getToken();
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}
	//cout << setw(4) << left << lexer.lineNum<< "This is a integer" << endl;
}

/*
<���ʽ>    ::= �ۣ�������<��>{<�ӷ������><��>}  
//[+|-]ֻ�����ڵ�һ��<��>
*/
void Parser::expression() {
	if (curToken.type == PLUS || curToken.type == MINUS) {
		getToken();
	}
	item();
	while (curToken.type == PLUS || curToken.type == MINUS) {
		getToken();
		item();
	}
	
	cout << setw(4) << left << lexer.lineNum<< "This is an expression" << endl;
}

/*
<��>     ::= <����>{<�˷������><����>}
*/
void Parser::item() {
	factor();
	while (curToken.type == MULT || curToken.type == DIV) {
		getToken();
		factor();
	}

	cout << setw(4) << left << lexer.lineNum<< "This is a item" << endl;
}

/*
<����>    ::= <��ʶ��>��<��ʶ��>��[��<���ʽ>��]����<����>|<�ַ�>��<�з���ֵ�����������>|��(��<���ʽ>��)��
*/
void Parser::factor() {
	//<��ʶ��>��<��ʶ��>��[��<���ʽ>��]��|<�з���ֵ�����������>
	string name;
	if (curToken.type == ID) { //***���޸�
		pushToken(curToken);

		name = curToken.str;

		getToken();
		if (curToken.type == LBRK) {		//<��ʶ��>��[��<���ʽ>��]��
			clearToken();
			getToken();
			expression();
			if (curToken.type == RBRK) {
				getToken();
			}
			else {
				error(MISSING_RIGHT_BRACKET, lexer.lineNum);
			}
		}
		else if (curToken.type == LPAR) {	//<�з���ֵ�����������>�в���
			pushToken(curToken);
			retract();
			getToken();
			funcWithValState();
		}
		else if (symTab.isFunc(name, INTTP) || symTab.isFunc(name, CHARTP)) {	//<�з���ֵ�����������>�޲���������Ǻ���������Ҫ����
			pushToken(curToken);
			retract();
			getToken();
			funcWithValState();
		}
		else {					//<��ʶ��>
			clearToken();
			//getToken();
		}

	}
	//����
	else if (curToken.type == PLUS || curToken.type == MINUS || curToken.type == NUM) {
		intNum();
	}
	else if (curToken.type == SIGCHAR) {
		getToken();
	}
	else if (curToken.type == LPAR) {
		getToken();
		expression();
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
}

/*
<������>    ::=  <���ͱ�ʶ��><��ʶ��>{,<���ͱ�ʶ��><��ʶ��>}
*/
void Parser::paraTab() {
	if (curToken.type == INT || curToken.type == CHAR) {
		getToken();
		if (curToken.type == ID) {
			getToken();
		}
		else {
			error(MISSING_IDEN, lexer.lineNum);
		}
	}
	while (curToken.type == COMMA) {
		getToken();
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

		if (curToken.type == LPAR) {	//���������в��������޸�
			pushToken(curToken);
			retract();
			getToken();
			if (symTab.isFunc(name, VOIDTP))
				funcWithNoValState();
			else
				funcWithValState();
		}
		else {
			//��ֵ�����޷���ֵ�޲�������������䣬���޸�*****
			pushToken(curToken);
			retract();
			getToken();
			if (symTab.isFunc(name, VOIDTP))
				funcWithNoValState();
			else if (symTab.isFunc(name, INTTP) || symTab.isFunc(name, CHARTP))
				funcWithValState();
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
	if (curToken.type != IF) {
		error(UNKNOWN, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	condition();
	if (curToken.type != RPAR) {
		error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	statement();
	if (curToken.type != ELSE) {
		error(MISSING_ELSE, lexer.lineNum);
	}
	getToken();
	statement();

	cout << setw(4) << left << lexer.lineNum<< "This is a if statement" << endl;
}

/*
<����>    ::=  <���ʽ><��ϵ�����><���ʽ>��<���ʽ> //���ʽΪ0����Ϊ�٣�����Ϊ��
*/
void Parser::condition() {
	expression();
	if (curToken.type == LSS || curToken.type == LEQ || curToken.type == GTR ||
		curToken.type == GEQ || curToken.type == NEQ || curToken.type == EQEQ) {
		getToken();
		expression();
	}

 	cout << setw(4) << left << lexer.lineNum<< "This is a condition" << endl;
}

/*
<ѭ�����>   ::=  do<���>while ��(��<����>��)��
*/
void Parser::whileState() {
	if (curToken.type != DO) {
		error(UNKNOWN, lexer.lineNum);
	}
	getToken();
	statement();
	if (curToken.type != WHILE) {
		error(MISSING_WHIL, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	condition();
	if (curToken.type != RPAR) {
		error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	
	cout << setw(4) << left << lexer.lineNum<< "This is a while statement" << endl;
}

/*
<������>  ::=  switch ��(��<���ʽ>��)�� ��{��<�����><ȱʡ> ��}��
<�����>   ::=  <��������>{<��������>}
<ȱʡ>   ::=  default : <���>
*/
void Parser::switchState() {
	if (curToken.type != SWITCH) {
		error(UNKNOWN, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	expression();
	if (curToken.type != RPAR) {
		error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	//�����
	if (curToken.type == LBRA) {
		getToken();
		while (curToken.type == CASE) {
			caseState();
		}
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
			getToken();
		}
	}
	cout << setw(4) << left << lexer.lineNum<< "This is a switch statement" << endl;
}

/*
<��������>  ::=  case<����>��<���>
<����>   ::=  <����>|<�ַ�>
*/
void Parser::caseState() {
	if (curToken.type == CASE) {
		getToken();
		if (curToken.type == SIGCHAR) {
			getToken();
		}
		else {
			intNum();
		}

		if (curToken.type == COLON) {
			getToken();
			statement();
		}
		else {
			error(MISSING_COLO, lexer.lineNum);
		}
	}
}

/*
<�з���ֵ�����������> ::= <��ʶ��>��(��<ֵ������>��)��|<��ʶ��> //��һ��ѡ��Ϊ�в�����������ڶ���ѡ��Ϊ�޲��������
*/
void Parser::funcWithValState() {
	if (curToken.type != ID) {
		error(MISSING_IDEN, lexer.lineNum);
	}
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
	cout << setw(4) << left << lexer.lineNum<< "This is a function call statement with return value " << endl;
}

/*
<�޷���ֵ�����������> ::= <��ʶ��>��(��<ֵ������>��)��|<��ʶ��> //��һ��ѡ��Ϊ�в�����������ڶ���ѡ��Ϊ�޲��������
*/
void Parser::funcWithNoValState() {
	if (curToken.type != ID) {
		error(MISSING_IDEN, lexer.lineNum);
	}
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
	cout << setw(4) << left << lexer.lineNum<< "This is a function call statement without return value " << endl;
}

/*
<ֵ������>   ::= <���ʽ>{,<���ʽ>}
*/
void Parser::valParaTab() {
	expression();
	while (curToken.type == COMMA) {
		getToken();
		expression();
	}
	
	cout << setw(4) << left << lexer.lineNum<< "This is a value parameter table" << endl;
}

/*
<��ֵ���>   ::=  <��ʶ��>��<���ʽ>|<��ʶ��>��[��<���ʽ>��]��=<���ʽ>
*/
void Parser::assignState() {
	if (curToken.type != ID) {
		error(MISSING_IDEN, lexer.lineNum);
	}
	getToken();
	if (curToken.type == EQU) {
		getToken();
		expression();
	}
	else if (curToken.type == LBRK) {
		getToken();
		expression();
		if (curToken.type != RBRK) {
			error(MISSING_RIGHT_BRACKET, lexer.lineNum);
		}
		getToken();
		if (curToken.type != EQU) {
			error(MISSING_EQUAL_SIGN, lexer.lineNum);
		}
		getToken();
		expression();
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
	getToken();
	while (curToken.type == COMMA) {
		getToken();
		if (curToken.type == ID) {
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
	if (curToken.type != PRINTF) {
		error(UNKNOWN, lexer.lineNum);
	}
	getToken();
	if (curToken.type != LPAR) {
		error(MISSING_LEFT_PARENTHESIS, lexer.lineNum);
	}
	getToken();
	if (curToken.type == STRING) {
		getToken();
		if (curToken.type == COMMA) {
			getToken();
			expression();
		}
	}
	else {
		expression();
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
	if (curToken.type != RETURN) {
		error(MISSING_RETU, lexer.lineNum);
	}
	getToken();
	if (curToken.type == LPAR) {
		getToken();
		expression();
		if (curToken.type == RPAR) {
			getToken();
		}
		else {
			error(MISSING_RIGHT_PARENTHESIS, lexer.lineNum);
		}
	}

	cout << setw(4) << left << lexer.lineNum  << "This is a return statement" << endl;
}

void parser_test() {
	Parser parser;
	string path;
	//path = "./in/in3.c";
	cin >> path;
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