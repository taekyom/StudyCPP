#include<stdio.h>

class Simple
{
private:
	int value;
public:
	Simple(int avalue) : value(avalue){}
	void OutValue()
	{
		printf("value = %d\n", value);
	}
};

int main()
{
	Simple A(1), B(2); //Simple타입의 객체 A, B 2개 생성
	A.OutValue();
	B.OutValue();

	return 0;
}