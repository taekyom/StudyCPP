#include<stdio.h>

class StaticTest
{
public:
	int a;
	static int b;	//static ������� ����, ��ü ���� ����X
	//������
	StaticTest()
	{
		a = 10;
		//b = 20;   //static ��������� Ŭ���� ���ο��� �ʱ�ȭ �Ұ���
		b++;
	}
	
	void GetData()
	{
		printf("a = %d, b= %d\n", a, b);
	}

};

//int b = 20;			//�Ҽ��� �����Ƿ� �ʱ�ȭ �Ұ���
int StaticTest::b = 20; //static ������� �ʱ�ȭ : Ŭ���� �ܺο��� Ŭ���� �Ҽ��� ����������� ����

int main()
{
	StaticTest s1;
	s1.GetData();
	StaticTest s2;
	s2.GetData();

	return 0;
}