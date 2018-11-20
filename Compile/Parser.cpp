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

//�����������⣬ÿ���ӳ���ε����һ����getToken()
/*
<����>    :: = ��<����˵��>�ݣ�<����˵��>��{ <�з���ֵ��������> | <�޷���ֵ��������> }<������>
<����˵��> first set = {const}
<����˵��> first set = {int, char}
<�з���ֵ��������> first set = {int, char}
<�޷���ֵ��������> first set = {void}
<������> first set ={void}
*/
void Parser::program() {
	getToken();

	//����˵��
	if (curToken.type == CONST) {
		getToken();
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
				varDecl();
			}
			//�з���ֵ�������壬token���ݵ���ʶ��λ��
			else if (curToken.type == LPAR) {
				pushToken(curToken);	//�˴������д���������һ��
				getToken();
			}
		}
	}
	
	//{ <�з���ֵ��������> | <�޷���ֵ��������> }
	while (curToken.type == INT || curToken.type == CHAR || curToken.type == VOID) {
		//�з���ֵ����
		if (curToken.type == INT || curToken.type == CHAR) {
			pushToken(curToken);
			getToken();
			if (curToken.type == ID) {
				pushToken(curToken);;
				getToken();
				if()
			}
		}
		//�޷���ֵ������main����
		else {
			pushToken(curToken);
			getToken();
			//main������token���ݵ�void
			if (curToken.type == MAIN) {
				pushToken(curToken);
				break;
			}
			//�޷���ֵ����
			else if (curToken.type == ID) {
				pushToken(curToken);
				funcWithNoVal();
			}
			else {
				//error
			}
		}
	}

	//main����

	
	
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