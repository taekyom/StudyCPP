#include<iostream>
#include<vector>
#include<algorithm> //sort�� ����ϱ� ���� �������
using namespace std;

bool compare(int a, int b)
{
	return a > b; //�������� ����
}

int main()
{
	vector<int>arr;
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(8);
	arr.push_back(2);

//	sort(arr.begin(), arr.end()); //�������� ����(default)
	sort(arr.begin(), arr.end(), compare); //compare �Լ��� ȣ���ؼ� �����ϴ� ��
	for (auto i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}