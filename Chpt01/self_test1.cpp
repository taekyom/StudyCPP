#include<stdio.h>

int main()
{
	float* a; //�Ǽ��� �迭

	a = new float[100];
	a[50] = 3.14;
	printf("%.2lf", a[50]);
}