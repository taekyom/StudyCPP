#include<stdio.h>

int main()
{
	const char* str = "korea";
	int* pi;

	pi = (int*)str;
	printf("%d %x\n", *pi, *pi); //%x : 16진수로 출력
}