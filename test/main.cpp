#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1 = "s1";
	string s2 = s1;
	s1 = "ss1";
	cout << s2;
}