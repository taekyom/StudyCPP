#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>v;
	vector<int>v1 = { 1, 2, 3, 4, 5 };
	vector<int>v2[5];

	v.push_back(10);
	vector<int>::iterator iter = v.begin(); //iterator : 포인터같은 객체 생성, iter로 v로 만든 vector에 접근 가능
	iter = v.insert(iter, 2); //v라는 vector에 맨 처음 2를 집어넣으라는 것

	v.pop_back();//맨 마지막에 있는 원소가 자동으로 삭제
	v.erase(v.begin() + 10);
	v.clear();
}
vector<int>arr;