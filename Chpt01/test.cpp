/*
	레퍼런스를 이용한 swap 함수
*/
#include<iostream>
using namespace std;

void swap(int&, int&);

int main()
{
	int a, b;  //같은 함수 안에서는 따로 레퍼런스를 선언할 필요X

	cout << "두 수를 입력하세요 : ";
	cin >> a;
	cin >> b;

	cout << "swap 후 출력 : ";
	swap(a, b);			  //함수 호출할 때는 실인수를 호출, 입력받을 때는 레퍼런스로 받음
	cout << a << " " << b;
}

void swap(int& a, int& b) //입력받을 때는 실인수를 레퍼런스로 받음
{
	int tmp = a;
	a = b;
	b = tmp;	//tmp가 a이므로 결국 b = a가 됨

}
