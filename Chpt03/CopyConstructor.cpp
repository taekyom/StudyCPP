#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<String.h>


class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage)
	{
		pname = new char[strlen(aname) + 1]; //�����Ҵ�
		strcpy(pname, aname);
		age = aage;
	}
	Human(const Human& other) //���� ������ : ���� Ÿ���� �ٸ� ��ü�� ���� ���۷����� ����, ������ ������ ���ѷ���
	{
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}
	//���� �����ڰ� �ڱ� �ڽ��� ���� ���Ǿ��� ������ ���ȣ��
	/*Human(Human other)
	{
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}*/


	~Human() //�����Ҵ� ����
	{
		delete[]pname;
	}

	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};

void printHuman(Human who)
{
	who.intro();
}

int main()
{
	Human Kang("������", 1424);
	Human boy = Kang;

	printHuman(boy);
}