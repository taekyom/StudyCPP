/*
	���۷����� �̿��� swap �Լ�
*/
#include<iostream>
using namespace std;

void swap(int&, int&);

int main()
{
	int a, b;  //���� �Լ� �ȿ����� ���� ���۷����� ������ �ʿ�X

	cout << "�� ���� �Է��ϼ��� : ";
	cin >> a;
	cin >> b;

	cout << "swap �� ��� : ";
	swap(a, b);			  //�Լ� ȣ���� ���� ���μ��� ȣ��, �Է¹��� ���� ���۷����� ����
	cout << a << " " << b;
}

void swap(int& a, int& b) //�Է¹��� ���� ���μ��� ���۷����� ����
{
	int tmp = a;
	a = b;
	b = tmp;	//tmp�� a�̹Ƿ� �ᱹ b = a�� ��

}
