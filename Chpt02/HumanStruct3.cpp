#include<stdio.h>

struct Human
{
	char name[12];
	int age;

	void intro();	//멤버함수 원형 선언
};

//멤버 함수의 외부 작성
void Human::intro()	//Human 구조체에 속한 intro함수, 본체 정의
{
	printf("이름 = %s, 나이 = %d\n", name, age);
}

int main()
{
	Human lee = { "이태경", 26 };
	lee.intro(); //intro 함수 호출
}