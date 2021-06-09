#include<stdio.h>
#include<iostream>

class A
{
public:
	virtual void test()
	{
		printf("A::test()\n");
	}

};

class B : public A
{
public:
	virtual void test()
	{
		printf("B::test()\n");
	}
	void test2()
	{
		printf("B::test2()\n");
	}
};

class C : public B
{
public:
	virtual void test()
	{
		printf("C::test()\n");
	}
	void test2()
	{
		printf("C::test2()\n");
	}
};

void GlobalFunc(A& a)
{
	try
	{
		C& c = dynamic_cast<C&>(a);
		printf("GlobalFunc()\n");
	}
	catch (std::bad_cast)
	{
		printf("casting error\n");
	}
}

int main()
{
	A* pa = new C;
	A* paa = new B;
	pa->test();
	B* pb = dynamic_cast<B*>(pa);
	if (pb)
	{
		pb->test2();
	}
	C* pc = dynamic_cast<C*>(paa);	//자식포인터로 부모객체를 가리키는 형태(불완전한 캐스팅)
	if (pc)
	{
		pc->test2();
	}

	C c;
	GlobalFunc(c);
	B b;
	GlobalFunc(b);


	return 0;
}