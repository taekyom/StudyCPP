#include<iostream>

class Human	//구조체에 멤버함수가 추가로 들어간 것 : class
{
public:
	char name[20];
	float height;
	float weight;
	int age;
	char blood;

	void view();	//멤버함수
};

void Human::view()	//::범위 지정 연산자, Human이라는 클래스에 소속된 view함수라는 것을 나타냄, ::없으면 전역함수로 선언됨	
{
	printf("나의 이름은 %s이고 키는 %.2lfcm, 몸무게는 %.2lfkg, 나이는 %d살, 혈액형은 %c형입니다.", name, height, weight, age, blood);
}

int main()
{
	Human my = { "이태경", 165, 55, 26, 'A' };
	my.view();
	return 0;
}