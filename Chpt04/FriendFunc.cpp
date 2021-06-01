#include<stdio.h>

class Date;	//Ŭ������ ���� : Ŭ������ 1�� �̻� ���� ���� �Լ�ó�� �� ���� Ŭ������ ������ ����
class Time
{
private:
	int hour, min, sec;
public:
	friend void OutToday(Date&, Time&);	//������ �Լ� : OutToday��� ���������� ������ȭ
	
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
};

class Date
{
private:
	int year, month, day;
public:
	friend void OutToday(Date&, Time&); //������ �Լ�

	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};

void OutToday(Date& d, Time& t) //���۷��� ���, friend Ű����� �������� ���
{
	printf("������ %d�� %d�� %d���̸� ���� �ð��� %d:%d:%d�Դϴ�.\n",
		d.year, d.month, d.day, t.hour, t.min, t.sec); //������ȭ �߱� ������ private�� ��������� ���������� �ǵ帱 �� ����
}

int main()
{
	Date d(2021, 06, 01);
	Time t(12, 34, 56);
	OutToday(d, t);
	return 0;
}