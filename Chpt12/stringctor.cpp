#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1("test");
	string s2(s1);
	string s3;
	string s4(10, 'S'); //S를 10개 만들어라
	string s5("very nice day", 8);
	const char *str = "abcdefghijklmnopqrstuvwxyz";  //값 변경 불가
//	const char str[] = "abcdefghijklmnopqrstuvwxyz"; //값 변경(각 배열의 요소 값) 가능
	string s6(str + 5, str + 10);

	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;
	cout << "s3=" << s3 << endl;
	cout << "s4=" << s4 << endl;
	cout << "s5=" << s5 << endl;
	cout << "s6=" << s6 << endl;


	return 0;
}