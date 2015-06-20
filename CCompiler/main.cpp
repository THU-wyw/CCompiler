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
	string test_file = "../SyntaxTests/tests/"+file+".cpp";
	string result_file = "../SyntaxTests/results/"+file+"-syntax.txt";
	string final_file = "../SyntaxTests/results/"+file+"-java.java";
	ifstream fin;
	fin.open(test_file);
	string temp;
	fin >> temp;
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
	test("declaration");
	//test("statement");
    //test("Palindrome");
	return 0;
}