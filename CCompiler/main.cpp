#include <iostream>
#include <fstream>
#include <stdio.h>
#include "SyntaxNode.h"
using namespace std;
extern int yyparse();
extern FILE * yyin;
extern Program* program;

void test(string file)
{
	string test_file = "../Tests/source_code/"+file+".cpp";
	string result_file = "../Tests/syntax_results/"+file+"-syntax.txt";
	string final_file = "../Tests/translate_results/"+file+".java";
	ifstream fin;
	fopen_s(&yyin, test_file.c_str(), "r");
	yyparse();
	ofstream fout;

	fout.open(result_file);
	if (program != NULL)
		program->PrintTree(fout);
	fout.close();

	fout.open(final_file);
	if(program != NULL)
		program->GenerateCode(fout);
	fout.close();
}
int main(int argc, char **argv)
{	
	//test("expression");
	//test("declaration");
	//test("statement");
    //test("Palindrome");
	test("KMP");
	//test("ExpressionEvaluation");
	return 0;
}