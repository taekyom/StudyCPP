#include<stdio.h>
using namespace std;

template<typename T, int SZ>
class CTest
{
private:
	T ary[SZ];
public:
	T& operator[](int idx)
	{
		if (idx < 0 || idx >= SZ)
		{
			cout << "error" << endl;
			exit(1);
		}
		return ary[idx];
	}
	void getData()
	{
		for (int i = 0; i < SZ; i++)
		{
			cout << ary[i] << endl;
		}
	}
};

int main()
{
	CTest<int, 3> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[20] = 30;
	arr.getData();
	return 0;
}