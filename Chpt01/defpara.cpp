#include<stdio.h>

//base�� from~to������ �հ踦 ���ϴµ� step ������ �ǳʶ� �� base�� 0�̹Ƿ� 0���� �����ϸ鼭 1�� ����
int GetSum(int from, int to, int step = 1, int base = 0); //int from, int to �� �ݵ�� �ۼ�, int step, int base �� �����ϸ� 0, 1

int main()
{
	printf("%d\n", GetSum(1, 10));						  //GetSum(from, to, step, base)������ �ۼ�
	printf("%d\n", GetSum(1, 10, 2));
	printf("%d\n", GetSum(1, 10, 2, 10));
}

int GetSum(int from, int to, int step/* = 1*/, int base/* = 0*/)
{
	int sum = base;
	for (int i = from; i <= to; i += step)
	{
		sum += i;
	}
	return sum;
}
