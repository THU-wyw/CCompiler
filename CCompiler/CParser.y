%{
#include <stdio.h>
#include <string>
#include "SyntaxNode.h"

Program* program;
extern int yylex();
void yyerror(const char*s) { printf("ERROR: %s\n", s); }

%}

%code requires {
	#include <vector>
	#include "SyntaxNode.h"
	using namespace std;
}

%union {
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
%type <expression> expression constant_expression conditional_expression
%type <expression> primary_expression postfix_expression unary_expression
%type <expression> multiplicative_expression additive_expression shift_expression relational_expression equality_expression AND_expression inclusive_OR_expression exclusive_OR_expression logical_AND_expression logical_OR_expression
%type <expression> assignment_expression initializer
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
%type <statement> while_statement
%type <statement> jump_statement
%type <statement> return_statement
%type <program> translation_unit program

%type <statement> block_item statement

//basic types
%type <identifier> identifier
%type <str> IDENTIFIER IMMEDIATE_INTEGER STRING_LITERAL
%type <str> unary_operator assignment_operator
%type <number> pointer 
%type <vt_t> declaration_specifiers type_specifier

%start program

%%
program
	: translation_unit { $$ = $1; program = $1; }
	;

primary_expression
	: identifier
	| IMMEDIATE_INTEGER { 
		$$ = new ImmediateInteger(atol($1->c_str())); delete $1; 
	}
	| STRING_LITERAL { 
		$$ = new StringLiteral(*$1); delete $1; 
	}
	| '(' expression ')' { $$ = $2; }
	;
/*
*	postfix_expression example:
*		a[6], a(), a.b, a->b, a++, a--
*/
postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']' { 
		$$ = new BinaryExpression($1, $3, "[]"); 
	}
	| postfix_expression '(' argument_expression_list ')' {
		cout << "function call" << endl;
		$$ = new FunctionCall($1, $3); 
	}
	| postfix_expression '(' ')' {
		cout << "function call" << endl;
		$$ = new FunctionCall($1, new vector<Expression*>()); 
	}
	| postfix_expression '.' identifier {
		$$ = new BinaryExpression($1, $3, "."); 
	}
	| postfix_expression PTR_OP identifier { 
		$$ = new BinaryExpression($1, $3, "->"); 
	}
	| postfix_expression INC_OP {
		$$ = new UnaryExpression($1, "_++");
	}
	| postfix_expression DEC_OP {
		$$ = new UnaryExpression($1, "_--");
	}
	;

/*
*   argument_expression_list example:
*       someFunction( a, 3*5 )
*                     ^^^^^^ 
*/
argument_expression_list
	: assignment_expression {
		$$ = new vector<Expression*>();
		$$->push_back($1);
	}
	| argument_expression_list ',' assignment_expression {
		$$->push_back($3);
	}
	;

/*
*   unary_expression_list example:
*       ++a, --a, &p, *p, +2, -1, ~a, !a
*/
unary_expression
	: postfix_expression 
	| INC_OP unary_expression {
		$$ = new UnaryExpression($2, "++_");
	}
	| DEC_OP unary_expression {
		$$ = new UnaryExpression($2, "--_");
	}
	| unary_operator unary_expression {
		$$ = new UnaryExpression($2, *$1);
	}
	;

unary_operator
	: '&' { $$ = new string("&"); }
	| '*' { $$ = new string("*"); }
	| '+' { $$ = new string("+"); }
	| '-' { $$ = new string("-"); }
	| '~' { $$ = new string("~"); }
	| '!' { $$ = new string("!"); }
	;

/*
*	< means belongs to
*	Here we have:
*   unary_expression < multiplicative_expression < additive_expression < shift_expression
*	< relational_expression < equality_expression < AND_expression < exclusive_OR_expression 
*	< inclusive_OR_expression < logical_AND_expression < logical_OR_expression < assignment_expression
*/
multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression {
		$$ = new BinaryExpression($1, $3, "*"); 
	}
	| multiplicative_expression '/' unary_expression {
		$$ = new BinaryExpression($1, $3, "/"); 
	}
	| multiplicative_expression '%' unary_expression {
		$$ = new BinaryExpression($1, $3, "%"); 
	}
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression {
		$$ = new BinaryExpression($1, $3, "+"); 
	}
	| additive_expression '-' multiplicative_expression {
		$$ = new BinaryExpression($1, $3, "-"); 
	}
	;

shift_expression
	: additive_expression
	| shift_expression SHIFT_LEFT_OP additive_expression {
		$$ = new BinaryExpression($1, $3, "<<"); 
	}
	| shift_expression SHIFT_RIGHT_OP additive_expression {
		$$ = new BinaryExpression($1, $3, ">>"); 
	}
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression {
		$$ = new BinaryExpression($1, $3, "<"); 
	}
	| relational_expression '>' shift_expression {
		$$ = new BinaryExpression($1, $3, ">"); 
	}
	| relational_expression LE_OP shift_expression {
		$$ = new BinaryExpression($1, $3, "<="); 
	}
	| relational_expression GE_OP shift_expression {
		$$ = new BinaryExpression($1, $3, ">="); 
	}
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression {
		$$ = new BinaryExpression($1, $3, "==");  
	}
	| equality_expression NE_OP relational_expression {
		$$ = new BinaryExpression($1, $3, "!="); 
	}
	;

AND_expression
	: equality_expression
	| AND_expression '&' equality_expression {
		$$ = new BinaryExpression($1, $3, "&"); 
	}
	;

exclusive_OR_expression
	: AND_expression
	| exclusive_OR_expression '^' AND_expression {
		$$ = new BinaryExpression($1, $3, "^"); 
	}
	;

inclusive_OR_expression
	: exclusive_OR_expression
	| inclusive_OR_expression '|' exclusive_OR_expression {
		$$ = new BinaryExpression($1, $3, "|"); 
	}
	;

logical_AND_expression
	: inclusive_OR_expression
	| logical_AND_expression AND_OP inclusive_OR_expression {
		$$ = new BinaryExpression($1, $3, "&&"); 
	}
	;

logical_OR_expression
	: logical_AND_expression
	| logical_OR_expression OR_OP logical_AND_expression {
		$$ = new BinaryExpression($1, $3, "||"); 
	}
	;

assignment_expression
	: logical_OR_expression
	| unary_expression assignment_operator assignment_expression {
		$$ = new AssignmentExpression($1, $3, *$2);
	}
	;

assignment_operator
	:'=' { $$ = new string("="); }
	| MUL_ASSIGN { $$ = new string("*="); }
	| DIV_ASSIGN { $$ = new string("/="); }
	| MOD_ASSIGN { $$ = new string("%="); }
	| ADD_ASSIGN { $$ = new string("+="); }
	| SUB_ASSIGN { $$ = new string("-="); }
	| SHIFT_LEFT_ASSIGN { $$ = new string("<<="); }
	| SHIFT_RIGHT_ASSIGN { $$ = new string(">>="); }
	| AND_ASSIGN { $$ = new string("&="); }
	| EXCLUSIVE_OR_ASSIGN { $$ = new string("^="); }
	| INCLUSIVE_OR_ASSIGN { $$ = new string("|="); }
	;

expression
	: assignment_expression
	;

conditional_expression
	: logical_OR_expression
	;

constant_expression
	: conditional_expression
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
		vector<VariableDeclaration*>::iterator iter;
		for (iter = $2->begin(); iter != $2->end(); iter++){
			(*iter)->vt.type = $1;
		}
		$$ = *($2->begin());
	}
	;

