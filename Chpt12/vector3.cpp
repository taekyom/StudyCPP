#include<iostream>
#include<vector>
#include<algorithm> //sort를 사용하기 위한 헤더파일
using namespace std;

bool compare(int a, int b)
{
	return a > b; //내림차순 정렬
}

int main()
{
	vector<int>arr;
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(8);
	arr.push_back(2);

//	sort(arr.begin(), arr.end()); //오름차순 정렬(default)
	sort(arr.begin(), arr.end(), compare); //compare 함수를 호출해서 정렬하는 것
	for (auto i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}