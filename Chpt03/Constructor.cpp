#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	//생성자 : 클래스의 이름과 같음, 리턴값이 없음(있으면 멤버함수)
	Human(const char* aname, int aage)
	{
		strcpy(this->name, aname);
		this->age = aage;
	}

	void intro()
	{
		printf("이름=%s, 나이=%d\n", name, age);
	}
};

int main()
{
	Human lee("이태경", 26);
	lee.intro();
}