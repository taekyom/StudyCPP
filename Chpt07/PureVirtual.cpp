#include<stdio.h>

class Shape
{
public:
	virtual void draw() = 0; //순수가상함수 : 상속받은 클래스가 꼭 사용해야 함(강제성 O)
};

class Line : public Shape
{
public:
	virtual void draw() //가상함수 : 상속받은 클래스가 꼭 사용하지 않아도 ok
	{
		puts("선을 긋습니다.");
	}
};

class Circle : public Shape
{
public:
	virtual void draw()
	{
		puts("동그라미 그렸다 치고");
	}
};

class Rect : public Shape
{
public:
	virtual void draw()
	{
		puts("요건 사각형입니다.");
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