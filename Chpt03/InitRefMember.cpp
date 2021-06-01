#include<stdio.h>

class Some
{
public:
	int& total;
	Some(int& atotal) : total(atotal) {} //const, 레퍼런스 : 콜론초기화를 통해 초기화해야 함
	void OutTotal()
	{
		printf("%d\n", total);
	}
};

int main()
{
	int value = 8;
	Some s(value);
	s.OutTotal();
}