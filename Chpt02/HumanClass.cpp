#include<stdio.h>

class Human //클래스(확장된 구조체)
{
public:     //클래스는 기본적으로 private이므로 외부에서 사용하려면 pubilc으로 지정
	char name[12];
	int age;

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human lee = { "이태경", 26 };
	lee.intro();

	return 0;
}