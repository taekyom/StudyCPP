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
	Simple A(1), B(2); //SimpleŸ���� ��ü A, B 2�� ����
	A.OutValue();
	B.OutValue();

	return 0;
}