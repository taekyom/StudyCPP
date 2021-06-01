#include<stdio.h>

int main()
{
	enum origin { EAST, WEST, SOUTH, NORTH }; //enum : 열거형
	enum origin mark = WEST;
	printf("%d 방향\n", mark);				  //WEST가 1번째 데이터이므로 1 출력

	struct SHuman
	{
		char name[12];
		int age;
		double height;
	};

	//struct SHuman lee = { "이태경", 26, 165 }; → struct 키위드를 붙이지 않아도 열거형인지, 구조체인지 구분 가능
	SHuman lee = { "이태경", 26, 165 };
	printf("이름 = %s, 나이 = %d\n", lee.name, lee.age);
}