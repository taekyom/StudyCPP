#include<stdio.h>

int count = 0;	//정적 멤버 변수(전역변수) : 클래스 밖에 선언, 클래스 소속
				//Simple 타입의 객체가 몇개 생성되었는지 관리
class Simple
{
private:
	int value;
public:
	//생성자
	Simple()
	{
		count++;
	}
	//파괴자
	~Simple()
	{
		count--;
	}
	void OutCount()	//멤버함수 선언
	{
		printf("현재 객체 개수 = %d\n", count);
	}
};

int main()
{
	Simple s, * ps;  //simple타입의 객체 s, *ps 생성
	s.OutCount();
	ps = new Simple;
	ps->OutCount();
	delete ps;
	s.OutCount();
	printf("크기 = %d\n", sizeof(s));
	return 0;
}