%{
#include <stdio.h>
#include <string>
#include "SyntaxNode.h"

Program* program;
extern int yylex();
void yyerror(const char*s) { 
	printf("ERROR: %s\n", s); 
}

%}

%code requires {
	#include <vector>
	#include "SyntaxNode.h"
	#include "Type.h"
}

%union {
	SyntaxNode* node;
	Program* program;
	Expression* expression;
	Identifier* identifier;
	std::vector<Identifier*>* identifier_list;
	ImmediateInteger* immediate_integer;
	StringLiteral* string_literal;
	UnaryExpression* unary_expression;
	BinaryExpression* binary_expression;
	std::vector<Expression*>* expression_list;
	FunctionCall* function_call;
	AssignmentExpression* assignment_expression;
	Statement* statement;
	Declaration* declaration;
	std::vector<Declaration*>* declaration_list;
	VariableDeclaration* variable_declaration;
	std::vector<VariableDeclaration*>* variable_declaration_list;
	StatementsBlock* statements_block;
	IfStatement* if_statement;
	WhileStatement* while_statement;
	ExpressionStatement* expression_statement;
	FunctionDeclaration* function_declaration;
	FunctionDefinition* function_definition;
	std::string* str;
	int number;
	char symbol;
	Type::BasicType vt_t;
}

// terminal symbols
%token IDENTIFIER STRING_LITERAL IMMEDIATE_INTEGER

// unary op
%token INC_OP DEC_OP 

// binary op
%token PTR_OP SHIFT_LEFT_OP SHIFT_RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP

// assign op
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN SHIFT_LEFT_ASSIGN SHIFT_RIGHT_ASSIGN AND_ASSIGN INCLUSIVE_OR_ASSIGN EXCLUSIVE_OR_ASSIGN

// labels
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR CONTINUE BREAK RETURN

// types
%token CHAR INT FLOAT CONST VOID

// type of the symbols
// expression types
%type <expression> expression 
%type <expression> initializer
%type <expression_list> argument_expression_list

//declaration types
%type <variable_declaration> variable_declaration init_declarator declarator direct_declarator parameter_declaration 
%type <variable_declaration_list> parameter_list init_declarator_list 
%type <function_declaration> function_declarator function_declaration
%type <declaration> declaration

//statement types
%type <statement> compound_statement block_item_list
%type <statement> expression_statement
%type <statement> if_statement
%type <statement> while_statement for_statement
%type <statement> jump_statement
%type <statement> return_statement
%type <program> translation_unit program

%type <statement> block_item statement

//basic types
%type <identifier> identifier
%type <str> IDENTIFIER IMMEDIATE_INTEGER STRING_LITERAL
%type <number> pointer 
%type <vt_t> declaration_specifiers type_specifier

%start program

%left '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN SHIFT_LEFT_ASSIGN SHIFT_RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN EXCLUSIVE_OR_ASSIGN INCLUSIVE_OR_ASSIGN
%left OR_OP
%left AND_OP
%left '|'
%left '^'
%left '&'
%left EQ_OP NE_OP
%left '>' '<' LE_OP GE_OP
%left SHIFT_LEFT_OP SHIFT_RIGHT_OP
%left '+' '-'
%left '/' '*' '%'
%nonassoc '!' REFERENCE DEREFERENCE INC_OP DEC_OP '~' UMINUS UADD
%left '.' PTR_OP '[' ']' '(' ')'

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%
program
	: translation_unit { $$ = $1; program = $1; }
	;

