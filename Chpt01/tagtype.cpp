#include<stdio.h>

int main()
{
	enum origin { EAST, WEST, SOUTH, NORTH }; //enum : ������
	enum origin mark = WEST;
	printf("%d ����\n", mark);				  //WEST�� 1��° �������̹Ƿ� 1 ���

	struct SHuman
	{
		char name[12];
		int age;
		double height;
	};

	//struct SHuman lee = { "���°�", 26, 165 }; �� struct Ű���带 ������ �ʾƵ� ����������, ����ü���� ���� ����
	SHuman lee = { "���°�", 26, 165 };
	printf("�̸� = %s, ���� = %d\n", lee.name, lee.age);
}