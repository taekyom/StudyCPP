#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	Human()	//�μ��� ������ �ʴ� ������ : default ������, ����� Ư���� ����x, ������ ������ �ʱ�ȭ�ϴ� ����
	{
		strcpy(name, "�̸�����");
		age = 0;
	}

	void intro()
	{
		printf("�̸� = %s, ���� = %d", name, age);
	}
};

int main()
{
	Human momo;
	momo.intro();
}