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
	const MyTest& operator-(const MyTest &other)const
	{
		MyTest mt;
		mt.x = this->x - other.x;
		mt.y = this->y - other.y;

		return mt;
	}
};

int main()
{
	MyTest m1(40, 50);
	MyTest m2(15, 25);
	MyTest m3;
	m3 = m1 - m2;
	m3.printData();
	return 0;
}