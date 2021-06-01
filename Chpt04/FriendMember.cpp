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
	friend void Date::OutToday(Time& t); //friend ����Լ�

	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
};

void Date::OutToday(Time &t)
{
	printf("������ %d�� %d�� %d���̰� ���� �ð��� %d:%d:%d�Դϴ�.\n", year, month, day, t.hour, t.min, t.sec);
}

int main()
{
	Date d(2021, 06, 01);
	Time t(12, 34, 56);
	d.OutToday(t);

	return 0;
}