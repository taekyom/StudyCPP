#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

class Date
{
protected:
	int year, month, day;
public:
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void OutDate()
	{
		printf("%d/%d/%d", year, month, day);
	}
};

class Time
{
protected:
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
		printf("%d:%d:%d", hour, min, sec);
	}
};

class DateTime : public Date, public Time //���߻�� : ��ӹ޴� Ŭ������ �޸��� ����
{
private:
	bool bEngMessage;
	int milisec;
public:
	DateTime(int y, int m, int d, int h, int min, int s, int ms, bool b = false) : Date(y, m, d), Time(h, min, s)
	{
		milisec = ms;
		bEngMessage = b;
	}
	void OutNow()
	{
		printf(bEngMessage ? "Now is" : "������ ");
		OutDate();
		_putch(' ');
		OutTime();
		printf(".%d", milisec);
		puts(bEngMessage ? "." : "�Դϴ�.");
	}
};

int main()
{
	DateTime Now(2021, 06, 04, 9, 39, 26, 89);
	Now.OutNow();
	return 0;
}