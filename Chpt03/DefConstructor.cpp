#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	Human()	//인수를 취하지 않는 생성자 : default 생성자, 멤버에 특정값 대입x, 무난한 값으로 초기화하는 역할
	{
		strcpy(name, "이름없음");
		age = 0;
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d", name, age);
	}
};

int main()
{
	Human momo;
	momo.intro();
}