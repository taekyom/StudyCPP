#include<Stdio.h>
#include<iostream>
using namespace std;

class Base
{
private:
	int data;
public:
	Base(){}
	~Base(){}
	void SetData(int adata)
	{
		data = adata;
	}
	int GetData()
	{
		return data;
	}
};

class Derived : public Base
{
public: //�ڽİ�ü������ �����ϸ� private
	void SetData(int adata)
	{
		if (adata > 0)
		{
			adata = 0;
		}
		Base::SetData(adata);
	}
	void PrintData()
	{
		cout << "PrintData() : " << GetData() << endl;
	}
};

int main()
{
	Base* pb = new Derived; //�θ� �ڽ��� ����Ŵ
	Derived* pd = NULL;

	pb->SetData(10); //�θ�Ŭ������ setData()
	pd = static_cast<Derived*>(pb); //static_cast
	pd->SetData(20); //�ڽ�Ŭ������ setData()
	pd->PrintData();
	return 0;
}