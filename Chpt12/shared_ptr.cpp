#include<iostream>
using namespace std;

class CTest
{
public:
	CTest() { cout << "���� CTest()�Դϴ�." << endl; };
	~CTest() { cout << "���� ~CTest()�Դϴ�." << endl; };
	void func(){ cout << "���� func()�Դϴ�." << endl; }
};

int main()
{
	shared_ptr<CTest> ptr1(new CTest);
	ptr1->func();

	cout << "count : " << ptr1.use_count() << endl;
	{
		shared_ptr<CTest> ptr2(ptr1);//ptr2��� ����Ʈ�����͸� ����µ� ptr1 ����
		cout << "count : " << ptr1.use_count() << endl;
		ptr2->func();
	}
	cout << "count : " << ptr1.use_count() << endl;
	//{}�ȿ����� ptr2 ��밡��, �ۿ����� �ڵ����� �Ҵ� ����
	ptr1->func();

	unique_ptr<CTest>ptr1(new CTest);

	return 0;
}