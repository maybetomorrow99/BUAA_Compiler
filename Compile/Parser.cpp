#include "parser.h"



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
	tokens.push(t);
}

//除了主程序外，每个子程序段的最后一定是getToken()
/*
<程序>    :: = ［<常量说明>］［<变量说明>］{ <有返回值函数定义> | <无返回值函数定义> }<主函数>
<常量说明> first set = {const}
<变量说明> first set = {int, char}
<有返回值函数定义> first set = {int, char}
<无返回值函数定义> first set = {void}
<主函数> first set ={void}
*/
void Parser::program() {
	getToken();

	//常量说明
	if (curToken.type == CONST) {
		getToken();
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
				varDecl();
			}
			//有返回值函数定义，token回溯到标识符位置
			else if (curToken.type == LPAR) {
				pushToken(curToken);	//此处不进行处理，进入下一步
				getToken();
			}
		}
	}
	
	//{ <有返回值函数定义> | <无返回值函数定义> }
	while (curToken.type == INT || curToken.type == CHAR || curToken.type == VOID) {
		//有返回值函数
		if (curToken.type == INT || curToken.type == CHAR) {
			pushToken(curToken);
			getToken();
			if (curToken.type == ID) {
				pushToken(curToken);;
				getToken();
				if()
			}
		}
		//无返回值函数或main函数
		else {
			pushToken(curToken);
			getToken();
			//main函数，token回溯到void
			if (curToken.type == MAIN) {
				pushToken(curToken);
				break;
			}
			//无返回值函数
			else if (curToken.type == ID) {
				pushToken(curToken);
				funcWithNoVal();
			}
			else {
				//error
			}
		}
	}

	//main函数

	
	
}

void Parser::constDecl() {

}

void Parser::constDef() {

}

void Parser::varDecl() {

}

void Parser::varDef() {

}

void Parser::funcWithVal() {

}

void Parser::funcWithNoVal() {

}

void Parser::mainFunc() {

}

void Parser::expression() {

}

void Parser::item() {

}

void Parser::factor() {

}

void Parser::declHeader() {

}

void Parser::paraTab() {

}

void Parser::compState() {

}

void Parser::stateCol() {

}

void Parser::statement() {

}

void Parser::ifState() {

}

void Parser::whileState() {

}

void Parser::switchState() {

}

void Parser::caseState() {

}

void Parser::funcWithValState() {

}

void Parser::funcWithNoValState() {

}

void Parser::varParaTab() {

}

void Parser::assignState() {

}

void Parser::scanfState() {

}

void Parser::printfState() {

}

void Parser::returnState() {

}

void parser_test() {
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