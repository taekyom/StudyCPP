#include<stdio.h>

class Time
{
private:
	int hour, min, sec;
public:
	void SetTime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	void OutTime()
	{
		printf("현재 시간은 %d:%d:%d입니다.", hour, min, sec);
	}
};

int main()
{
	Time now;	//타입이 Time인 객체 now(변수) 선언
				//객체=변수, 클래스 타입으로 선언된 변수=인스턴스
	now.SetTime(12, 30, 40);
	now.OutTime();
}