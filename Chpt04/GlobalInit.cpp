#include<stdio.h>

class DBQuery
{
private:
	static int hCon;	//���� ������� ����
	int nResult;
public:
	DBQuery() {};
	static void DBConnect(const char* Server, const char* ID, const char* Pass);	//���� ����Լ� ����
	static void DBDisConnect();
	bool RunQuery(const char* SQL);
};

int DBQuery::hCon;	//���� ������� �ʱ�ȭ : ���� ���� ���ϸ� �ڵ����� 0���� �ʱ�ȭ

void DBQuery::DBConnect(const char *Server, const char* ID, const char* Pass) //���� ����Լ� �ʱ�ȭ
{
	//DB ���� ����
	hCon = 1234;
	puts("����Ǿ����ϴ�.");
}

void DBQuery::DBDisConnect()
{
	//DB ���� ���� ����
	hCon = NULL;
	puts("������ ���������ϴ�.");
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

	//�ʿ��� DB ���Ǹ� �Ѵ�.
	Q1.RunQuery("select*from tblBuja where ���� ģ�� ���");

	DBQuery::DBDisConnect();
	return 0;
}