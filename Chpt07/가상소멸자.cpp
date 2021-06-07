#include<iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int anum)
	{
		num = anum;
		cout << num << "CTest constructor" << endl;
	}
	virtual ~CTest()
	{
		cout << num << "CTest destructor" << endl;
	}
	void func()
	{
		cout << "CTest func()" << endl;
	}
};
class CTestSub : public CTest
{
	//상속클래스에서 접근지정자 설정 안하면 자동으로 private
	int subN;
public:
	CTestSub(int anum, int asubN) : CTest(anum)
	{
		subN = asubN;
		cout << subN << "CTestSub constructor" << endl;
	}
	~CTestSub()
	{
		cout << subN << "CTestSub destructor" << endl;
	}
	void func()
	{
		cout << "CTestSub func()" << endl;
	}
};

int main()
{
	CTest b(10);
	b.func();
	CTestSub d(10, 20);
	d.func();

	CTest* pb = new CTestSub(30, 33); //추상자료형으로 자식객체를 가리킴
	pb->func();

	delete pb;

	return 0;
}