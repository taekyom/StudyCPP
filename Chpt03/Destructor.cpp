#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage)
	{
		pname = new char[strlen(aname) + 1]; //new[] : �޸� �Ҵ�
		strcpy(pname, aname);
		age = aage;
		printf("%s ��ü�� �����ڰ� ȣ��Ǿ����ϴ�.\n", pname);
	}

	//�ı��� : ~������
	~Human()
	{
		printf("%s ��ü�� �ı��Ǿ����ϴ�.\n", pname);
		delete[]pname; //delete[] : �޸� ��ȯ
	}

	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};

Human boy("����ѹ��ź��̿͵η��", 12); //���� ������ ����

int main()
{
	printf("mainȣ��\n");
	//Human boy("����ѹ��ź��̿͵η��", 12);
	boy.intro();
}
//��ü�� �Ҹ�� �� �ı��ڰ� �ڵ����� ȣ��
//new[]�Ŀ��� �ݵ�� delete[]�� ��ȯ���ֱ