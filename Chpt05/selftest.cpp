#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char* name;
	int age;
public:
	Human(){}
	Human(const char* aname, const int aage)
	{
		name = new char[strlen(aname) + 1]; //�����Ҵ� : name�� �迭�̹Ƿ� NULL�� ��ŭ +1 ����� ��
		strcpy(name, aname);
		this->age = aage;
	}
	Human(const Human &other) //���������
	{
		name = new char[strlen(other.name) + 1]; //�����Ҵ� : name�� �迭�̹Ƿ� NULL�� ��ŭ +1 ����� ��
		strcpy(name, other.name);
		this->age = other.age;
	}
	~Human() //�����Ҵ� ����
	{
		delete[] name;
	}
	const Human operator=(const Human &other)
	{
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
		return *this;
	}

	void printHuman()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human myH("���°�", 26);
	Human youH(myH);
	Human Xman;
	Xman = myH;

	myH.printHuman();
	youH.printHuman();
	Xman.printHuman();

	return 0;
}