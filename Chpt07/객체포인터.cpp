#include<iostream>
using namespace std;

class A
{
public:
	void AFunc()
	{
		cout << "A::AFunc()" << endl;
	}
};

class B : public A
{
public:
	void BFunc()
	{
		cout << "B::BFunc()" << endl;
	}
};

class C : public B
{
public:
	void CFunc()
	{
		cout << "C::CFunc()" << endl;
	}
};

int main()
{
	A* pa = new C; //부모 클래스 A 타입의 포인터가 파생 객체(자식클래스 타입의 C객체)를 가리킴(부모는 자식을 가리킬 수 있음)
	pa->AFunc();   

	//C* pcc = new A; //자식 포인터가 부모 객체를 가리키는 것은 불가능

	B* pb = new C; //C라는 자식 객체를 가리키지만 B클래스까지만 사용 가능(A는 사용 불가능)
	pb->AFunc(); //클래스 B가 A를 상속받으므로 pb는 AFunc, BFunc 모두 호출 가능
	pb->BFunc();
	
	C* pc = new C; 
	pc->AFunc(); //클래스 C가 B를 상속받고, 클래스 B는 A를 상속받으므로 pc는 AFunc, BFunc, CFunc 모두 호출 가능
	pc->BFunc();
	pc->CFunc();

	return 0;
}
//부모는 자식클래스에 접근 가능
//실질적인 데이터 사용 범위는 포인터의 자료형을 따라감
//ex. 포인터 pa는 C 클래스에 접근, 포인터의 자료형과 동일한 A객체(영역)만 사용 가능 
//ex. 포인터 pc는 C 클래스에 접근, 포인터의 자료형과 동일한 C객체(영역)만 사용 가능 → C객체 안에 B, A객체가 있으므로 C, B, A 모두 사용 가능
