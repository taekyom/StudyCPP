#include<stdio.h>

class Time
{
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s)
	{
		SetTime(h, m, s);
	}

	void SetTime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() const
	{
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
	//const int func();	 //출력을 상수화 시킬 때 
	//void func() const; //멤버 함수 자체를 const 상수화 시킬 때, 이 함수 안에 있는 멤버 변수는 건드릴 수 없다는 것 의미(멤버변수 값이 변경되면 안될 때)

};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 12, 13);
	now.OutTime();

	const Time meeting(16, 00, 00);	//const 클래스 객체 : 객체를 상수화시키는 것 → 상수화된 멤버변수만 사용 가능, 일반 멤버변수는 접근 불가능
	//meeting.SetTime(17, 00, 00);
	meeting.OutTime();
	return 0;
}