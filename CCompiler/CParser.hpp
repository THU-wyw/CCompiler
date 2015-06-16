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

	#include "SyntaxNode.h"
	using namespace std;


/* Line 2058 of yacc.c  */
#line 52 "CParser.hpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING_LITERAL = 259,
     IMMEDIATE_INTEGER = 260,
     PTR_OP = 261,
     INC_OP = 262,
     DEC_OP = 263,
     LEFT_OP = 264,
     RIGHT_OP = 265,
     LE_OP = 266,
     GE_OP = 267,
     EQ_OP = 268,
     NE_OP = 269,
     AND_OP = 270,
     OR_OP = 271,
     ASSIGN = 272,
     ADD_ASSIGN = 273,
     SUB_ASSIGN = 274,
     MUL_ASSIGN = 275,
     DIV_ASSIGN = 276,
     CASE = 277,
     DEFAULT = 278,
     IF = 279,
     ELSE = 280,
     SWITCH = 281,
     WHILE = 282,
     DO = 283,
     FOR = 284,
     CONTINUE = 285,
     BREAK = 286,
     RETURN = 287,
     CHAR = 288,
     INT = 289,
     FLOAT = 290,
     CONST = 291,
     VOID = 292
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 16 "CParser.y"

	SyntaxNode* node;
	Expression* expression;
	Identifier* identifier;
	ImmediateInteger* immediate_integer;
	StringLiteral* string_literal;
	UnaryExpression* unary_expression;
	BinaryExpression* binary_expression;
	FunctionCall* function_call;
	AssignmentExpression* assignment_expression;
	Statement* statement;
	VariableDeclaration* variable_declaration;
	StatementsBlock* statements_block;
	IfStatement* if_statement;
	WhileStatement* while_statement;
	ExpressionStatement* expression_statement;
	FunctionDeclaration* function_declaration;
	FunctionDefinition* function_definition;
	std::string* string;


/* Line 2058 of yacc.c  */
#line 126 "CParser.hpp"
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
