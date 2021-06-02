#include<stdio.h>

class StaticTest
{
	static int a;	//static ������� ���� �� this ������ ��� �Ұ���(��ü ���� �����ϴ°� �ƴϹǷ�)
	int b;

public:
	//����Ʈ ������
	StaticTest();
	//static ����Լ� : static ��������� ����ϱ� ����
	static void SetData(int);	

	void GetData();
};

int StaticTest::a = 10;			//static ������� �ʱ�ȭ(Ŭ���� �ܺ�)

StaticTest::StaticTest()
{
	this->b = 20;
}
void StaticTest::GetData()
{
	printf("a : %d, : %d\n", a, b);
}
void StaticTest::SetData(int aa)
{
	a = aa;
	//this->a = aa;	//this ������ ��� �Ұ���(��ü ���� �����ϴ� �� �ƴϹǷ�)
}

int main()
{
	StaticTest s1;
	s1.GetData();
	StaticTest s2;
	s2.GetData();

	s1.SetData(35);	//a�� ��ȭ
	s1.GetData();
	s2.GetData();

	StaticTest::SetData(40); //Ŭ���� �Ҽ��̹Ƿ� Ŭ������ ���ؼ� ȣ�� ����
	s1.GetData();
	s2.GetData();

	return 0;
}