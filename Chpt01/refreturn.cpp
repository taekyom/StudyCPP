#include<stdio.h>

int ar[] = { 1, 2, 3, 4, 5 };

int& GetAr(int i) //ar�迭�� i��° ��Ҹ� ã�Ƽ� �� ����� ���۷����� �������ִ� �Լ�
{
	return ar[i];
}

int main()
{
	GetAr(3) = 6;
	printf("ar[3] = %d\n", ar[3]);
}

//rvalue : ���, �迭, ����
//lvalue : ����, 