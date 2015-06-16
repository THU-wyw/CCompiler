#include <iostream>
#include "SyntaxNode.h"
using namespace std;
extern int yyparse();
 
int main(int argc, char **argv)
{
	//yyin = fopen("test.txt", "r");
    yyparse();
    cout << "code over" << endl;
    return 0;
}