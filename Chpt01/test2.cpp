#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

//void InputNameRef(char*& Name) //�������� ���۷���(=(char*)Ÿ���� ���۷���), ������ ��ü�� �μ��� ���� ��
//{
//	Name = (char*)malloc(32);
//	strcpy(Name, "Lee Tae kyoung");
//}

int main()
{
	int a = 10;
	int& ra = a;
	int* pa = &ra;
	printf("%p %p %p\n", &a, pa, &ra);
}
