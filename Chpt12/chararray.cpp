#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s("char array");
	string s2("C++ string");

	cout << s.data() << endl;
	cout << s.c_str() << endl;

	char str[128];
	strcpy(str, s.c_str());
	printf("str = %s\n", str);

	swap(s, s2);
	cout << s << endl;
	return 0;
}