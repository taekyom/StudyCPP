#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char* pname;
	int age;
public:
	Human(const char* aname, int aage) //포인터 변수 → 포인터로, 배열 → 포인터로
	{
		pname = new char[strlen(aname) + 1]; //배열의 동적할당
		strcpy(pname, aname);
		age = aage;
	}

	~Human() //동적할당 해제
	{
		delete[]pname;
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};


int main()
{
	Human Kang("강감찬", 1424);
	Human boy = Kang;	//boy가 kang의 사본

	boy.intro();
}