#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
protected:
	char name[12];
	int age;
public:
	Human(const char *aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}
	void Eat()
	{
		puts("옴뇸뇸");
	}
	virtual void intro()	//가상함수
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

class Student : public Human
{
protected:
	int stunum;
public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage)
	{
		stunum = astunum;
	}
	void intro() //Human 클래스와 다른 동작이므로 재정의(override)
	{
		printf("%d학번 %s입니다.\n", stunum, name);
	}
};

int main()
{
	Human h("김사랑", 10);
	Student s("이학생", 15, 1234567);
	Human* pH;

	pH = &h;
	pH->intro();
	pH->Eat();
	pH = &s;
	pH->intro();
	pH->Eat();

	return 0;
}