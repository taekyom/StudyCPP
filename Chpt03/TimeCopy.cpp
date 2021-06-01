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

	void OutTime()
	{
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	Time then = now; //then : 객체를 생성하고 now로 초기화
	//Time then(now); : 25행과 같음

	then.OutTime();
}
//똑같은 타입의 객체를 하나 더 생성하는 것 : 복사생성