#include<stdio.h>

class DBQuery
{
private:
	static int hCon;	//정적 멤버변수 선언
	int nResult;
public:
	DBQuery() {};
	static void DBConnect(const char* Server, const char* ID, const char* Pass);	//정적 멤버함수 선언
	static void DBDisConnect();
	bool RunQuery(const char* SQL);
};

int DBQuery::hCon;	//정적 멤버변수 초기화 : 값을 지정 안하면 자동으로 0으로 초기화

void DBQuery::DBConnect(const char *Server, const char* ID, const char* Pass) //정적 멤버함수 초기화
{
	//DB 서버 접속
	hCon = 1234;
	puts("연결되었습니다.");
}

void DBQuery::DBDisConnect()
{
	//DB 서버 접속 해제
	hCon = NULL;
	puts("연결이 끊어졌습니다.");
}

bool DBQuery::RunQuery(const char* SQL)
{
	//Query(hCon, SQL);
	puts(SQL);
	return true;
}

int main()
{
	DBQuery::DBConnect("Secret", "Adult", "doemfdmsrkfk");
	DBQuery Q1, Q2, Q3;

	//필요한 DB 질의를 한다.
	Q1.RunQuery("select*from tblBuja where 나랑 친한 사람");

	DBQuery::DBDisConnect();
	return 0;
}