#include<iostream>
using namespace std;

class CTest
{
public:
	CTest() { cout << "나는 CTest()입니다." << endl; };
	~CTest() { cout << "나는 ~CTest()입니다." << endl; };
	void func(){ cout << "나는 func()입니다." << endl; }
};

int main()
{
	shared_ptr<CTest> ptr1(new CTest);
	ptr1->func();

	cout << "count : " << ptr1.use_count() << endl;
	{
		shared_ptr<CTest> ptr2(ptr1);//ptr2라는 스마트포인터를 만드는데 ptr1 복사
		cout << "count : " << ptr1.use_count() << endl;
		ptr2->func();
	}
	cout << "count : " << ptr1.use_count() << endl;
	//{}안에서만 ptr2 사용가능, 밖에서는 자동으로 할당 해제
	ptr1->func();

	unique_ptr<CTest>ptr1(new CTest);

	return 0;
}