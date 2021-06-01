#include<stdio.h>

int main()
{
	int* ar;

	ar = new int[5]; //배열을 동적할당, C에서는 (int*)malloc(sizeof(int)*5)로 표현
	for (int i = 0; i < 5; i++)
	{
		ar[i] = i;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d번째 = %d\n", i, ar[i]);
	}
	delete[] ar; //배열 해제 시에는 delete[] 사용
}
//재할당할 때는 new로 다시 생성해서 사용