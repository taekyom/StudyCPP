#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

void InputNameRef(char*& Name) //�������� ���۷���(=(char*)Ÿ���� ���۷���), ������ ��ü�� �μ��� ���� ��
{
	Name = (char*)malloc(32);
	strcpy(Name, "Lee Tae kyoung");
}

int main()
{
	char* Name;

	InputNameRef(Name);
	printf("�̸��� %s�Դϴ�.", Name);
	free(Name);
}