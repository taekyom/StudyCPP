#include<stdio.h>

class Human
{
public:
	char name[12];
	int age;

	void intro()
	{
		printf("�̸�=%s, ����=%d\n", name, age);
	}
};

int main()
{
	Human arFriend[10] = { {"������", 49}, {"������", 49}, {"ȫ�浿", 49} };
	Human* pFriend;			//�Ѹ��� ������ ����Ŵ
	pFriend = &arFriend[1];	//arFriend�� 1��° ���� �ּҰ��� ����Ŵ
	pFriend->intro();
}