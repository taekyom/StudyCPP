#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<String.h>


class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage)
	{
		pname = new char[strlen(aname) + 1]; //동적할당
		strcpy(pname, aname);
		age = aage;
	}
	Human(const Human& other) //복사 생성자 : 같은 타입의 다른 객체에 대한 레퍼런스를 받음, 값으로 받으면 무한루프
	{
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}
	//복사 생성자가 자기 자신을 종료 조건없이 무한히 재귀호출
	/*Human(Human other)
	{
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}*/


	~Human() //동적할당 해제
	{
		delete[]pname;
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

void printHuman(Human who)
{
	who.intro();
}

int main()
{
	Human Kang("강감찬", 1424);
	Human boy = Kang;

	printHuman(boy);
}