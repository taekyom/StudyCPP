#include<stdio.h>

//int func(int a)
//{
//	return a;
//}

int func(int a, int b = 0)	//디폴트 매개변수(b = 0) 설정
{
	return a + b;
}

int main()
{
	func(10);	//함수 오버로딩 발생

	return 0;
}