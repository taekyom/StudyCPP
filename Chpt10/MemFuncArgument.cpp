#define _CRT_SECURE_NO_WARNINGS
#include<Stdio.h>

class Calc
{
public:
	void Op1(int a, int b) { printf("%d\n", a + b); }
	void Op2(int a, int b) { printf("%d\n", a - b); }
	void Op3(int a, int b) { printf("%d\n", a * b); }
	void DoCalc(void (Calc::* fp)(int, int), int a, int b)
	{
		puts("지금부터 연산결과를 발표하겠습니다.\n");
		printf("%d와 %d의 연산결과 : ", a, b);
		(this->*fp)(a, b); //전달받은 멤버함수 호출
		puts("이상입니다.");
	}
};

int main()
{
	int ch;
	Calc C;
	int a = 3, b = 4;
	void (Calc:: * arop[3])(int, int) = { &Calc::Op1, &Calc::Op2, &Calc::Op3 }; //포인터 배열

	printf("연산 방법을 선택하시오. 0=더하기, 1=빼기, 2=곱하기 : ");
	scanf("%d", &ch);

	if (ch >= 0 && ch <= 2)
	{
		C.DoCalc(arop[ch], a, b);
	}
	return 0;
}
