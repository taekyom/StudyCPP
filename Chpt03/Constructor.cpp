#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	//������ : Ŭ������ �̸��� ����, ���ϰ��� ����(������ ����Լ�)
	Human(const char* aname, int aage)
	{
		strcpy(this->name, aname);
		this->age = aage;
	}

	void intro()
	{
		printf("�̸�=%s, ����=%d\n", name, age);
	}
};

int main()
{
	Human lee("���°�", 26);
	lee.intro();
}