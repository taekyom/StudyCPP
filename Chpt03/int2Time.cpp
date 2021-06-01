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

	//explicit : ������� ��ȯ�� �㰡(�Ϲ��� ��ȯx)
	explicit Time(int abssec)	//��ȯ ������ : �ӽ� ��ü(abssec)�� �����Ͽ� ��ȯ�ϰ� ����� ����
	{
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime()
	{
		printf("����ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

void printTime(Time when)
{
	when.OutTime();
}

int main()
{
	Time noon(40000); //����� ��ȯ
	noon.OutTime();
	//noon = 70000;     //�Ϲ��� ��ȯ(��ȣ�� ����)
	/*Time now = 60000;
	now.OutTime();
	now = 70000;
	now.OutTime();

	printTime(80000);*/
	return 0;
}