#include<stdio.h>

class Some
{
private:
	mutable int temp; //mutable : ���ȭ��Ų ��������� ���� ���ܸ� ���� 
public:
	//����Ʈ ������
	Some(){}
	void method() const //����Լ��� ���ȭ : ������� ������ �� ����
	{
		temp = 0; //mutable�� ����Ʊ� ������ temp = 0; �ʱ�ȭ ����
	}
};

int main()
{
	Some s;
	s.method();

	const Some t;
	t.method();

	return 0;
}