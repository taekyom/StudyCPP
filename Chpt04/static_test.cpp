#include<stdio.h>

class StaticTest
{
public:
	int a;
	static int b;	//static 멤버변수 선언, 객체 내에 존재X
	//생성자
	StaticTest()
	{
		a = 10;
		//b = 20;   //static 멤버변수는 클래스 내부에서 초기화 불가능
		b++;
	}
	
	void GetData()
	{
		printf("a = %d, b= %d\n", a, b);
	}

};

//int b = 20;			//소속이 없으므로 초기화 불가능
int StaticTest::b = 20; //static 멤버변수 초기화 : 클래스 외부에서 클래스 소속인 멤버변수임을 밝힘

int main()
{
	StaticTest s1;
	s1.GetData();
	StaticTest s2;
	s2.GetData();

	return 0;
}