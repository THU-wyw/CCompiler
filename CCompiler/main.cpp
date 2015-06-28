#include <iostream>
#include <fstream>
#include <stdio.h>
#include "SyntaxNode.h"
#include "CParserDriver.h"
using namespace std;

void test(string file)
{
	string test_file = "../Tests/source_code/"+file+".cpp";
	string result_file = "../Tests/syntax_results/"+file+"-syntax.txt";
	string final_file = "../Tests/translate_results/"+file+".java";
	ofstream fout;
	fout.open(final_file);
	CParserDriver parser_driver;
	parser_driver.Parse(test_file);
	parser_driver.GenerateCode(final_file);
	fout.close();
}
int main(int argc, char **argv)
{	
	//test("expression");
	//test("declaration");
	//test("statement");
	//test("Palindrome");
	//test("KMP");
	test("ExpressionEvaluation");
	return 0;
}