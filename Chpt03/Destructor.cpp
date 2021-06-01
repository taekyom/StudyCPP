#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage)
	{
		pname = new char[strlen(aname) + 1]; //new[] : 메모리 할당
		strcpy(pname, aname);
		age = aage;
		printf("%s 객체의 생성자가 호출되었습니다.\n", pname);
	}

	//파괴자 : ~생성자
	~Human()
	{
		printf("%s 객체가 파괴되었습니다.\n", pname);
		delete[]pname; //delete[] : 메모리 반환
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

Human boy("김수한무거북이와두루미", 12); //전역 생성자 생성

int main()
{
	printf("main호출\n");
	//Human boy("김수한무거북이와두루미", 12);
	boy.intro();
}
//객체가 소멸될 때 파괴자가 자동으로 호출
//new[]후에는 반드시 delete[]로 반환해주기