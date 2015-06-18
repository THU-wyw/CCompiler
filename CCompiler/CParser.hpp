/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_CPARSER_HPP_INCLUDED
# define YY_YY_CPARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 12 "CParser.y"

	#include <vector>
	#include "SyntaxNode.h"
	using namespace std;


/* Line 2058 of yacc.c  */
#line 53 "CParser.hpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING_LITERAL = 259,
     IMMEDIATE_INTEGER = 260,
     INC_OP = 261,
     DEC_OP = 262,
     PTR_OP = 263,
     SHIFT_LEFT_OP = 264,
     SHIFT_RIGHT_OP = 265,
     LE_OP = 266,
     GE_OP = 267,
     EQ_OP = 268,
     NE_OP = 269,
     AND_OP = 270,
     OR_OP = 271,
     ADD_ASSIGN = 272,
     SUB_ASSIGN = 273,
     MUL_ASSIGN = 274,
     DIV_ASSIGN = 275,
     MOD_ASSIGN = 276,
     SHIFT_LEFT_ASSIGN = 277,
     SHIFT_RIGHT_ASSIGN = 278,
     AND_ASSIGN = 279,
     INCLUSIVE_OR_ASSIGN = 280,
     EXCLUSIVE_OR_ASSIGN = 281,
     CASE = 282,
     DEFAULT = 283,
     IF = 284,
     ELSE = 285,
     SWITCH = 286,
     WHILE = 287,
     DO = 288,
     FOR = 289,
     CONTINUE = 290,
     BREAK = 291,
     RETURN = 292,
     CHAR = 293,
     INT = 294,
     FLOAT = 295,
     CONST = 296,
     VOID = 297
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 18 "CParser.y"

	SyntaxNode* node;
	Program* program;
	Expression* expression;
	Identifier* identifier;
	vector<Identifier*>* identifier_list;
	ImmediateInteger* immediate_integer;
	StringLiteral* string_literal;
	UnaryExpression* unary_expression;
	BinaryExpression* binary_expression;
	vector<Expression*>* expression_list;
	FunctionCall* function_call;
	AssignmentExpression* assignment_expression;
	Statement* statement;
	Declaration* declaration;
	vector<Declaration*>* declaration_list;
	VariableDeclaration* variable_declaration;
	vector<VariableDeclaration*>* variable_declaration_list;
	StatementsBlock* statements_block;
	IfStatement* if_statement;
	WhileStatement* while_statement;
	ExpressionStatement* expression_statement;
	FunctionDeclaration* function_declaration;
	FunctionDefinition* function_definition;
	string* str;
	int number;
	char symbol;
	VariableType::Type vt_t;


/* Line 2058 of yacc.c  */
#line 141 "CParser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_CPARSER_HPP_INCLUDED  */
