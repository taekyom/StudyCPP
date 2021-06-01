#include<stdio.h>

class Human
{
public: //클래스 외부에서 사용하기 위해 public 지정
	char name[12];
	int age;

	void intro()
	{
		printf("이름=%s, 나이=%d\n", name, age);
	}
};

int main()
{
	Human arFriend[10] = { {"문동욱", 49}, {"김유진", 49}, {"홍길동", 49} }; //Human 타입으로 배열 arFriend[10] 선언
	Human* pFriend;			//배열 데이터 중 한명의 정보를 가리킴
	pFriend = &arFriend[1];	//arFriend의 1번째 방의 주소값 → 김유진
	pFriend->intro();
}