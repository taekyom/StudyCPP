#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
protected:
	char name[12];
	int age;
public:
	Human(const char* aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}
	void intro()
	{
		printf("ÀÌ¸§ = %s, ³ªÀÌ = %d\n", name, age);
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
	void intro()
	{
		printf("%dÇÐ¹ø %sÀÔ´Ï´Ù.\n", stunum, name);
	}
	void study()
	{
		printf("ÀÌÀÌ´Â »ç, ÀÌ»ïÀº À°, ÀÌ»ç ÆÈ");
	}
};

int main()
{
	Human h("±è»ç¶û", 10);
	Student s("ÀÌÇÐ»ý", 15, 1234567);
	Human* pH;
	pH = &h;
	pH->intro();
	pH = &s;
	pH->intro();

	return 0;
}