#include<stdio.h>

//base에 from~to까지의 합계를 더하는데 step 단위씩 건너뜀 → base는 0이므로 0부터 누적하면서 1씩 증가
int GetSum(int from, int to, int step = 1, int base = 0); //int from, int to → 반드시 작성, int step, int base → 생략하면 0, 1

int main()
{
	printf("%d\n", GetSum(1, 10));						  //GetSum(from, to, step, base)순으로 작성
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