init_declarator_list
	: init_declarator {
		$$ = new vector<VariableDeclaration*>();
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
		$$->initializer = $3;
	}
	;

type_specifier
	: VOID { $$ = VariableType::VOID; }
	| CHAR { $$ = VariableType::CHAR; }
	| INT { $$ = VariableType::INT; }
	| FLOAT { $$ = VariableType::FLOAT; }
	;

pointer
	: { $$ = 0; }
	| '*' pointer { $$ = $2 + 1; }
	;

declarator
	: pointer direct_declarator {
		$2->vt.pointer = $1;
		$$ = $2;
	}
	;

direct_declarator
	: identifier {
		$$ = new VariableDeclaration();
		$$->identifier = $1;
	}
	| direct_declarator '[' constant_expression ']' {
		$1->vt.array.push_back($3);
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
	: identifier '(' parameter_list ')' {
		$$ = new FunctionDeclaration($1, $3);
	}
	| identifier '(' ')' {
		$$ = new FunctionDeclaration($1, new vector<VariableDeclaration*>());
	}
	;

parameter_list
	: parameter_declaration {
		$$ = new vector<VariableDeclaration*>();
		$$->push_back($1);
	}
	| parameter_list ',' parameter_declaration {
		$1->push_back($3);
		$$ = $1;
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		cout << "parameter_declaration" << endl;
		$2->vt.type = $1;
		$$ = $2;
	}
	;

identifier
	: IDENTIFIER { $$ = new Identifier(*$1); }
	;

initializer
	: assignment_expression
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
//	| for_statement
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
		//((StatementsBlock *)$$)->pushStatement($1);
	}
	| block_item_list block_item {
		cout << "block_item_list" << endl;
		((StatementsBlock *)$1)->pushStatement($2);
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
	: IF '(' expression ')' statement {
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

/*
for_statement
	: for '(' expression ';' expression ';' expression ')' statement
	| for '(' declaration expression ';' expression')'statement
	;
*/

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
		$$->pushDeclaration($1);
	}
	| translation_unit declaration {
		$$->pushDeclaration($2);
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
	: declaration_specifiers function_declarator compound_statement {
		VariableType vt;
		vt.type = $1;
		$2->setReturnType(vt);
		$2->setStatementsBlock($3);
		$$ = $2;
	}