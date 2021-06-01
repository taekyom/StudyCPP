#include<stdio.h>
//구조체 : default→public
//클래스 : default→private

struct Human //캡슐화, 추상화
{
private: //은닉(은폐) : 구조체 외부에서 멤버변수 초기화 및 수정 불가능하게 함
	char name[12];
	int age;
public:
	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human lee;
	//lee.age = 28; //불가능
	lee.intro();
}