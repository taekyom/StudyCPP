#include<stdio.h>

class Simple
{
private:
	int value;
	static int count;	//���� ������� ����
public:
	//����Ʈ ������
	Simple()
	{
		count++;
	}
	//�ı���
	~Simple()
	{
		count--;
	}
	//���� ����Լ�
	static void InitCount()	
	{
		count = 0;
	}
	static void OutCount()
	{
		printf("���� ��ü ���� = %d\n", count);
	}
	
};

int Simple::count;	//���� ������� �ʱ�ȭ

int main()
{
	//ī��Ʈ0
	Simple::InitCount();
	Simple::OutCount();

	//ī��Ʈ1
	Simple s, * ps;		//Simple Ÿ���� ��ü s, *ps ����
	Simple::OutCount();

	//ī��Ʈ2
	ps = new Simple;
	Simple::OutCount();

	//ī��Ʈ1
	delete ps;
	Simple::OutCount();

	//ī��Ʈ0
	printf("ũ�� = %d\n", sizeof(s));

	return 0;
}