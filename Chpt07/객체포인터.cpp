#include<iostream>
using namespace std;

class A
{
public:
	void AFunc()
	{
		cout << "A::AFunc()" << endl;
	}
};

class B : public A
{
public:
	void BFunc()
	{
		cout << "B::BFunc()" << endl;
	}
};

class C : public B
{
public:
	void CFunc()
	{
		cout << "C::CFunc()" << endl;
	}
};

int main()
{
	A* pa = new C; //�θ� Ŭ���� A Ÿ���� �����Ͱ� �Ļ� ��ü(�ڽ�Ŭ���� Ÿ���� C��ü)�� ����Ŵ(�θ�� �ڽ��� ����ų �� ����)
	pa->AFunc();   

	//C* pcc = new A; //�ڽ� �����Ͱ� �θ� ��ü�� ����Ű�� ���� �Ұ���

	B* pb = new C; //C��� �ڽ� ��ü�� ����Ű���� BŬ���������� ��� ����(A�� ��� �Ұ���)
	pb->AFunc(); //Ŭ���� B�� A�� ��ӹ����Ƿ� pb�� AFunc, BFunc ��� ȣ�� ����
	pb->BFunc();
	
	C* pc = new C; 
	pc->AFunc(); //Ŭ���� C�� B�� ��ӹް�, Ŭ���� B�� A�� ��ӹ����Ƿ� pc�� AFunc, BFunc, CFunc ��� ȣ�� ����
	pc->BFunc();
	pc->CFunc();

	return 0;
}
//�θ�� �ڽ�Ŭ������ ���� ����
//�������� ������ ��� ������ �������� �ڷ����� ����
//ex. ������ pa�� C Ŭ������ ����, �������� �ڷ����� ������ A��ü(����)�� ��� ���� 
//ex. ������ pc�� C Ŭ������ ����, �������� �ڷ����� ������ C��ü(����)�� ��� ���� �� C��ü �ȿ� B, A��ü�� �����Ƿ� C, B, A ��� ��� ����
