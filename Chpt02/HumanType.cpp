#include<stdio.h>

class Human
{
public:
	char name[12];
	int age;

	void intro()
	{
		printf("이름=%s, 나이=%d\n", name, age);
	}
};

int main()
{
	Human arFriend[10] = { {"문동욱", 49}, {"김유진", 49}, {"홍길동", 49} };
	Human* pFriend;			//한명의 정보를 가리킴
	pFriend = &arFriend[1];	//arFriend의 1번째 방의 주소값을 가리킴
	pFriend->intro();
}