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
		name = new char[strlen(aname) + 1]; //동적할당 : name이 배열이므로 NULL값 만큼 +1 해줘야 함
		strcpy(name, aname);
		this->age = aage;
	}
	Human(const Human &other) //복사생성자
	{
		name = new char[strlen(other.name) + 1]; //동적할당 : name이 배열이므로 NULL값 만큼 +1 해줘야 함
		strcpy(name, other.name);
		this->age = other.age;
	}
	~Human() //동적할당 해제
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
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human myH("이태경", 26);
	Human youH(myH);
	Human Xman;
	Xman = myH;

	myH.printHuman();
	youH.printHuman();
	Xman.printHuman();

	return 0;
}