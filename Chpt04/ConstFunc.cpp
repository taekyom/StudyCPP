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
		printf("���� �ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
	//const int func();	 //����� ���ȭ ��ų �� 
	//void func() const; //��� �Լ� ��ü�� const ���ȭ ��ų ��, �� �Լ� �ȿ� �ִ� ��� ������ �ǵ帱 �� ���ٴ� �� �ǹ�(������� ���� ����Ǹ� �ȵ� ��)

};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 12, 13);
	now.OutTime();

	const Time meeting(16, 00, 00);	//const Ŭ���� ��ü : ��ü�� ���ȭ��Ű�� �� �� ���ȭ�� ��������� ��� ����, �Ϲ� ��������� ���� �Ұ���
	//meeting.SetTime(17, 00, 00);
	meeting.OutTime();
	return 0;
}