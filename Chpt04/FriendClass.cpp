#include<stdio.h>

class Date;
class Time
{
private:
	int hour, min, sec;
public:
	friend class Date;	//friend 클래스 

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
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void OutToday(Time &t)
	{
		printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
			year, month, day, t.hour, t.min, t.sec);
	}
};

int main()
{
	Date d(2021, 06, 01);
	Time t(12, 34, 56);
	d.OutToday(t);
	return 0;
}