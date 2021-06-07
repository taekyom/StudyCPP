#include<stdio.h>

class Shape
{
public:
	virtual void draw() = 0; //���������Լ� : ��ӹ��� Ŭ������ �� ����ؾ� ��(������ O)
};

class Line : public Shape
{
public:
	virtual void draw() //�����Լ� : ��ӹ��� Ŭ������ �� ������� �ʾƵ� ok
	{
		puts("���� �߽��ϴ�.");
	}
};

class Circle : public Shape
{
public:
	virtual void draw()
	{
		puts("���׶�� �׷ȴ� ġ��");
	}
};

class Rect : public Shape
{
public:
	virtual void draw()
	{
		puts("��� �簢���Դϴ�.");
	}
};

int main()
{
	Shape* pS[3];

	pS[0] = new Line;
	pS[1] = new Circle;
	pS[2] = new Rect;

	for (int i = 0; i < 3; i++)
	{
		pS[i]->draw();
	}

	for (int i = 0; i < 3; i++)
	{
		delete pS[i];
	}

	return 0;
}