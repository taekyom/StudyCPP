#include<stdio.h>
//����ü : default��public
//Ŭ���� : default��private

struct Human //ĸ��ȭ, �߻�ȭ
{
private: //����
	char name[12];
	int age;
public:
	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human lee;
	lee.intro();
}