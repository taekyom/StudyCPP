#include<stdio.h>

int main()
{
	int* pi, * pj;

	pi = new int; //new ������ �⺻ ���� : ������ = new Ÿ��
	pj = new int(10);
	*pi = 123;

	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);

	delete pi;   //new�� delete�� �Բ� ���(malloc�� freeó��)
	delete pj;
}