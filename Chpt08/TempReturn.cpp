#include<stdio.h>

template<typename T>
T max(T a, T b)
{
	return(a > b) ? a : b;
}

int main()
{
	int a = max<int>(1, 2);
	double b = max(1.1, 2.2);
	//int c = max(2, 3.14);

	printf("a = %d\n", a);
}