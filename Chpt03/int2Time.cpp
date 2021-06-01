#include<stdio.h>

class Time
{
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	//explicit : 명시적인 변환만 허가(암묵적 변환x)
	explicit Time(int abssec)	//변환 생성자 : 임시 객체(abssec)를 생성하여 변환하고 멤버에 대입
	{
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime()
	{
		printf("현재시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

void printTime(Time when)
{
	when.OutTime();
}

int main()
{
	Time noon(40000); //명시적 변환
	noon.OutTime();
	//noon = 70000;     //암묵적 변환(모호성 존재)
	/*Time now = 60000;
	now.OutTime();
	now = 70000;
	now.OutTime();

	printTime(80000);*/
	return 0;
}