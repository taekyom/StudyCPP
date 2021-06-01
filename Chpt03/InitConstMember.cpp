#include<stdio.h>

class Some
{
public:
	const int total;	//const 예약어(형변환)은 선언과 동시에 초기화하지 않으면 그 후에 초기화 불가능
	Some(int atotal) : total(atotal) {}	//초기화 리스트 방식
	/*Some(int atotal)  //일반적인 대입연산을 통한 초기화 방식 불가능
	{
		total = atotal;
	}*/
	void OutTotal()
	{
		printf("%d\n", total);
	}
};

int main()
{
	Some s(5); //Some 타입의 객체 s 선언
	s.OutTotal();
	return 0;
}