#include<stdio.h>

int main()
{
	int age = 25;
	bool isAdult = age > 19;
	if (isAdult)
	{
		puts("성인입니다.");
	}

	return 0;
}
//age가 이미 bool의 조건보다 크므로 "성인입니다." 출력