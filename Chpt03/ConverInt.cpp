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
	Time(int abssec)
	{
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}
	operator int()	//operator : 변환함수, int : 변환타입, {} : 본체
	{
		return hour * 3600 + min * 60 + sec;
	}
	//변환함수의 변환 대상 : 자기 자신, 변환결과 : 지정한 타입 → 인수와 리턴값 모두 생략

	void OutTime()
	{
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	int i = now;
	printf("i=%d\n", i);

	return 0;
}