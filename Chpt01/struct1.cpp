#include<iostream>

class Human	//����ü�� ����Լ��� �߰��� �� �� : class
{
public:
	char name[20];
	float height;
	float weight;
	int age;
	char blood;

	void view();	//����Լ�
};

void Human::view()	//::���� ���� ������, Human�̶�� Ŭ������ �Ҽӵ� view�Լ���� ���� ��Ÿ��, ::������ �����Լ��� �����	
{
	printf("���� �̸��� %s�̰� Ű�� %.2lfcm, �����Դ� %.2lfkg, ���̴� %d��, �������� %c���Դϴ�.", name, height, weight, age, blood);
}

int main()
{
	Human my = { "���°�", 165, 55, 26, 'A' };
	my.view();
	return 0;
}