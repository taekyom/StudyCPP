#include<stdio.h>

int count = 0;	//���� ��� ����(��������) : Ŭ���� �ۿ� ����, Ŭ���� �Ҽ�
				//Simple Ÿ���� ��ü�� � �����Ǿ����� ����
class Simple
{
private:
	int value;
public:
	//������
	Simple()
	{
		count++;
	}
	//�ı���
	~Simple()
	{
		count--;
	}
	void OutCount()	//����Լ� ����
	{
		printf("���� ��ü ���� = %d\n", count);
	}
};

int main()
{
	Simple s, * ps;  //simpleŸ���� ��ü s, *ps ����
	s.OutCount();
	ps = new Simple;
	ps->OutCount();
	delete ps;
	s.OutCount();
	printf("ũ�� = %d\n", sizeof(s));
	return 0;
}