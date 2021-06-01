#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

class Human
{
private:
	char name[12];
	int age;
public:
	//������
	Human(const char* aname, int aage)
	{
		SetName(aname);
		SetAge(aage);
	}

	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}

	char* GetName()	
	{
		return name;
	}
	void SetName(const char* aname)
	{
		if (strlen(aname) < 12)	//�̸��� 12�̸��� ���
		{
			strcpy(name, aname);
		}
		else					//�̸��� 12�̻��� ��� : �� ���ڿ�
		{
			strcpy(name, " ");
		}
	}

	int GetAge() 
	{
		return age;
	}
	void SetAge(int aage)
	{
		if (aage >= 0 && aage <= 120)
		{
			age = aage;	//age�� ���޹��� �μ� aage ����
		}
		else			//0~120�� ������ ���̿� 0 ����
		{
			age = 0;
		}
	}
};

int main()
{
	/*�̸��� ���̸� Ű����� �Է� �ޱ�
	Human i;
	char tempName[100];
	printf("�̸��� �Է��ϼ��� : ");
	cin >> tempName;
	i.SetName(tempName);
	i.GetName();*/

	Human lee("���°�", 26); //Human : Ŭ����, lee : ��ü
	//lee.SetName("�谡���ٶ󸶹ٻ������īŸ����");
	lee.SetAge(400); 
	lee.intro();

	return 0;
}