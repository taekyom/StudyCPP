#include<stdio.h>

class Some
{
public:
	const int total;	//const �����(����ȯ)�� ����� ���ÿ� �ʱ�ȭ���� ������ �� �Ŀ� �ʱ�ȭ �Ұ���
	Some(int atotal) : total(atotal) {}	//�ʱ�ȭ ����Ʈ ���
	/*Some(int atotal)  //�Ϲ����� ���Կ����� ���� �ʱ�ȭ ��� �Ұ���
	{
		total = atotal;
	}*/
	void OutTotal()
	{
		printf("%d\n", total);
	}
};

int main()
{
	Some s(5); //Some Ÿ���� ��ü s ����
	s.OutTotal();
	return 0;
}