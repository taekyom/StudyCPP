#include<stdio.h>

int ar[] = { 1, 2, 3, 4, 5 };

int& GetAr(int i) //ar배열의 i번째 요소를 찾아서 그 요소의 레퍼런스를 리턴해주는 함수
{
	return ar[i];
}

int main()
{
	GetAr(3) = 6;
	printf("ar[3] = %d\n", ar[3]);
}

//rvalue : 상수, 배열, 변수
//lvalue : 변수, 