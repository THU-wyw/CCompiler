#include <iostream>
#include <string>
using namespace std;

void printStr(string s)
{
	cout << s << endl;
}
int main()
{
	string *s = new string("$");
	cout << *s << endl;
}