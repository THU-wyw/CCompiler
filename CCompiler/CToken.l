%option noyywrap
%x COMMENT
%x IFILE
%{
#include <stdio.h>
#include "CParser.hpp"

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

int NewFile(char *filename);
int PopFile(void);
%}
%%
[ \t\n]+
\\$
"case"							{ return CASE; }
"default"						{ return DEFAULT; }
"if"							{ return IF; }
"else"							{ return ELSE; }
"switch"						{ return SWITCH; }
"while"							{ return WHILE; }
"do"							{ return DO; }
"for"							{ return FOR; }
"continue"						{ return CONTINUE; }
"break"							{ return BREAK; }
"return"						{ return RETURN; }
"char"							{ return CHAR; }
"int"							{ return INT; }
"float"							{ return FLOAT; }
"const"							{ return CONST; }
"void"							{ return VOID; }
"{"  							{ return '{'; }
"}"								{ return '}'; }
"["								{ return '['; }
"]"								{ return ']'; }
"("								{ return '('; }
")"								{ return ')'; }
"++"							{ return INC_OP; }
"--"							{ return DEC_OP; }
"->"							{ return RIGHT_ARROW; }
"+="							{ return ADD_ASSIGN; }
"-="							{ return SUB_ASSIGN; }
"*="							{ return MUL_ASSIGN; }
"/="							{ return DIV_ASSIGN; }
"%="                            { return MOD_ASSIGN; }
"<<="                           { return SHIFT_LEFT_ASSIGN; }
">>="                           { return SHIFT_RIGHT_ASSIGN; }
"&="                            {return AND_ASSIGN; }
"^="                            {return EXCLUSIVE_OR_ASSIGN; }
"|="                            {return INCLUSIVE_OR_ASSIGN; }
"<="							{ return LE_OP; }
">="							{ return GE_OP; }
"=="							{ return EQ_OP; }
"!="							{ return NE_OP; }
"&&"							{ return AND_OP; }
"||"							{ return OR_OP; }
"<<"                            { return SHIFT_LEFT_OP; }
">>"                            { return SHIFT_RIGHT_OP; }
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
"*"                             { return '*'; }
"+"                             { return '+'; }
"-"                             { return '-'; }
"~"                             { return '~'; }
"!"                             { return '!'; }
([1-9][0-9]*)|0					{ 
									// printf("integer: %s\n", yytext); 
									yylval.string = new std::string(yytext, yyleng);
									return IMMEDIATE_INTEGER;
								}
[_a-zA-Z][_a-zA-Z0-9]*			{ 
									// printf("identifier: %s\n", yytext); 
									yylval.string = new std::string(yytext, yyleng);
									return IDENTIFIER;
								}
\"([^"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+)*\" { 
									// printf("string_literal: %s\n", yytext);
									yylval.string = new std::string(yytext, yyleng);
									return STRING_LITERAL; 
								}
^"#"[ \t]*include[ \t]*[\"<]	{ BEGIN(IFILE); }
<IFILE>[^ \t\n\">]+				{
									char c;
									while ((c = yyinput()) && c != '\n');
									yylineno++;
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
	FILE* file = fopen(filename, "r");
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
