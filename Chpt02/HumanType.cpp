#include<stdio.h>

class Human
{
public: //Ŭ���� �ܺο��� ����ϱ� ���� public ����
	char name[12];
	int age;

	void intro()
	{
		printf("�̸�=%s, ����=%d\n", name, age);
	}
};

int main()
{
	Human arFriend[10] = { {"������", 49}, {"������", 49}, {"ȫ�浿", 49} }; //Human Ÿ������ �迭 arFriend[10] ����
	Human* pFriend;			//�迭 ������ �� �Ѹ��� ������ ����Ŵ
	pFriend = &arFriend[1];	//arFriend�� 1��° ���� �ּҰ� �� ������
	pFriend->intro();
}