#include<stdio.h>

int main()
{
	int* ar;

	ar = new int[5]; //�迭�� �����Ҵ�, C������ (int*)malloc(sizeof(int)*5)�� ǥ��
	for (int i = 0; i < 5; i++)
	{
		ar[i] = i;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d��° = %d\n", i, ar[i]);
	}
	delete[] ar; //�迭 ���� �ÿ��� delete[] ���
}
//���Ҵ��� ���� new�� �ٽ� �����ؼ� ���