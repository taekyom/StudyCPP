#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

class Human
{
private:
	char name[12];
	int age;
public:
	//생성자
	Human(const char* aname, int aage)
	{
		SetName(aname);
		SetAge(aage);
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}

	char* GetName()	
	{
		return name;
	}
	void SetName(const char* aname)
	{
		if (strlen(aname) < 12)	//이름이 12미만인 경우
		{
			strcpy(name, aname);
		}
		else					//이름이 12이상인 경우 : 빈 문자열
		{
			strcpy(name, " ");
		}
	}

	int GetAge() 
	{
		return age;
	}
	void SetAge(int aage)
	{
		if (aage >= 0 && aage <= 120)
		{
			age = aage;	//age에 전달받은 인수 aage 대입
		}
		else			//0~120을 넘으면 나이에 0 대입
		{
			age = 0;
		}
	}
};

int main()
{
	/*이름과 나이를 키보드로 입력 받기
	Human i;
	char tempName[100];
	printf("이름을 입력하세요 : ");
	cin >> tempName;
	i.SetName(tempName);
	i.GetName();*/

	Human lee("이태경", 26); //Human : 클래스, lee : 객체
	//lee.SetName("김가나다라마바사아자차카타파하");
	lee.SetAge(400); 
	lee.intro();

	return 0;
}