#include<stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	//생성자1
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	//생성자2
	Time(int abssec)
	{
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime()
	{
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 30, 40); //인수 3개이므로 생성자1 호출
	now.OutTime();
	Time noon(44000);	 //인수 1개이므로 생성자2 호출
	noon.OutTime();
}
//어떤 생성자를 호출할지는 객체 선언문의 인수에 의해 결정
//인수가 다르면 여러개의 생성자 정의 가능