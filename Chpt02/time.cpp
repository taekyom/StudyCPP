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
		printf("���� �ð��� %d:%d:%d�Դϴ�.", hour, min, sec);
	}
};

int main()
{
	Time now;	//Ÿ���� Time�� ��ü now(����) ����
				//��ü=����, Ŭ���� Ÿ������ ����� ����=�ν��Ͻ�
	now.SetTime(12, 30, 40);
	now.OutTime();
}