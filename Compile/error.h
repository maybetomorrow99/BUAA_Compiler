#pragma once
#include "stdafx.h"

#define UNKNOWN						0
#define MISSING_SIN_QUOTE           1
#define MISSING_DOU_QUOTES          2
#define CHAR_ERROR                  3
#define EXCL_MARK_ERROR             4
#define INVALID_SYMBOL              5
#define STRING_TOO_LONG             6
#define NUM_TOO_LARGE               7
#define MISSING_SEMI                8
#define MISSING_IDEN                9
#define MISSING_EQUAL_SIGN          10
#define MISSING_CHAR                11
#define MISSING_TYPE				12
#define MISSING_RIGHT_PARENTHESIS   13
#define MISSING_RIGHT_BRACKET       14
#define MISSING_RIGHT_BRACE         15
#define MISSING_LEFT_PARENTHESIS    16
#define MISSING_LEFT_BRACKET        17
#define MISSING_LEFT_BRACE          18
#define MISSING_MAIN                19
#define MISSING_ELSE                20
#define MISSING_CONS                21
#define MISSING_OPER                22
#define MISSING_LETT                23
#define MISSING_CASE                24
#define MISSING_COLO                25
#define MISSING_WHIL                26
#define MISSING_RETU                27
#define EXPRESSION_ERRO             28
#define IDENT_NOT_DEF               29
#define IDENT_REDEF                 30
#define IDENT_TOO_LONG              31
#define MISSING_RET_VAL				32
#define PARA_TYP_NOT_MATCH		    33
#define PARA_NUM_NOT_MATCH          34
#define RETURN_VALUE_ERROR          35
#define CONSTANT_NOT_INITIALIZED    36
#define VARIABLE_NOT_INITIALIZED    37
#define SYMBOL_TABLE_OVERFLOW       38
#define ARRAY_OVER                  39
#define CASE_CONST_REPEAT			40
#define ARRAY_INDEX_NOT_INT			41
#define ASSIGN_TYPE_DIFF			42
#define EXPR_IN_CONDITION_NOT_INT	43
#define CASE_CONST_DIFF				44
#define ASSIGN_CONST				45
#define MISSING_INTEGER				46
#define FUNC_WITH_PARE				47
#define MISSING_DEFAULT				48
#define STATEMENT_ERROR				49
extern int errcount;

void error(int errid, int lineNum);
