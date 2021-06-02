#include<stdio.h>

class MyTest
{
private:
	int x, y;
public:
	MyTest() {}
	MyTest(int ax, int ay)
	{
		x = ax;
		y = ay;
		printf("�μ� 2�� ������\n");
	}
	//���� ������
	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y) //�ݷ� �ʱ�ȭ
	{
		printf("���� ������ ȣ��!\n");
	}
	
	void printData()
	{
		printf("a = %d, b = %d\n", x, y);
	}

	const MyTest& operator+(const MyTest& other) const //����� &���� �ӽð�ü ���� �ȵ�
	{
		MyTest mt; //��ü ����
		mt.x = this->x + other.x;
		mt.y = this->y + other.y;

		return mt;
	}
};

int main()
{
	MyTest m1(10, 20);
	MyTest m2(20, 30);
	MyTest m3;
	m3 = m1 + m2; //operator+�Լ��� ��������Ƿ� +��ȣ�� ����� ���� ����
	
	m3.printData();
	return 0;
}