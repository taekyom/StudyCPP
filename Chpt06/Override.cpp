#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
protected:
	char name[12];
	int age;
public:
	Human(const char *aname, const int aage)
	{
		strcpy(name, aname);
		age = aage;
	}
	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

class Student : public Human
{
protected:
	int stunum;
public:
	Student(const char*aname, int aage, int astunum) : Human(aname, aage)
	{
		stunum = astunum;
	}
	void study()
	{
		printf("이이는 사, 이삼은 육, 이사 팔");
	}
	void intro()
	{
		printf("%d학번 %s입니다.\n", stunum, name);
	}
};

int main() 
{
	Human kim("김상형", 29);
	kim.intro();
	Student han("김한결", 15, 123456);
	han.intro();
	han.Human::intro();
	return 0;
}
//override : 재정의(상속관계에서 부모 클래스의 멤버함수를 자식 클래스에서 그대로 사용하는 것)
//overload : 중복정의(매개변수 개수나 타입이 다를 때 적용)