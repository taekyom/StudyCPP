#include<stdio.h>

struct Human
{
	char name[12];
	int age;

	void intro()	//����Լ�(method)�� ���� �ۼ�
	{
		printf("�̸� = %s, ���� =%d", name, age);
	}
};


int main()
{
	Human lee = { "���°�", 26 };
	lee.intro();

	return 0;
}