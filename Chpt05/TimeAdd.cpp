#include<stdio.h>

class Time
{
private:
	int hour, min, sec;
public:
	//디폴트 생성자
	Time(){}
	//생성자
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	//멤버함수
	void OutTime()
	{
		printf("%d:%d:%d\n", hour, min, sec);
	}
	
	const Time AddTime(const Time&other)const
	{
		Time t;
		t.sec = sec + other.sec;
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		return t;
	}
};

int main()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	t3 = t1.AddTime(t2);
	t3.OutTime();
	return 0;
}