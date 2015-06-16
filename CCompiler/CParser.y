%{
#include <stdio.h>
#include <string>
#include "SyntaxNode.h"

Program* program;
extern int yylex();
void yyerror(const char*s) { printf("ERROR: %s\n", s); }

%}

%code requires {
	#include "SyntaxNode.h"
	using namespace std;
}
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
}

//terminal symbols
%token IDENTIFIER STRING_LITERAL IMMEDIATE_INTEGER
%token PTR_OP INC_OP DEC_OP SHIFT_LEFT_OP SHIFT_RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR CONTINUE BREAK RETURN
%token CHAR INT FLOAT CONST VOID

//type of the ymbols
%type <expression> primary_expression
%type <string> IDENTIFIER IMMEDIATE_INTEGER STRING_LITERAL

%start program

%%
program
	:statement
	;

primary_expression
	: IDENTIFIER { $$ = new Identifier(*$1); delete $1; }
	| IMMEDIATE_INTEGER { 
		$$ = new ImmediateInteger(atol($1->c_str())); delete $1; 
	}
	| STRING_LITERAL { 
		$$ = new StringLiteral(*$1); delete $1; 
	}
	| '(' expression ')' { $$ = $2; }
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']' { 
		$$ = new BinaryExpression($1, $2, "[]"); 
	}
	| postfix_expression '(' argument_expression_list ')' {
		$$ = new FunctionCall($1, $3); 
	}
	| postfix_expression '.' IDENTIFIER {
		$$ = new BinaryExpression($1, $3, $2); 
	}
	| postfix_expression PTR_OP IDENTIFIER { 
		$$ = new BinaryExpression($1, $3, $2); 
	}
	| postfix_expression INC_OP {
		$$ = new UnaryExpression($1, "_++");
	}
	| postfix_expression DEC_OP {
		$$ = new UnaryExpression($1, "_--");
	}
	;

argument_expression_list
	: assignment_expression{
		$$ = new vector<Expression>();
		$$.pushback(*$1);
	}
	| argument_expression_list ',' assignment_expression {
		$$.pushback(*$3);
	}
	;

unary_expression
	: postfix_expression 
	| INC_OP unary_expression {
		$$ = new UnaryExpression($1, "++_");
	}
	| DEC_OP unary_expression {
		$$ = new UnaryExpression($1, "--_");
	}
	| unary_operator unary_expression {
		$$ = new UnaryExpression($2, $1);
	}
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
	| additive-expression '+' multiplicative_expression {
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
		$$ = new BinaryExpression($1, $3, $2); 
	}
	| relational_expression '>' shift_expression {
		$$ = new BinaryExpression($1, $3, $2); 
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
		$$ = new BinaryExpression($1, $3, $2); 
	}
	;

exclusive_OR_expression
	: AND_expression
	| exclusive_OR_expression '^' AND_expression {
		$$ = new BinaryExpression($1, $3, $2); 
	}
	;

inclusive_OR_expression
	: exclusive_OR_expression
	| inclusive_OR_expression '|' exclusive_OR_expression {
		$$ = new BinaryExpression($1, $3, $2); 
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
		switch($2)
		{
			case '=':
				$$ = new AssigementExpression($1, $3, "=");
				break;
			case ADD_ASSIGN:
				$$ = new AssigementExpression($1, $3, "+=");
				break;
			case SUB_ASSIGN:
				$$ = new AssigementExpression($1, $3, "-=");
				break;
			case MUL_ASSIGN:
				$$ = new AssigementExpression($1, $3, "*=");
				break;
			case DIV_ASSIGN:
				$$ = new AssigementExpression($1, $3, "/=");
				break;
			case MOD_ASSIGN:
				$$ = new AssigementExpression($1, $3, "%=");
				break;
			case SHIFT_LEFT_ASSIGN:
				$$ = new AssigementExpression($1, $3, "<<=");
				break;
			case SHIFT_RIGHT_ASSIGN:
				$$ = new AssigementExpression($1, $3, ">>=");
				break;
			case AND_ASSIGN:
				$$ = new AssigementExpression($1, $3, "&=");
				break;
			case EXCLUSIVE_OR_ASSIGN:
				$$ = new AssigementExpression($1, $3, "^=");
				break;
			case INCLUSIVE_OR_ASSIGN:
				$$ = new AssigementExpression($1, $3, "|=");
				break;
			default:
				break;
		}		
	}
	;

