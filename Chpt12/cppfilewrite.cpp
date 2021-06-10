#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream f;

	f.open("C:\Sources\GitRepository\StudyCPP\Chpt12\cpptest.txt");
	if(f.is_open())
	{
		f << "string" << 1234 << endl;
		f.close();
	}
	else
	{
		cout << "파일 열기 실패" << endl;
	}
	return 0;
}