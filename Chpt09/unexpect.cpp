#include<stdio.h>
#include<exception>
using namespace std;

void myunex()
{
	puts("�߻��ؼ��� �ȵǴ� ���� �߻�");
	exit(-2);
}

void calc() throw(int)
{
	throw "string";
}

int main()
{
	set_unexpected(myunex);
	try
	{
		calc();
	}
	catch (int)
	{
		puts("������ ���� �߻�");
	}
	puts("���α׷� ����");

	return 0;
}