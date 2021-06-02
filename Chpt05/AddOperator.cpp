#include<stdio.h>

class Time
{
private:
	int hour, min, sec;
public:
	Time(){}
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	void OutTime()
	{
		printf("%d:%d:%d\n", hour, min, sec);
	}

	//operator +가 함수이름(연산자 함수) : + 연산자를 활용해 연산을 할 함수(ex. -연산 함수 : operator -, x연산 함수 : operator *)
	const Time operator +(const Time &other) const //맨 뒤에 있는 const : Time안의 값(hour, min, sec)을 상수화, other : 자기 자신이 아닌 것(t2)
	{
		Time t;
		t.sec = sec + other.sec;
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.hour / 60;
		t.min %= 60;
		return t;
	}
};

int main()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	t3 = t1 + t2;	//연산자 함수는 기본 객체 연산과 같은 형태로 나타냄
	//t3 = t1.operator+(t2);
	t3.OutTime();
	return 0;
}