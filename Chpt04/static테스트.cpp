/*	
	회원이름, 전화번호, 주소, cnt를 멤버변수로 갖는 CMember class 설계
	1. cnt : 총 회원수, 정적멤버변수로 선언
	2. 회원정보는 객체선언과 동시에 초기화

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

class CMember
{
private:
	char name[12];
	char phone[20];
	char address[100];
	static int cnt;	//정적 멤버변수 선언
public:
	//디폴트 생성자
	//CMember()
	//{
	//	cnt++;
	//}
	////파괴자
	//~CMember()
	//{
	//	cnt--;
	//}

	CMember(const char *n, const char *p, const char *a)
	{
		strcpy(name, n);
		strcpy(phone, p);
		strcpy(address, a);
		cnt++;		//1번 데이터 입력하고 다음 입력 시 cnt++되어야 숫자 증가
	}
	static void InitCnt()
	{
		cnt = 0;
	}
	static void OutCnt()
	{
		printf("총 회원수 : %d\n", cnt);
		printf("\n");
	}

	void GetData()
	{
		printf("회원 정보 : %d, %s, %s, %s\n", cnt, name, phone, address);
	}
};

int CMember::cnt;	//정적 멤버변수 초기화

int main()
{
	CMember::InitCnt(); //맨 처음 cnt = 0부터 시작
	CMember c1("이태경", "010-7280-9231", "부산광역시 해운대구");
	c1.GetData();
	CMember::OutCnt();

	CMember c2("홍길동", "010-1234-5678", "부산광역시 남구");
	c2.GetData();
	CMember::OutCnt();

	CMember c3("박철수", "010-1111-2222", "서울특별시 강남구");
	c3.GetData();
	CMember::OutCnt();
	


	return 0;
}