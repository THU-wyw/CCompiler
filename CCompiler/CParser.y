%{
#include "SyntaxNode.h"

#include <string>
Program* program;
extern int yylex();
void yyerror(const char*s) { printf("ERROR: %s\n", s); }
%}

%union {
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
%}

%token IDENTIFIER STRING_LITERAL IMMEDIATE_INTEGER
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR CONTINUE BREAK RETURN
%token CHAR INT FLOAT CONST VOID

%start translation_unit

%%
primary_expression
	: IDENTIFIER { $$ = new Identifier(*$1); delete $1; }
	| IMMEDIATE_INTEGER { $$ = new ImmediateInteger(atol($1->c_str())); delete $1; }
	| STRING_LITERAL { $$ = new StringLiteral($1); delete $1; }
	| '(' expression ')'{ $$ = $1; }
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator unary_expression
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression
	| multiplicative_expression '/' unary_expression
	| multiplicative_expression '%' unary_expression
	;

additive_expression
	: multiplicative_expression
	| additive-expression + multiplicative_expression
	| additive_expression - multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression '<=' shift_expression
	| relational_expression '>=' shift_expression