assignment_operator
	:'='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| SHIFT_LEFT_ASSIGN
	| SHIFT_RIGHT_ASSIGN
	| AND_ASSIGN
	| EXCLUSIVE_OR_ASSIGN
	| INCLUSIVE_OR_ASSIGN
	;

expression
	: assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration_specifiers
	: type_specifier
	;

variable_declaration
	: declaration_specifiers init_declarator_list {
		vector<VariableDeclaration>::iterator iter;
		VariableType::Type t;
		switch($1){
			case VOID:
				t = VariableType::Type::VOID;
				break;
			case CHAR:
				t = VariableType::Type::VOID;
				break;
			case INT:
				t = VariableType::Type::VOID;
				break;
			case FLOAT
				t = VariableType::Type::VOID;
				break;
			default:
				break;
		}
		for (iter = $2.begin(); iter != iter.end(); iter++){
			iter->vt.type = t;
		}
	}
	;

init_declarator_list
	: init_declarator {
		$$ = new vector<VariableDeclaration>();
		$$.pushback(*$1);
	}
	| init_declarator ',' init_declarator_list {
		$3.pushback(*$1);
		$$ = $3;
	}

init_declarator
	: declarator 
	| declarator '=' initializer {
		$$ = $1;
		$$->initializer = $3;
	}
	;

type_specifier
	: VOID
	| CHAR
	| INT
	| FLOAT
	;

pointer
	: { $$ = 0; }
	| '*' pointer { $$ = $2 + 1; }
	;

declarator
	: pointer direct_declarator {
		$2->pointer = $1;
	}
	;

direct_declarator
	: identifier {
		$$ = new VariableDeclaration();
		$$->indentifier = $1;
	}
	| direct_declarator '[' constant_expression ']' {
		$1->array->pushback($3);
		$$ = $1;
	};

function_declarator
	: identifier '(' parameter_list ')' {
		$$ = new FunctionDeclaration($1, $3);
	}
	;

function_call
	: direct_declarator '(' identifier_list ')' {
		$$ = new FunctionCall($1, $3);
	}

parameter_list
	: {
		$$ = new vector<VariableDeclaration*>();
	}
	| parameter_declaration ',' parameter_list {
		$$->pushback(*$1);
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		VariableType::Type t;
		switch($1){
			case VOID:
				t = VariableType::Type::VOID;
				break;
			case CHAR:
				t = VariableType::Type::VOID;
				break;
			case INT:
				t = VariableType::Type::VOID;
				break;
			case FLOAT
				t = VariableType::Type::VOID;
				break;
			default:
				break;
		}
		$2->returnType.type = t;
	}
	;

identifier_list
	: { $$ = new vector<identifier*>(); }
	| identifier_list ',' identifier {
		$$->pushback($3);
	}
	;

initializer
	: assignment_expression
	/*
	| { initializer_list }
	| { initializer_list , }
	*/
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| if_statement
	| while_statement
	| for_statement
	| jump_statement
	| return_statement
	| variable_declaration
	;

compound_statement
	: '{' block_item_list '}' {
		$$ = $2;
	}
	;

block_item_list
	: block_item {
		$$ = new StatementsBlock();
		$$->pushStatement($1);
	}
	| block_item_list block_item {
		$$->pushStatement($1);
	}
	;

block_item
	: statement
	;

expression_statement
	: expression {
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
	: WHILE '(' epression ')' statement {
		$$ = new WhileStatement ($3, $5);
	}
	| do statement while '(' expression ')' ';' {
		$$ = new WhileStatement ($3, $5, true);
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
		$$ = new JumpStatement();
		$$->type = JumpStatement::JumpType::CONTINUE;
	}
	| BREAK ';' {
		$$ = new JumpStatement();
		$$->type = JumpStatement::JumpType::BREAK;
	}
	;

return_statement
	: RETURN expression ';' {
		$$ = new ReturnStatement($2);
	}
	;

translation_unit
	: external_declaration {
		$$ = new Program();
	}
	| translation_unit external_declaration {
		$$->externalDeclarations.pushback($1);
	}
	;

external_declaration
	: function_definition {
		$$ = new ExternalDeclaration(ExternalDeclaration::Type::FUNCTION_DECLARATION, $1);
	} 
	| variable_declaration {
		$$ = new ExternalDeclaration(ExternalDeclaration::Type::VARIABLE_DECLARATION, $1);
	}
	;

function_definition
	: declaration_specifiers function_declarator compound_statement {
		$2->setReturnType($1);
		$2->setStatements($3);
	}