expression
	: identifier { $$ = $1; }
	| IMMEDIATE_INTEGER { 
		$$ = new ImmediateInteger(atol($1->c_str())); 
		delete $1;
	}
	| STRING_LITERAL {
		$$ = new StringLiteral(*$1);
		delete $1;
	}
	| '(' expression ')' { $$ = $2; }
	| expression '+' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::ADD); }
	| expression '-' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::SUB); }
	| expression '*' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::MUL); }
	| expression '/' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::DIV); }
	| expression '%' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::MOD); }
	| expression '^' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::XOR_BIT); }
	| expression '|' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::OR_BIT); }
	| expression '&' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::AND_BIT); }
	| expression SHIFT_LEFT_OP expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::SHIFT_LEFT); }
	| expression SHIFT_RIGHT_OP expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::SHIFT_RIGHT); }
	| expression '>' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::GREATER); }
	| expression '<' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::LESS); }
	| expression EQ_OP expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::EQUAL); }
	| expression LE_OP expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::LESS_EQUAL); }
	| expression GE_OP expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::GREATER_EQUAL); }
	| expression NE_OP expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::NOT_EQUAL); }
	| expression '=' expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::ASSIGN); }
	| expression ADD_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::ADD_ASSIGN); }
	| expression SUB_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::SUB_ASSIGN); }
	| expression MUL_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::MUL_ASSIGN); }
	| expression DIV_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::DIV_ASSIGN); }
	| expression MOD_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::MOD_ASSIGN); }
	| expression AND_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::AND_ASSIGN); }
	| expression EXCLUSIVE_OR_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::EXCLUSIVE_OR_ASSIGN); }
	| expression INCLUSIVE_OR_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::INCLUSIVE_OR_ASSIGN); }
	| expression SHIFT_LEFT_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::SHIFT_LEFT_ASSIGN); }
	| expression SHIFT_RIGHT_ASSIGN expression { $$ = new AssignmentExpression($1, $3, AssignmentExpression::Operator::SHIFT_RIGHT_ASSIGN); }
	| expression AND_OP expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::AND); }
	| expression OR_OP expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::OR); }
	| expression '[' expression ']' { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::INDEX); }
	| expression '.' expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::DOT); }
	| expression PTR_OP expression { $$ = new BinaryExpression($1, $3, BinaryExpression::Operator::POINTER); }
	| expression INC_OP { $$ = new UnaryExpression($1, UnaryExpression::Operator::INC_AFTER); }
	| expression DEC_OP { $$ = new UnaryExpression($1, UnaryExpression::Operator::DEC_AFTER); }
	| INC_OP expression { $$ = new UnaryExpression($2, UnaryExpression::Operator::INC_PRE); }
	| DEC_OP expression { $$ = new UnaryExpression($2, UnaryExpression::Operator::DEC_PRE); }
	| '&' expression %prec REFERENCE { $$ = new UnaryExpression($2, UnaryExpression::Operator::REFERENCE); }
	| '*' expression %prec DEREFERENCE { $$ = new UnaryExpression($2, UnaryExpression::Operator::DEREFERENCE); }
	| '+' expression %prec UADD { $$ = $2; }
	| '-' expression %prec UMINUS { $$ = new UnaryExpression($2, UnaryExpression::Operator::MINUS); }
	| '~' expression { $$ = new UnaryExpression($2, UnaryExpression::Operator::NOT_BIT); }
	| '!' expression { $$ = new UnaryExpression($2, UnaryExpression::Operator::NOT); }
	| identifier '(' argument_expression_list ')' { $$ = new FunctionCall($1, $3); }
	| identifier '('')' { $$ = new FunctionCall($1, NULL); }
	;

argument_expression_list
	: expression { $$ = new std::vector<Expression*>(); $$->push_back($1); }
	| argument_expression_list ',' expression { $$->push_back($3); }
	;

/*
*	in C++11 standard, declaration_specifiers means:
*		const unsign long int *x;
*		^^^^^^^^^^^^^^^^^^^^^
*	type_specifier means:
*		int x
*		^^^
*	To simplify, I just let declaration_specifiers equals to type_specifier
*/
declaration_specifiers
	: type_specifier
	;
/*
*	in C++11 standard, there is no variable_declaration 
*	there is only declaration
*	Here I remove some of the grammars of declaration and rename it variable_declaration
*	in C++11 standard, variable_declaration can be:
*		int x, *p, y = 2, **q = &p;
*	init_declarator_list means:
*		int x, *p, y = 2, **q = &p;
*			^^^^^^^^^^^^^^^^^^^^^^
*	To simplify, I just don't allow list of declarator 
*		int x; or int x = 0;
*			^		  ^^^^^
*/
variable_declaration
	: declaration_specifiers init_declarator_list {
		for (auto iterator = $2->begin(); iterator != $2->end(); iterator++) {
			(*iterator)->set_basic_type($1);
		}
		$$ = *($2->begin());
	}
	;

init_declarator_list
	: init_declarator {
		$$ = new std::vector<VariableDeclaration*>();
		$$->push_back($1);
	}
	/*| init_declarator_list ',' init_declarator {
		$1->push_back($3);
		$$ = $1;
	}*/
	;

/*
*					int **x = &y;
* init_declarator:		^^^^^^^^
* pointer:				^^
* direct_declarator:      ^
*					int x[5];
* direct_declarator:    ^^^^
*/
init_declarator
	: declarator 
	| declarator '=' initializer {
		$$ = $1;
		$$->set_initializer($3);
	}
	;

