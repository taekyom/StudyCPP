#include<stdio.h>

class MyTest
{
private:
	int x, y;
public:
	MyTest(){}
	MyTest(int ax, int ay)
	{
		x = ax;
		y = ay;
	}

	void printData()
	{
		printf("a = %d, b = %d\n", x, y);
	}
	//const MyTest& operator-(const MyTest &other)const
	//{
	//	MyTest mt;
	//	mt.x = this->x - other.x;
	//	mt.y = this->y - other.y;

	//	return mt;
	//}
	
	friend const MyTest operator-(const MyTest& rhs1, const MyTest& rhs2); //friend 키워드 사용해야 함
};

//전역 연산자 함수
const MyTest operator-(const MyTest& rhs1, const MyTest& rhs2)
{
	MyTest res;
	res.x = rhs1.x - rhs2.x;
	res.y = rhs1.y - rhs2.y;
	return res;
}

int main()
{
	MyTest m1(40, 50);
	MyTest m2(15, 25);
	MyTest m3;
	//m3 = m1 - m2;
	m3 = operator-(m1, m2);
	m3.printData();

	return 0;
}