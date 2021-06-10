#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v = { 10, 20, 30, 40, 50 };
	
	//배열형태
	for (auto i = 0; i < v.size(); i++) //auto : 자동으로 컴파일러가 자료형을 맞춰 줌
	{
		cout << v[i] << ' ';  
	}
	printf("\n");
	
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << ' ';
	}
	printf("\n");

	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << ' ';
	}
	return 0;
}