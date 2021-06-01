#include<stdio.h>

class Time;
class Date
{
private:
	int year, month, day;
public:
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void OutToday(Time &t);
};

class Time
{
private:
	int hour, min, sec;
public:
	friend void Date::OutToday(Time& t); //friend 멤버함수

	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
};

void Date::OutToday(Time &t)
{
	printf("오늘은 %d년 %d월 %d일이고 지금 시간은 %d:%d:%d입니다.\n", year, month, day, t.hour, t.min, t.sec);
}

int main()
{
	Date d(2021, 06, 01);
	Time t(12, 34, 56);
	d.OutToday(t);

	return 0;
}