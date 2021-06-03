#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;
public:
	Human(const char *aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}
	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

class Student : public Human //Human���κ��� Student �Ļ�, �θ�� public���� ���
{
private:
	int stunum;
public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage)
	{
		stunum = astunum;
	}
	void study()
	{
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

int main()
{
	Human kim("���ö", 29); //�θ� Ŭ���� Ÿ���� ��ü ����
	kim.intro();
	Student han("���Ѱ�", 15, 123456); //�ڽ� Ŭ���� Ÿ���� ��ü ����
	han.intro();
	han.study();

	return 0;
}
//�θ�Ŭ������ �ڽ�Ŭ���� ���� ������ ȣ�� ����
//1. �ڽ�Ŭ������ �����ڰ� ���� ȣ��
//2. �θ�Ŭ������ ������ ȣ�� �� ����
//3. �ڽ� Ŭ������ ������ ����
//�ڽ�Ŭ������ �θ�Ŭ������ private���� ����� ��������� ������ ����, ����/������ �Ұ���
//protected : ��ӹ��� Ŭ������ ��밡��