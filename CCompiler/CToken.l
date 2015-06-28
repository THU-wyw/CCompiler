%option noyywrap
%option interactive
%x COMMENT
%x IFILE
%{
#include <cstdio>
#include "CParser.hpp"
#include "CParserDriver.h"

#define YY_DECL int yylex(yy::CParser::semantic_type *yylval, \
	yy::CParser::location_type *yylloc, CParserDriver& driver)

#define YY_USER_ACTION yylloc->columns(yyleng);
struct Reference {
	struct Reference *next;
	char *filename;
	int flags;
	int lineno;
};

char *current_filename;

struct BufferStack {
	struct BufferStack *prev;
	YY_BUFFER_STATE buffer;
	int lineno;
	char* filename;
	FILE* file;
} *current_buffer_stack;

typedef yy::CParser::token token;
int NewFile(char *filename);
int PopFile(void);
%}
%%
[ \t\n]+
\\$
"case"							{ return token::CASE; }
"default"						{ return token::DEFAULT; }
"if"							{ return token::IF; }
"else"							{ return token::ELSE; }
"switch"						{ return token::SWITCH; }
"while"							{ return token::WHILE; }
"do"							{ return token::DO; }
"for"							{ return token::FOR; }
"continue"						{ return token::CONTINUE; }
"break"							{ return token::BREAK; }
"return"						{ return token::RETURN; }
"char"							{ return token::CHAR; }
"int"							{ return token::INT; }
"float"							{ return token::FLOAT; }
"const"							{ return token::CONST; }
"void"							{ return token::VOID; }
"{"  							{ return '{'; }
"}"								{ return '}'; }
"["								{ return '['; }
"]"								{ return ']'; }
"("								{ return '('; }
")"								{ return ')'; }
"++"							{ return token::INC_OP; }
"--"							{ return token::DEC_OP; }
"->"							{ return token::PTR_OP; }
"+="							{ return token::ADD_ASSIGN; }
"-="							{ return token::SUB_ASSIGN; }
"*="							{ return token::MUL_ASSIGN; }
"/="							{ return token::DIV_ASSIGN; }
"%="                            { return token::MOD_ASSIGN; }
"<<="                           { return token::SHIFT_LEFT_ASSIGN; }
">>="                           { return token::SHIFT_RIGHT_ASSIGN; }
"&="                            { return token::AND_ASSIGN; }
"^="                            { return token::EXCLUSIVE_OR_ASSIGN; }
"|="                            { return token::INCLUSIVE_OR_ASSIGN; }
"<="							{ return token::LE_OP; }
">="							{ return token::GE_OP; }
"=="							{ return token::EQ_OP; }
"!="							{ return token::NE_OP; }
"&&"							{ return token::AND_OP; }
"||"							{ return token::OR_OP; }
"<<"                            { return token::SHIFT_LEFT_OP; }
">>"                            { return token::SHIFT_RIGHT_OP; }
"!"								{ return '!'; }
"+"								{ return '+'; }
"-"								{ return '-'; }
"*"								{ return '*'; }
"/"                             { return '/'; }
"%"                             { return '%'; }
"<"								{ return '<'; }
">"								{ return '>'; }
","								{ return ','; }
"="								{ return '='; }
";"								{ return ';'; }
"&"                             { return '&'; }
"~"                             { return '~'; }
"."								{ return '.'; }
"^"								{ return '^'; }
"|"								{ return '|'; }
([1-9][0-9]*)|0					{ 
									// printf("integer: %s\n", yytext); 
									yylval->str = new std::string(yytext, yyleng);
									return token::IMMEDIATE_INTEGER;
								}
[_a-zA-Z][_a-zA-Z0-9]*			{ 
									// printf("identifier: %s\n", yytext); 
									yylval->str = new std::string(yytext, yyleng);
									return token::IDENTIFIER;
								}
\"([^"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+)*\" { 
									// printf("string_literal: %s\n", yytext);
									yylval->str = new std::string(yytext, yyleng);
									return token::STRING_LITERAL; 
								}
\'(.|\\.)\'						{
									yylval->str = new std::string(yytext, yyleng);
									return token::CHAR_LITERAL;
								}
^"#"[ \t]*include[ \t]*[\"<]	{ BEGIN(IFILE); }
<IFILE>[^ \t\n\">]+				{
									char c;
									while ((c = yyinput()) && c != '\n');
									yylloc->lines(1);
									if (NewFile(yytext) == 0) {
										yyterminate();
									}
									BEGIN(INITIAL);
								}
<IFILE>.|\n						{
									fprintf(stderr, "%4d bad include line\n", yylineno);
									yyterminate();
								}
<<EOF>>							{ if(PopFile() == 0) yyterminate(); }
"/*"							{ BEGIN(COMMENT); }
<COMMENT>"*/"					{ BEGIN(INITIAL); }
<COMMENT>([^*]|\n)+|.
"//".*\n
. 								{ printf("no match: %s\n", yytext); }
%%

/*int main() {
	NewFile("test.txt");	
	yylex();
	return 0;
}*/

int NewFile(char *filename) {
	FILE* file;
	fopen_s(&file, filename, "r");
	struct BufferStack *buffer = (struct BufferStack *)malloc(sizeof(struct BufferStack));
	if (file == NULL) {
		perror(filename);
		return 0;
	}
	if (buffer == NULL) {
		perror("malloc");
		exit(1);
	}
	if (current_buffer_stack != NULL) {
		current_buffer_stack->lineno = yylineno;
	}
	buffer->prev = current_buffer_stack;
	buffer->buffer = yy_create_buffer(file, YY_BUF_SIZE);
	buffer->file = file;
	buffer->filename = filename;
	yy_switch_to_buffer(buffer->buffer);
	current_buffer_stack = buffer;
	yylineno = 1;
	current_filename = filename;
	return 1;
}

int PopFile(void) {
	struct BufferStack *buffer_stack = current_buffer_stack;
	struct BufferStack *prev_buffer_stack;
	if (buffer_stack == NULL) return 0;
	fclose(buffer_stack->file);
	yy_delete_buffer(buffer_stack->buffer);
	prev_buffer_stack = buffer_stack->prev;
	free(buffer_stack);

	if (prev_buffer_stack == NULL) return 0;
	
	yy_switch_to_buffer(prev_buffer_stack->buffer);
	current_buffer_stack = prev_buffer_stack;
	yylineno = current_buffer_stack->lineno;
	current_filename = current_buffer_stack->filename;
	return 1;
}		

void CParserDriver::ScanBegin() {
	if (filename_.empty()) {
		yyin = stdin;
	}
	else {
		if (fopen_s(&yyin, filename_.c_str(), "r") != 0) {
			exit(1);
		}
	}
}

void CParserDriver::ScanEnd() {
	fclose(yyin);
}