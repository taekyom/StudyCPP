#include<stdio.h>

struct Human
{
	char name[12];
	int age;

	void intro();	//����Լ� ���� ����
};

//��� �Լ��� �ܺ� �ۼ�
void Human::intro()	//Human ����ü�� ���� intro�Լ�, ��ü ����
{
	printf("�̸� = %s, ���� = %d\n", name, age);
}

int main()
{
	Human lee = { "���°�", 26 };
	lee.intro(); //intro �Լ� ȣ��
}