#include<stdio.h>

int main()
{
	float* a; //실수형 배열

	a = new float[100];
	a[50] = 3.14;
	printf("%.2lf", a[50]);
}