/*	
	ȸ���̸�, ��ȭ��ȣ, �ּ�, cnt�� ��������� ���� CMember class ����
	1. cnt : �� ȸ����, ������������� ����
	2. ȸ�������� ��ü����� ���ÿ� �ʱ�ȭ

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class CMember
{
private:
	char name[12];
	char phone[20];
	char address[100];
	static int cnt;	//���� ������� ����
public:
	//����Ʈ ������
	//CMember()
	//{
	//	cnt++;
	//}
	////�ı���
	//~CMember()
	//{
	//	cnt--;
	//}

	CMember(const char *n, const char *p, const char *a)
	{
		strcpy(name, n);
		strcpy(phone, p);
		strcpy(address, a);
		cnt++;		//1�� ������ �Է��ϰ� ���� �Է� �� cnt++�Ǿ�� ���� ����
	}
	static void InitCnt()
	{
		cnt = 0;
	}
	static void OutCnt()
	{
		printf("�� ȸ���� : %d\n", cnt);
		printf("\n");
	}

	void GetData()
	{
		printf("ȸ�� ���� : %d, %s, %s, %s\n", cnt, name, phone, address);
	}
};

int CMember::cnt;	//���� ������� �ʱ�ȭ

int main()
{
	CMember::InitCnt(); //�� ó�� cnt = 0���� ����
	CMember c1("���°�", "010-7280-9231", "�λ걤���� �ؿ�뱸");
	c1.GetData();
	CMember::OutCnt();

	CMember c2("ȫ�浿", "010-1234-5678", "�λ걤���� ����");
	c2.GetData();
	CMember::OutCnt();

	CMember c3("��ö��", "010-1111-2222", "����Ư���� ������");
	c3.GetData();
	CMember::OutCnt();
	


	return 0;
}