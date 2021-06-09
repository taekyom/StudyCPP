#include<Stdio.h>

class Parent
{
public:
	virtual void PrintMe()
	{
		printf("I am Parent.\n");
	}
};

class Child : public Parent
{
private:
	int num;
public:
	Child(int anum) : num(anum){}
	virtual void PrintMe()
	{
		printf("I am Child.\n");
	}
	void PrintNum()
	{
		printf("Hello Child = %d\n", num);
	}
};

void func(Parent *p)
{
	p->PrintMe();
	((Child*)p)->PrintNum(); //자식객체의 포인터로 강제 형변환, 자식객체의 포인터가 자식객체를 가리킴
}

int main()
{
	Parent p;
	Child c(5);

	func(&c);
	func(&p);

	return 0;
}