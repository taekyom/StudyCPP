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

	//operator +�� �Լ��̸�(������ �Լ�) : + �����ڸ� Ȱ���� ������ �� �Լ�(ex. -���� �Լ� : operator -, x���� �Լ� : operator *)
	const Time operator +(const Time &other) const //�� �ڿ� �ִ� const : Time���� ��(hour, min, sec)�� ���ȭ, other : �ڱ� �ڽ��� �ƴ� ��(t2)
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

	t3 = t1 + t2;	//������ �Լ��� �⺻ ��ü ����� ���� ���·� ��Ÿ��
	//t3 = t1.operator+(t2);
	t3.OutTime();
	return 0;
}