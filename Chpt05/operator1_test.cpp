#include<iostream>

class MyTest
{
private:
	int x, y;
public:
	//디폴트 생성자
	MyTest(){}

	MyTest(int ax, int ay)
	{
		x = ax;
		y = ay;
	}

	void printData()
	{
		printf("a : %d, b : %d", x, y);
	}
	const MyTest sum(const MyTest &other)const
	{
		MyTest m;
		m.x = this->x + other.x;
		m.y = this->y + other.y;

		return m;
	}
};


int main()
{
	MyTest obj1(10, 20);
	MyTest obj2(20, 30);
	MyTest obj;
	obj = obj1.sum(obj2);
	obj1.printData();
	return 0;
}