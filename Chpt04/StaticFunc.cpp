#include<stdio.h>

class Simple
{
private:
	int value;
	static int count;	//정적 멤버변수 선언
public:
	//디폴트 생성자
	Simple()
	{
		count++;
	}
	//파괴자
	~Simple()
	{
		count--;
	}
	//정적 멤버함수
	static void InitCount()	
	{
		count = 0;
	}
	static void OutCount()
	{
		printf("현재 객체 개수 = %d\n", count);
	}
	
};

int Simple::count;	//정적 멤버변수 초기화

int main()
{
	//카운트0
	Simple::InitCount();
	Simple::OutCount();

	//카운트1
	Simple s, * ps;		//Simple 타입의 객체 s, *ps 생성
	Simple::OutCount();

	//카운트2
	ps = new Simple;
	Simple::OutCount();

	//카운트1
	delete ps;
	Simple::OutCount();

	//카운트0
	printf("크기 = %d\n", sizeof(s));

	return 0;
}