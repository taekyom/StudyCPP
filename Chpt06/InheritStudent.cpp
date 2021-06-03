#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;
public:
	Human(const char *aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}
	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

class Student : public Human //Human으로부터 Student 파생, 부모는 public으로 상속
{
private:
	int stunum;
public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage)
	{
		stunum = astunum;
	}
	void study()
	{
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

int main()
{
	Human kim("김상철", 29); //부모 클래스 타입의 객체 생성
	kim.intro();
	Student han("김한결", 15, 123456); //자식 클래스 타입의 객체 생성
	han.intro();
	han.study();

	return 0;
}
//부모클래스와 자식클래스 간의 생성자 호출 과정
//1. 자식클래스의 생성자가 먼저 호출
//2. 부모클래스의 생성자 호출 및 실행
//3. 자식 클래스의 생성자 실행
//자식클래스는 부모클래스의 private으로 선언된 멤버변수에 접근은 가능, 변경/수정은 불가능
//protected : 상속받은 클래스만 사용가능