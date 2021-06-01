#include<stdio.h>

int main()
{
	int* pi, * pj;

	pi = new int; //new 연산자 기본 형식 : 포인터 = new 타입
	pj = new int(10);
	*pi = 123;

	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);

	delete pi;   //new와 delete는 함께 사용(malloc과 free처럼)
	delete pj;
}