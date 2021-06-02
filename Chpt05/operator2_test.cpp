#include<stdio.h>

class MyTest
{
private:
	int x, y;
public:
	MyTest() {}
	MyTest(int ax, int ay)
	{
		x = ax;
		y = ay;
		printf("인수 2개 생성자\n");
	}
	//복사 생성자
	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y) //콜론 초기화
	{
		printf("복사 생성자 호출!\n");
	}
	
	void printData()
	{
		printf("a = %d, b = %d\n", x, y);
	}

	const MyTest& operator+(const MyTest& other) const //출력이 &여야 임시객체 생성 안됨
	{
		MyTest mt; //객체 생성
		mt.x = this->x + other.x;
		mt.y = this->y + other.y;

		return mt;
	}
};

int main()
{
	MyTest m1(10, 20);
	MyTest m2(20, 30);
	MyTest m3;
	m3 = m1 + m2; //operator+함수를 사용했으므로 +기호를 사용한 연산 가능
	
	m3.printData();
	return 0;
}