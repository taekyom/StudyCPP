#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	//Human()	//�μ��� ������ �ʴ� ������ : default ������, ����� Ư���� ����x, ������ ������ �ʱ�ȭ�ϴ� ����
	//{
	//	strcpy(name, "�̸�����");
	//	age = 0;
	//}

	//������
	Human(const char* aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}

	void intro()
	{
		printf("�̸� = %s, ���� = %d", name, age);
	}
};


int main()
{
	//����Ʈ �����ڰ� ���� ������ �߻��ϴ� ����
	//Human momo;        //����
	//Human arFriend[3]; //����

	Human arFriend[3] = { {Human("������", 49)}, {Human("������", 49)}, {Human("ȫ�浿", 49)} };

	arFriend[2].intro();
}