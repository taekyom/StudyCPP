#include<stdio.h>

class Some
{
private:
	mutable int temp; //mutable : 상수화시킨 멤버변수에 대해 예외를 지정 
public:
	//디폴트 생성자
	Some(){}
	void method() const //멤버함수를 상수화 : 멤버변수 변경할 수 없음
	{
		temp = 0; //mutable로 선언됐기 때문에 temp = 0; 초기화 가능
	}
};

int main()
{
	Some s;
	s.method();

	const Some t;
	t.method();

	return 0;
}