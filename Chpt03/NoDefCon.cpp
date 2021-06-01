#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	//Human()	//인수를 취하지 않는 생성자 : default 생성자, 멤버에 특정값 대입x, 무난한 값으로 초기화하는 역할
	//{
	//	strcpy(name, "이름없음");
	//	age = 0;
	//}

	//생성자
	Human(const char* aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d", name, age);
	}
};


int main()
{
	//디폴트 생성자가 없기 때문에 발생하는 에러
	//Human momo;        //에러
	//Human arFriend[3]; //에러

	Human arFriend[3] = { {Human("문동욱", 49)}, {Human("김유진", 49)}, {Human("홍길동", 49)} };

	arFriend[2].intro();
}