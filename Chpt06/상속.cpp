#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
 
class Human
{
private:
	char* name;
public:
	Human(const char* aname)
	{
		int len = strlen(aname) + 1;
		name = new char[len]; //�����Ҵ�
		strcpy_s(name, len, aname); //strcpy_s : ������ ���̱��� �����ϴ� �Լ�
	}
	~Human()
	{
		delete[] name;
	}
	void PrintName()
	{
		cout << "My name is " << name;
	}
};

class Student : public Human
{
protected:
	char* major;
public:
	Student(const char* aname, const char* amajor) : Human(aname)
	{
		int len = strlen(amajor) + 1;
		major = new char[len];
		strcpy_s(major, len, amajor);
	}
	~Student()
	{
		delete[] major;
	}
	void PrintMajor()
	{
		PrintName(); //Human Ŭ������ name�� private�̹Ƿ� �ǵ帱 �� ���� ������ name�� ����ϴ� �Լ� ��ü�� ȣ��
		cout << " My major is " << major;
	}
};

int main()
{
	Human my("���°�");
	my.PrintName();
	printf("\n");
	Student s("���°�", "Iot");
	//s.PrintName();
	s.PrintMajor();
	return 0;
}