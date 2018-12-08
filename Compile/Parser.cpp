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
生成变量名
*/
string Parser::genVar() {
	string s = "$temp" + to_string(tempIndex++);
	return s;
}


/*
生成标签
*/
string Parser::genLab() {
	string s = "$label" + to_string(labelIndex++);
	return s;
}


/*
插入常量池中，返回值为对应的字符串
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


//除了主程序外，每个子程序段的最后一定是getToken()
/*
<程序>    :: = ［<常量说明>］［<变量说明>］{ <有返回值函数定义> | <无返回值函数定义> }<主函数>
<常量说明> first = {const}
<变量说明> first = {int, char}
<有返回值函数定义> first = {int, char}
<无返回值函数定义> first = {void}
<主函数> first ={void}
*/
void Parser::program() {
	getToken();

	//常量说明
	if (curToken.type == CONST) {
		constDecl();
	}

	//变量说明或有返回值函数定义
	if (curToken.type == INT || curToken.type == CHAR) {
		pushToken(curToken);
		getToken();
		if (curToken.type == ID) {
			pushToken(curToken);
			getToken();
			//变量说明，token回溯到标识符位置
			if (curToken.type == COMMA || curToken.type == SEMI || curToken.type == LBRK) {
				pushToken(curToken);
				retract();
				getToken();
				varDecl();
			}
			//有返回值函数定义，token回溯到标识符位置
			else if (curToken.type == LPAR || curToken.type == LBRA) {
				pushToken(curToken);	//此处不进行处理，进入下一步
				retract();
				getToken();
			}
		}
		else {
			error(UNKNOWN, lexer.lineNum);
		}
	}
	
	//{ <有返回值函数定义> | <无返回值函数定义> }
	while (curToken.type == INT || curToken.type == CHAR || curToken.type == VOID) {
		//有返回值函数
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
					//int f后没有括号
					error(0, lexer.lineNum);
				}
			}
			else {
				error(MISSING_IDEN, lexer.lineNum);
			}
		}
		//无返回值函数或main函数
		else {
			pushToken(curToken);
			getToken();
			//main函数，token回溯到void
			if (curToken.type == MAIN) {
				pushToken(curToken);
				retract();
				getToken();
				break;
			}
			//无返回值函数
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

	//main函数
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
<常量说明> ::=  const<常量定义>;{ const<常量定义>;}
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
<常量定义>   ::=   int<标识符>＝<整数>{,<标识符>＝<整数>}
				| char<标识符>＝<字符>{,<标识符>＝<字符>}
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
<变量说明>  ::= <变量定义>;{<变量定义>;}
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
				//有返回值函数定义，token回溯到标识符位置
				else if (curToken.type == LPAR || curToken.type == LBRA) {
					pushToken(curToken);	//此处不进行处理，进入下一步
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
<变量定义>  ::= <类型标识符>(<标识符>|<标识符>‘[’<无符号整数>‘]’){,(<标识符>|<标识符>‘[’<无符号整数>‘]’) } 
//<无符号整数>表示数组元素的个数，其值需大于0
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
		else {	//此处未进行错误处理，直接插入符号表
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
<有返回值函数定义>  ::=  <声明头部>‘(’<参数表>‘)’ ‘{’<复合语句>‘}’|<声明头部>‘{’<复合语句>‘}’
<声明头部>   ::=  int<标识符>|char<标识符>
//第一种选择为有参数的情况，第二种选择为无参数的情况
*/
void Parser::funcWithVal() {
	retFlag = false;
	//声明头部
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

	if (curToken.type == LPAR) {	//有参数
		if (!symTab.inTable(name)) {
			symTab.insert(name, FUNCKD, type, 0);
			quaterList.push_back(Quaternary("FUNC", (type == INTTP ? "int" : "char"), "", name));
		}
		else {
			error(IDENT_REDEF, lexer.lineNum);
		}

		getToken();
		paraTab();	//参数表中记录了参数个数
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
	else if (curToken.type == LBRA) {	//无参数
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
<无返回值函数定义>  ::= void<标识符>(’<参数表>‘)’‘{’<复合语句>‘}’| void<标识符>{’<复合语句>‘}’
//第一种选择为有参数的情况，第二种选择为无参数的情况
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
	if (curToken.type == LPAR) {	//有参数
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
	else if (curToken.type == LBRA) {	//无参数
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

	//默认在无返回值函数的最后加上return;
	quaterList.push_back(Quaternary("REN", "", "", ""));
	symTab.updateFuncVal();

	cout << setw(4) << left << lexer.lineNum<< "This is a function definition without return value" << endl;
}


/*
<声明头部>   ::=  int<标识符>|char<标识符>
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
<主函数>    ::= void main‘(’‘)’ ‘{’<复合语句>‘}’
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
<整数>        ::= ［＋｜－］<无符号整数>
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
<表达式>    ::= ［＋｜－］<项>{<加法运算符><项>}  
[+|-]只作用于第一个<项>
返回值为一个新的变量
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
<项>     ::= <因子>{<乘法运算符><因子>}
*/
SymbolItem Parser::item() {
	SymbolItem factorSym1, factorSym2;
	factorSym1 = factor();
	while (curToken.type == MULT || curToken.type == DIV) {
		int sign = curToken.type;
		getToken();
		factorSym2 = factor();

		//进行一次运算
		if (sign == MULT)
			quaterList.push_back(Quaternary("MUL", factorSym1.name, factorSym2.name, factorSym1.name));
		else
			quaterList.push_back(Quaternary("DIV", factorSym1.name, factorSym2.name, factorSym1.name));

		//参与运算之后类型一定为INTTP
		symTab.changeVarType(factorSym1.name);
	}

	cout << setw(4) << left << lexer.lineNum<< "This is a item" << endl;
	return factorSym1;
}


/*
<因子>    ::= <标识符>｜<标识符>‘[’<表达式>‘]’｜<整数>|<字符>｜<有返回值函数调用语句>|‘(’<表达式>‘)’
*/
SymbolItem Parser::factor() {
	//<标识符>｜<标识符>‘[’<表达式>‘]’|<有返回值函数调用语句>
	SymbolItem factorSym;
	SymbolItem arrayIndex;
	if (curToken.type == ID) { //***TODO
		pushToken(curToken);
		 
		string idName = curToken.str;
		if (!symTab.inTable(idName)) {
			error(IDENT_NOT_DEF, lexer.lineNum);
		}
		
		getToken();
		if (curToken.type == LBRK) {		//<标识符>‘[’<表达式>‘]’
			clearToken();
			getToken();

			//将数组的值放到一个新变量中
			factorSym.name = genVar();
			factorSym.type = symTab.search(idName).type;
			symTab.insert(factorSym.name, VARKD, factorSym.type, 0);
			quaterList.push_back(Quaternary("VAR", (type == INTTP ? "int" : "char"), "", factorSym.name));

			arrayIndex = expression();
			if (curToken.type == RBRK) {
				getToken();

				//取数组值
				quaterList.push_back(Quaternary("LARY", idName, arrayIndex.name, factorSym.name));
			}
			else {
				error(MISSING_RIGHT_BRACKET, lexer.lineNum);
			}
		}
		else if (curToken.type == LPAR) {	//<有返回值函数调用语句>有参数
			pushToken(curToken);
			retract();
			getToken();

			factorSym = funcWithValState();
			factorSym.type = symTab.searchFunc(idName).type;
			symTab.insert(factorSym.name, VARKD, factorSym.type, 0);

			//接受函数返回值
			quaterList.push_back(Quaternary("VOF", idName, "", factorSym.name));
		}
		else if (symTab.isFunc(idName)) {	//<有返回值函数调用语句>无参数，如果是函数，还需要回溯
			pushToken(curToken);
			retract();
			getToken();

			factorSym = funcWithValState();
			type = symTab.searchFunc(idName).type;
			symTab.insert(factorSym.name, VARKD, type, 0);

			//接受函数返回值
			quaterList.push_back(Quaternary("VOF", idName, "", factorSym.name));
		}
		else {					//<标识符>
			clearToken();
			
			factorSym.name = genVar();
			factorSym.type = symTab.search(idName).type;
			symTab.insert(factorSym.name, VARKD, factorSym.type, 0);
			quaterList.push_back(Quaternary("LVAR", idName, "", factorSym.name));
		}

	}
	//整数
	else if (curToken.type == PLUS || curToken.type == MINUS || curToken.type == NUM) {
		value = intNum();
		factorSym.name = genVar();
		factorSym.type = INTTP;
		symTab.insert(factorSym.name, VARKD, INTTP, value);
		quaterList.push_back(Quaternary("LI", to_string(value), "", factorSym.name));
	}
	else if (curToken.type == SIGCHAR) {	//字符
		factorSym.name = genVar();
		factorSym.type = CHARTP;
		symTab.insert(factorSym.name, VARKD, CHARTP, curToken.str[0]);
		quaterList.push_back(Quaternary("LI", to_string(curToken.str[0]), "", factorSym.name));
		getToken();
	}
	else if (curToken.type == LPAR) {		//表达式
		getToken();
		factorSym = expression();
		symTab.insert(factorSym.name, VARKD, INTTP, 0);	//TODO:此处可能有问题，表达式的类型不一定是整型

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
<参数表>    ::=  <类型标识符><标识符>{,<类型标识符><标识符>}
*/
void Parser::paraTab() {
	value = 0;
	if (curToken.type == INT || curToken.type == CHAR) {
		type = curToken.type == INT ? INTTP : CHARTP;

		getToken();
		if (curToken.type == ID) {
			name = curToken.str;
			value++;

			//此处应该不存在与全局变量重定义问题，参数只考虑与函数内部重名
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
<复合语句>   ::=  ［<常量说明>］［<变量说明>］<语句列>
<常量说明> first = {const}
<变量说明> first = {int, char}
<语句列> first = {if, do, {, switch, id, scanf, printf, ;, return}
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
		//语句列为空
	}
	else {
		error(UNKNOWN, lexer.lineNum);
	}
	cout << setw(4) << left << lexer.lineNum<< "This is a compound statement" << endl;
}


/*
<语句列>   ::=｛<语句>｝
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
<语句>    ::= <条件语句>｜<循环语句>| ‘{’<语句列>‘}’｜<情况语句>|<有返回值函数调用语句>;
					  |<无返回值函数调用语句>;｜<赋值语句>;｜<读语句>;｜<写语句>;｜<空>;｜<返回语句>;
<条件语句> first = {if}
<循环语句> first = {do}
‘{’<语句列>‘}’first = {'{'}
<情况语句> first = {switch}
<有返回值函数调用语句> first = {标识符}
<无返回值函数调用语句> first = {标识符}
<赋值语句> first = {标识符}
<读语句> first = {scanf}
<写语句> first = {printf}
<空>; first = {;}
<返回语句> first = {return}
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
	case ID:	//函数调用或赋值
		name = curToken.str;
		pushToken(curToken);
		getToken();

		if (curToken.type == LPAR) {	//函数调用有参数，TODO
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
			//赋值或有无返回值无参数函数调用语句，TODO*****
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
<条件语句>  ::=  if ‘(’<条件>‘)’<语句>else <语句>
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
<条件>    ::=  <表达式><关系运算符><表达式>｜<表达式> //表达式为0条件为假，否则为真
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
<循环语句>   ::=  do<语句>while ‘(’<条件>‘)’
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
<情况语句>  ::=  switch ‘(’<表达式>‘)’ ‘{’<情况表><缺省> ‘}’
<情况表>   ::=  <情况子语句>{<情况子语句>}
<缺省>   ::=  default : <语句>
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
	//情况表
	if (curToken.type == LBRA) {
		getToken();
		while (curToken.type == CASE) {
			caseState(exprSym, labelEnd);
		}

		//缺省
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
<情况子语句>  ::=  case<常量>：<语句>
<常量>   ::=  <整数>|<字符>
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
<有返回值函数调用语句> ::= <标识符>‘(’<值参数表>‘)’|<标识符> 
//第一种选择为有参数的情况，第二种选择为无参数的情况
*/
SymbolItem Parser::funcWithValState() {//TODO:返回值类型没有确定，在上层确定了
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
<无返回值函数调用语句> ::= <标识符>‘(’<值参数表>‘)’|<标识符> //第一种选择为有参数的情况，第二种选择为无参数的情况
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
<值参数表>   ::= <表达式>{,<表达式>}
*/
void Parser::valParaTab() {	//TODO:检查参数类型
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
<赋值语句>   ::=  <标识符>＝<表达式>|<标识符>‘[’<表达式>‘]’=<表达式>
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
<读语句>    ::=  scanf ‘(’<标识符>{,<标识符>}‘)’
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
<写语句>    ::=  printf‘(’<字符串>,<表达式>‘)’|printf ‘(’<字符串>‘)’|printf ‘(’<表达式>‘)’
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
<返回语句>   ::=  return[‘(’<表达式>‘)’]
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
	else {		//return;空return
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