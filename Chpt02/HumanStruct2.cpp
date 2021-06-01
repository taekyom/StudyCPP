#include<stdio.h>

struct Human
{
	char name[12];
	int age;

	void intro()	//멤버함수(method)의 내부 작성
	{
		printf("이름 = %s, 나이 =%d", name, age);
	}
};


int main()
{
	Human lee = { "이태경", 26 };
	lee.intro();

	return 0;
}