#include<stdio.h>

class Date;	//클래스의 원형 : 클래스를 1개 이상 만들 때는 함수처럼 맨 위에 클래스의 원형을 선언
class Time
{
private:
	int hour, min, sec;
public:
	friend void OutToday(Date&, Time&);	//프렌드 함수 : OutToday라는 전역변수를 프렌드화
	
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
};

class Date
{
private:
	int year, month, day;
public:
	friend void OutToday(Date&, Time&); //프렌드 함수

	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};

void OutToday(Date& d, Time& t) //레퍼런스 사용, friend 키워드는 원형에만 사용
{
	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
		d.year, d.month, d.day, t.hour, t.min, t.sec); //프렌드화 했기 때문에 private인 멤버변수를 직접적으로 건드릴 수 있음
}

int main()
{
	Date d(2021, 06, 01);
	Time t(12, 34, 56);
	OutToday(d, t);
	return 0;
}