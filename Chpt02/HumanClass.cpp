#include<stdio.h>

class Human //Ŭ����(Ȯ��� ����ü)
{
public:     //Ŭ������ �⺻������ private�̹Ƿ� �ܺο��� ����Ϸ��� pubilc���� ����
	char name[12];
	int age;

	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human lee = { "���°�", 26 };
	lee.intro();

	return 0;
}