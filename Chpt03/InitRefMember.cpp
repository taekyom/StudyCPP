#include<stdio.h>

class Some
{
public:
	int& total;
	Some(int& atotal) : total(atotal) {} //const, ���۷��� : �ݷ��ʱ�ȭ�� ���� �ʱ�ȭ�ؾ� ��
	void OutTotal()
	{
		printf("%d\n", total);
	}
};

int main()
{
	int value = 8;
	Some s(value);
	s.OutTotal();
}