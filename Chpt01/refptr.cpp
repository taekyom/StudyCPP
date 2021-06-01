#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

void InputNameRef(char*& Name) //포인터의 레퍼런스(=(char*)타입의 레퍼런스), 포인터 자체를 인수로 받은 것
{
	Name = (char*)malloc(32);
	strcpy(Name, "Lee Tae kyoung");
}

int main()
{
	char* Name;

	InputNameRef(Name);
	printf("이름은 %s입니다.", Name);
	free(Name);
}