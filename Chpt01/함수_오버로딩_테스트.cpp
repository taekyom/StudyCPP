#include<stdio.h>

//int func(int a)
//{
//	return a;
//}

int func(int a, int b = 0)	//����Ʈ �Ű�����(b = 0) ����
{
	return a + b;
}

int main()
{
	func(10);	//�Լ� �����ε� �߻�

	return 0;
}