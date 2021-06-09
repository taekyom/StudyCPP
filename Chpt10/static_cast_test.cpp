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
public: //자식객체에서는 생략하면 private
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
	Base* pb = new Derived; //부모가 자식을 가리킴
	Derived* pd = NULL;

	pb->SetData(10); //부모클래스의 setData()
	pd = static_cast<Derived*>(pb); //static_cast
	pd->SetData(20); //자식클래스의 setData()
	pd->PrintData();
	return 0;
}