type_specifier
	: VOID { $$ = Type::BasicType::VOID; }
	| CHAR { $$ = Type::BasicType::CHARACTER; }
	| INT { $$ = Type::BasicType::INTEGER; }
	| FLOAT { $$ = Type::BasicType::FLOAT; }
	;

pointer
	: { $$ = 0; }
	| '*' pointer { $$ = $2 + 1; }
	;

declarator
	: pointer direct_declarator {
		for (int i = 0; i < $1; i++) {
			$2->set_type(Type::CreatePointerType($2->get_type())); 
		}
		$$ = $2;
	}
	;

direct_declarator
	: identifier {
		$$ = new VariableDeclaration();
		$$->set_type(Type::CreateBasicType());
		$$->set_identifier($1);
	}
	| direct_declarator '[' expression ']' {
		$1->set_type(Type::CreateArrayType($1->get_type(), $3)); 
		$$ = $1;
	};

/*
* 						int someFunction(int x, int* y) {}
* function_declarator:      ^^^^^^^^^^^^^^^^^^^^^^^^^^^
* parameter_list: 						 ^^^^^^^^^^^^^
* parameter_declaration:                 ^^^^^
* function_declaration: ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*/
function_declarator
	: declaration_specifiers declarator '(' parameter_list ')' {
		$$ = new FunctionDeclaration($2->get_identifier(), $4);
	}
	| declaration_specifiers declarator '(' ')' {
		$$ = new FunctionDeclaration($2->get_identifier(), new std::vector<VariableDeclaration*>());
	}
	;

parameter_list
	: parameter_declaration {
		$$ = new std::vector<VariableDeclaration*>();
		$$->push_back($1);
	}
	| parameter_list ',' parameter_declaration {
		$1->push_back($3);
		$$ = $1;
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		std::cout << "parameter_declaration" << std::endl;
		$2->set_basic_type($1);
		$$ = $2;
	}
	;

identifier
	: IDENTIFIER { $$ = new Identifier(*$1); }
	;

initializer
	: expression
	/*
	| { initializer_list }
	| { initializer_list , }
	*/
	;

statement
	: compound_statement
	| expression_statement
	| if_statement
	| while_statement
	| for_statement
	| jump_statement
	| return_statement
	| variable_declaration ';' { $$ = $1; }
	;

compound_statement
	: '{' block_item_list '}' {
		$$ = $2;
	}
	;

block_item_list
	: {
		$$ = new StatementsBlock();
		//((StatementsBlock *)$$)->PushStatement($1);
	}
	| block_item_list block_item {
		std::cout << "block_item_list" << std::endl;
		((StatementsBlock *)$1)->PushStatement($2);
		$$ = $1;
	}
	;

block_item
	: statement
	;

expression_statement
	: expression ';' {
		$$ = new ExpressionStatement($1);
	}
	;

if_statement
	: IF '(' expression ')' statement %prec LOWER_THAN_ELSE {
		$$ = new IfStatement($3, $5);
	}
	| IF '(' expression ')' statement ELSE statement {
		$$ = new IfStatement($3, $5, $7);
	}
	;

while_statement
	: WHILE '(' expression ')' statement {
		$$ = new WhileStatement ($3, $5);
	}
	| DO statement WHILE '(' expression ')' ';' {
		$$ = new WhileStatement ($5, $2, true);
	}
	;


for_statement
	: FOR '(' expression ';' expression ';' expression ')' statement {
		$$ = new ForStatement(new ExpressionStatement($3), $5, $7, $9);
	}
	| FOR '(' variable_declaration ';' expression ';' expression')'statement {
		$$ = new ForStatement($3, $5, $7, $9);
	}
	;


jump_statement
	: CONTINUE ';' {
		$$ = new JumpStatement(JumpStatement::CONTINUE);
	}
	| BREAK ';' {
		$$ = new JumpStatement(JumpStatement::BREAK);
	}
	;

return_statement
	: RETURN expression ';' {
		$$ = new ReturnStatement($2);
	}
	| RETURN ';' {
		$$ = new ReturnStatement(NULL);
	}
	;

/*
*	translation_unit is the begin of the program
*	a program should is built up by a series of declarations(variable_declaration or function_declaration)
*/
translation_unit
	: declaration {
		$$ = new Program();
		$$->PushDeclaration($1);
	}
	| translation_unit declaration {
		$$->PushDeclaration($2);
	}
	;

declaration
	: function_declaration {
		$$ = $1;
	} 
	| variable_declaration {
		$$ = $1;
	}
	;

function_declaration
	: function_declarator compound_statement {
		$1->set_body($2);
		$$ = $1;
	}