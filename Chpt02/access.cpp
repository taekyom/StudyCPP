#include<stdio.h>
//����ü : default��public
//Ŭ���� : default��private

struct Human //ĸ��ȭ, �߻�ȭ
{
private: //����(����) : ����ü �ܺο��� ������� �ʱ�ȭ �� ���� �Ұ����ϰ� ��
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
	//lee.age = 28; //�Ұ���
	lee.intro();
}