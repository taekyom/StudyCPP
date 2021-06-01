#include<stdio.h>

class Date
{
private:
	int year, month, day;
public:
	void SetDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}

	void OutDate()
	{
		printf("오늘의 날짜는 %d년 %d월 %d일입니다.", year, month, day);
	}
};

int main()
{
	Date today;
	today.SetDate(2020, 05, 31);
	today.OutDate();
}