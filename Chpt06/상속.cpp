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
		name = new char[len]; //동적할당
		strcpy_s(name, len, aname); //strcpy_s : 복사할 길이까지 지정하는 함수
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
		PrintName(); //Human 클래스의 name이 private이므로 건드릴 수 없기 때문에 name을 사용하는 함수 자체를 호출
		cout << " My major is " << major;
	}
};

int main()
{
	Human my("이태경");
	my.PrintName();
	printf("\n");
	Student s("이태경", "Iot");
	//s.PrintName();
	s.PrintMajor();
	return 0;
}