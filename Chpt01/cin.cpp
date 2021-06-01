#include<iostream>
using namespace std;

int main()
{
	int age;
	cout << "나이를 입력하세요 : ";
	cin >> age;										 //정수값을 입력받아 age변수로 보낸다
	cout << "당신은 " << age << "살입니다." << endl;
}
// << : 출력 시 객체로 보내는 형식, >> : 입력받을 때 값을 변수로 보내는 모양