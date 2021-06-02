#include<stdio.h>

class StaticTest
{
	static int a;	//static 멤버변수 선언 → this 포인터 사용 불가능(객체 내에 존재하는게 아니므로)
	int b;

public:
	//디폴트 생성자
	StaticTest();
	//static 멤버함수 : static 멤버변수를 사용하기 위함
	static void SetData(int);	

	void GetData();
};

int StaticTest::a = 10;			//static 멤버변수 초기화(클래스 외부)

StaticTest::StaticTest()
{
	this->b = 20;
}
void StaticTest::GetData()
{
	printf("a : %d, : %d\n", a, b);
}
void StaticTest::SetData(int aa)
{
	a = aa;
	//this->a = aa;	//this 포인터 사용 불가능(객체 내에 존재하는 게 아니므로)
}

int main()
{
	StaticTest s1;
	s1.GetData();
	StaticTest s2;
	s2.GetData();

	s1.SetData(35);	//a값 변화
	s1.GetData();
	s2.GetData();

	StaticTest::SetData(40); //클래스 소속이므로 클래스를 통해서 호출 가능
	s1.GetData();
	s2.GetData();

	return 0;
}