#include<stdio.h>

class MathCalc
{
private:
	const double pie;
public:
	MathCalc(double apie) : pie(apie) {}	//��� ����� �ݷ� �ʱ�ȭ
	void DoCalc(double r)
	{
		printf("������ %.2f�� ���� �ѷ� = %.2f\n", r, r * 2 * pie);
	}
};

int main()
{
	MathCalc m(3.1416);
	m.DoCalc(5);
	return 0;
}