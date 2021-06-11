/*
	고스톱 프로그램 : 
	
	-최종 실행 화면
	1. 플레이어 2명이 하는 맞고형식으로 진행
	2. 플레이어 2명의 화투패를 화면의 아래쪽과 위쪽에 표시
	3. 화면 중앙에 담요가 있고 이 위에 펼쳐진 카드를 놓고, 뒤집어진 카드는 ???로 표시
	4. 화면 오른쪽에 각 플레이어가 먹은 카드와 점수, 고 횟수가 표시
	5. 숫자키로 패 선택(ex. [1][2][3][4][5])
	6. 카드 속성 : 숫자와 종류, 1~12까지 각 4장씩 총 48장, 광, 십, 오, 피 네종류로 구분
	7. 데크 : 담요 중앙에 카드를 쌓아놓은 것, 플레이어가 카드를 낼 때마다 한 장씩 뒤집어 게임 진행 → 모든 카드 소진하면 끝

	-description
	1. 화투판에 등장하는 모든 사물을 추상화하여 클래스로 정의
	2. 게임 진행 과정을 코드로 구현

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"cursor.h" //gotoxy, delay함수 사용하기 위함
#include<assert.h>
#include<iostream>
using namespace std;

const int MaxCard = 48;		  //총 화투패의 개수(1~12까지 각 4장씩)
const int CardGap = 4;		  //카드 간의 간격(하나의 카드를 세 문자 길이로 출력하므로 NULL문자까지 4로 정의)
const int Speed = 1000;		  //카드를 내거나 메시지 출력 시 대기할 시간, 전체적인 게임 진행 속도 조절(게임판의 변화상황/메시지 확인 시간 부여)
const int PromptSpeed = 2000; //상동

//화투 한 장을 표현하는 클래스
struct SCard
{
	char Name[4];
	SCard() { Name[0] = 0; } //디폴트 생성자 : 카드를 섞을 때 or 상대방에게 피가 없는 경우(특수 상황)
	SCard(const char* pName) //인수가 1개인 생성자
	{
		strcpy(Name, pName);
	}

	//GetNumber, GetKind : 카드를 먹을 수 있는지, 먹은 패를 어디에 출력할 지 결정할 때 사용
	int GetNumber() const //화투의 숫자 조사 : 1~9까지는 숫자 리턴, J, B, D는 10~12리턴하고 순서대로 카드 정렬
	{
		if (isdigit(Name[0]))
		{
			return Name[0] - '0';
		}
		if (Name[0] == 'J')
		{
			return 10;
		}
		if (Name[0] == 'D')
		{
			return 11;
		}
		return 12; //B일 때
	};

	//화투의 종류 조사 : Name + 1의 한글을 읽어 0~3까지의 숫자와 대응시킴
	int GetKind() const {
		if (strcmp(Name + 1, "광") == 0)
		{
			return 0;
		}
		else if (strcmp(Name + 1, "십") == 0)
		{
			return 1;
		}
		else if (strcmp(Name + 1, "오") == 0)
		{
			return 2;
		}
		else return 3;
	}
	friend ostream& operator <<(ostream& c, const SCard& C) //카드 출력
	{
		return c << C.Name;
	}
	bool operator ==(const SCard& Other) const  //두 카드가 같은지 조사
	{
		return (strcmp(Name, Other.Name) == 0); //두 이름이 일치하면 같은 카드 
	}
	bool operator <(const SCard& Other) const   //두 카드의 대소를 비교 : 숫자 비교 후 숫자 일치 → 종류 비교, 종류에 따라 순서 매김 
	{
		if (GetNumber() < Other.GetNumber())
		{
			return true;
		}
		if (GetNumber() > Other.GetNumber())
		{
			return false;
		}
		if (GetKind() < Other.GetKind())
		{
			return true;
		}
		return false;
	}
};

//화투의 초기 카드 목록 : 각 숫자마다 조합이 달라 일정한 규칙X
SCard HwaToo[MaxCard] = { "1광", "1오", "1피", "1피", "2오", "2십", "2피", "2피", "3광", "3오", "3피", "3피",
							"4십", "4오", "4피", "4피",	"5십", "5오", "5피", "5피",	"6십", "6십", "6피", "6피",
							"7십", "7십", "7피", "7피",	"8광", "8십", "8피", "8피", "9십", "9오", "9피", "9피",
							"J십", "J오", "J피", "J피", "D광", "D피", "D피", "D피", "B광", "B십", "B오", "6피", };

//카드의 집합을 관리하는 기본동작 클래스(전체 코드 상 카드 집합의 공통 부모 역할)
class CCardSet
{
protected:
	SCard Card[MaxCard]; //최대 48개의 SCard 객체 배열 포함
	int Num;			 //집합에 포함된 카드의 현재 개수, 카드가 삽입/삭제되면서 증감
	const int sx, sy;	 //카드 집합의 화면상의 좌표(출력 위치 고정 → 상수로 선언)
	CCardSet(int asx, int asy) : sx(asx), sy(asy)
	{
		Num = 0;		 //전달받은 화면 자표를 저장, 카드개수를 0으로 초기화
	}

public:
	int GetNum() { return Num; }
	SCard GetCard(int idx) { return Card[idx]; }
	void Reset() //게임을 여러 번 할 때 재초기화를 위함
	{
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
		Num = 0;
	}
	void InsertCard(SCard C);
	SCard RemoveCard(int idx);
	int FindSameCard(SCard C, int* pSame);
	int FindFirstCard(const char* pName);
};

//카드 삽입
void CCardSet::InsertCard(SCard C) {
	int i;

	if (C.Name[0] == 0)	//빈 카드 삽입 거부
	{
		return;
	}
	for (i = 0; i < Num; i++)	//유효한 카드는 정렬된 위치에 삽입
	{
		if (C < Card[i]) break; //카드집합을 순회 → 삽입할 카드보다 큰 최초의 카드를 찾아 그 위치에 삽입
	}
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));
	Card[i] = C;
	Num++;
}

//지정한 첨자의 카드를 제거하고 해당 카드 리턴
//카드를 내거나 데크에서 카드를 뒤집을 때 호출 → 카드 하나 choice
SCard CCardSet::RemoveCard(int idx) 
{
	assert(idx < Num);
	SCard C = Card[idx];
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--; //정렬 상태를 유지하기 위해 제거된 카드 뒤쪽은 한 칸씩 앞으로 이동하며 1 감소
	return C;
}

//C와 일치하는 카드 조사
//여러 장의 카드가 일치할 수 있음 → 배열에 카드 목록 작성, 개수 리턴
int CCardSet::FindSameCard(SCard C, int* pSame) 
{
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++) 
	{
		if (Card[i].GetNumber() == C.GetNumber()) 
		{
			num++;
			*p++ = i;
		}
	}
	*p = -1;	//배열의 끝
	return num; //개수 리턴
}

//카드의 존재여부 신속히 검색
//부분 문자열 검색으로 숫자나 종류가 일치하는 최초의 카드 검색(ex. 8 : 종류에 상관없이 8이 있는지 조사)
int CCardSet::FindFirstCard(const char* pName) {
	int i;

	for (i = 0; i < Num; i++) //순차 검색
	{
		if (strstr(Card[i].Name, pName) != NULL) 
		{
			return i;
		}
	}
	return -1;				 //일치하는 게 없으면 -1 리턴
}

//데크
class CDeck : public CCardSet //카드 집합이므로 CCardSet로부터 상속
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }
	void Shuffle()			  //카드를 무작위로 섞는 함수
	{
		int i, n;
		for (i = 0; i < MaxCard; i++) //48번 돌면 카드가 불규칙하게 섞임
		{
			do {
				n = random(MaxCard);
			} while (Card[n].Name[0] != NULL);
			Card[n] = HwaToo[i];	  //HwaToo배열의 카드를 Card배열의 임의 위치에 집어넣음
			Num++;
		}
	}
	SCard Pop()						  //위에서부터 순서대로 한 장씩 빼내 담요에 놓고 플레이어들에게 나눠 줌
	{
		return RemoveCard(Num - 1);   //마지막 카드 하나를 제거하여 리턴
	}
	bool IsEmpty()					  //카드가 0인지 조사 → 게임 끝인지 조사
	{
		return Num == 0;
	}
	bool IsNotLast()				  //마지막 게임인지 조사
	{
		return Num > 1;				  //남은 카드가 2장 이상 → 마지막 게임 X, 1장 → 마지막 게임
	}
	void Draw(bool bFlip)			  //화면에 데크 표시
	{
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   "); //모두 뒤집어져 있으므로 ???만 출력, 카드 한 장을 막 뒤집었을 때 → 이 카드만 출력
	}
};

//플레이어 : 맞고일 때 10장으로 시작
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }
	void Draw(bool MyTurn) //플레이어의 패를 나타냄
	{
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) 
		{
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn) 
			{
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

//담요
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
	void Draw()
	{
		CPlayer::Draw(false);	//담요는 카드를 보여주기만 하므로 MyTurn의 인수는 항상 false
	}
	void DrawSelNum(int* pSame) //플레이어가 낸 카드나 데크에서 뒤집은 카드와 일치하는 카드가 둘 이상 → 일련번호 표시
	{
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++)
		{
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	void DrawTempCard(int idx, SCard C) //플레이어가 낸 카드를 먹을 카드 아래쪽에 출력, 두 카드가 일치함을 보여줌
	{
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

//플레이어가 먹은 카드의 집합 : 먹은 패와 점수 관리
class CPlayerPae : public CCardSet
{
private:
	int nGo;	  //고 횟수
public:
	int OldScore; //점수
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) 
	{
		OldScore = 6; nGo = 0; 
	}
	void Reset()
	{
		CCardSet::Reset(); OldScore = 6; nGo = 0;
	}
	int GetGo()
	{
		return nGo;
	}
	void IncreaseGo() //고 횟수는 증가만 가능(감소하는 경우는 X)
	{
		nGo++; 
	}
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

//먹은 패를 화면에 종류별로 출력
void CPlayerPae::Draw()
{
	int i, kind;
	int x[4] = { sx, sx, sx, sx }, py = sy + 3;

	for (i = 0; i < Num; i++)
	{
		kind = Card[i].GetKind();
		if (kind < 3)
		{
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else
		{
			gotoxy(x[3], py);
			x[3] += CardGap;
			if (x[3] > 75)
			{
				x[3] = sx;
				py++;
			}
		}
		cout << Card[i];
	}
	gotoxy(sx + 23, sy);
	cout << "점수 : " << CalcScore() << "점, " << nGo << "고";
}

//상대방이 3장을 한번에 먹거나 싹쓸이했을 때, 피 한장을 제거하여 상대에게 상납
SCard CPlayerPae::RemovePee()
{
	int idx;

	idx = FindFirstCard("피");
	if (idx != -1)
	{
		return RemoveCard(idx);
	}
	return SCard(); //상대방의 먹은 패에 삽입
}

//고스톱 규칙대로 점수 계산
//광 개수에 따라 3장 이상은 각각 3, 4, 15점으로 계산, 비광이 포함된 3광은 2점
//십과 오는 5장부터 1점으로 계산
//특정 카드 종류를 다 모았을 때도 점수 추가 : 청단, 초단, 홍단은 각 3점, 고도리는 5점
int CPlayerPae::CalcScore() 
{
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0, 0, 0, 3, 4, 15 };
	
	for (i = 0; i < Num; i++)
	{
		kind = Card[i].GetKind();
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B광") != -1 && FindFirstCard("2십") != -1)
	{
		NewScore--;
	}
	if (n[1] >= 5)
	{
		NewScore += (n[1] - 4);
	}
	if (n[2] >= 5)
	{
		NewScore += (n[2] - 4);
	}
	if (n[3] >= 10)
	{
		NewScore += (n[3] - 9);
	}
	if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1)
	{
		NewScore += 5;
	}
	if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1)
	{
		NewScore += 3;
	}
	if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1)
	{
		NewScore += 3;
	}
	if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1)
	{
		NewScore += 3;
	}
	return NewScore;
}


//도우미 함수 
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

//전역 변수(게임 전반에 사용되므로)
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn; //지금 누가 카드를 낼 차례인지 기억

//main 함수
void main()
{
	int i, ch;
	int arSame[4], SameNum;
	char Mes[256];
	CPlayer* Turn;
	CPlayerPae* TurnPae, * OtherPae;
	int UserIdx, UserSel, DeckSel;
	SCard UserCard, DeckCard;
	bool UserTriple, DeckTriple;
	int nSnatch;
	int NewScore;

	randomize();  //완전한 난수 생성 → 난수 발생기 초기화
	Initialize(); //패 나누고 게임판 생성
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) //게임 시작(카드 1장을 낼 때 1번 반복)
	{
		DrawScreen();
		if (SouthTurn) //남군부터 시작
		{
			Turn = &South;
			TurnPae = &SouthPae; //대상 패를 미리 조사
			OtherPae = &NorthPae;
		}
		else 
		{
			Turn = &North;
			TurnPae = &NorthPae; //대상 패를 미리 조사
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "내고 싶은 화투를 선택하세요(1 ~ %d, 0 : 종료) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) //0을 입력하면 게임 종료
		{
			if (InputInt("정말 끝내시겠습니까?(0 : 예, 1 : 아니오)", 0, 1) == 0) //실수 입력 방지 질문
				return;
			else continue;
		}

		//플레이어가 카드를 1장을 냄
		UserTriple = DeckTriple = false;
		UserIdx = ch - 1;
		UserCard = Turn->GetCard(UserIdx);
		SameNum = Blanket.FindSameCard(UserCard, arSame); //플레이어가 낸 카드와 담요에 깔린 카드의 일치 개수 계산
		switch (SameNum) 
		{
		case 0: //일치하는 카드가 없는 경우
			UserSel = -1; //아무것도 먹지 못하므로 -1
			Blanket.InsertCard(Turn->RemoveCard(UserIdx)); //버린카드는 즉시 담요에 삽입(낙장불입)
			DrawScreen();
			break;
		case 1: //1개만 일치하는 경우
			UserSel = arSame[0]; //해당 카드를 먹음
			break;
		case 2: //2개가 일치하는 경우
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) //2개의 카드가 같을 때는 질문X
			{
				UserSel = arSame[0];
			}
			else 
			{
				Blanket.DrawSelNum(arSame);
				sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1 ~ %d)", SameNum); 
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1]; //선택한 카드 대입
			}
			break;
		case 3: //3개가 일치하는 경우
			UserSel = arSame[1];
			UserTriple = true; //3장을 먹음
			break;
		}

		if (UserSel != -1) 
		{
			Blanket.DrawTempCard(UserSel, UserCard);
		}
		delay(Speed); //플레이어가 낸 카드를 먹을 카드 아래쪽에 표시하고 1초간 지연 → 상황 확인

		//데크에서 1장을 뒤집음
		Deck.Draw(true);
		delay(Speed);		   //뒤집은 카드를 보여주기 위한 지연
		DeckCard = Deck.Pop(); //데크 맨 위 카드를 꺼냄
		SameNum = Blanket.FindSameCard(DeckCard, arSame);
		switch (SameNum) 
		{
		case 0: //일치하는 카드가 없는 경우
			DeckSel = -1; //먹을 게 없음
			break;
		case 1: //1개만 일치하는 경우
			DeckSel = arSame[0];
			if (DeckSel == UserSel) //데크의 카드를 뒤집었을 때 사용자가 낸 카드와 데크의 카드가 일치하면
			{
				if (Deck.IsNotLast()) 
				{
					Blanket.InsertCard(DeckCard); //모든 카드를 담요로 반납
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));
					OutPrompt("설사했습니다.", PromptSpeed);
					continue;
				}
				else 
				{
					DeckSel = -1; //막판에는 설사X
				}
			}
			break;
		case 2: //2개가 일치하는 경우
			if (UserSel == arSame[0]) 
			{
				DeckSel = arSame[1];
			}
			else if (UserSel == arSame[1]) 
			{
				DeckSel = arSame[0];
			}
			else 
			{
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) 
				{
					DeckSel = arSame[0];
				}
				else 
				{
					Blanket.DrawSelNum(arSame);
					sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3: //3개가 일치하는 경우
			DeckSel = arSame[1];
			DeckTriple = true; //모든 카드를 다 가져옴
			break;
		}
		if (DeckSel != -1) 
		{
			Blanket.DrawTempCard(DeckSel, DeckCard);
		}
		Deck.Draw(false);
		delay(Speed);

		//일치하는 카드를 먹음(3장을 먹은 경우는 전부 get)
		if (UserSel != -1) 
		{
			if (UserTriple) 
			{
				for (i = 0; i < 3; i++) 
				{
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));
				}
			}
			else 
			{
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));
			if (DeckSel != -1 && DeckSel > UserSel) 
			{
				DeckSel -= (UserTriple ? 3 : 1);
			}
		}
		if (DeckSel != -1) 
		{
			if (DeckTriple) 
			{
				for (i = 0; i < 3; i++) 
				{
					TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));
				}
			}
			else 
			{
				TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));
			}
			TurnPae->InsertCard(DeckCard);
		}
		else //DeckSel = -1일 때
		{
			Blanket.InsertCard(DeckCard);
		}

		//쪽, 따닥, 싹쓸이 조건을 점검하고 상대방의 피를 뺏음
		//쪽 : 내가 낸 카드를 데크에서 뒤집어 다시 먹은 경우
		//따닥 : 플레이어가 낸 카드로 담요의 카드를 먹고 데크에서 뒤집은 카드로도 먹되 4장의 숫자가 모두 일치하는 경우
		//싹쓸이 : 담요에 남은 카드가 하나도 없어야 함
		//쪽, 따닥, 세장 먹기는 동시에 발생x → nSnatch의 최대값은 3
		nSnatch = 0;
		if (Deck.IsNotLast()) 
		{
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) 
			{
				nSnatch++;
				OutPrompt("쪽입니다.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) 
			{
				nSnatch++;
				OutPrompt("따닥입니다.", PromptSpeed); 
			}
			if (Blanket.GetNum() == 0) 
			{
				nSnatch++;
				OutPrompt("싹쓸이입니다.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) 
			{
				OutPrompt("한꺼번에 세 장을 먹었습니다.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		for (i = 0; i < nSnatch; i++) 
		{
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		//점수 계산, 고/스톱 여부 질문
		NewScore = TurnPae->CalcScore();
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) 
		{
			DrawScreen();
			if (InputInt("추가 점수를 획득했습니다.(0 : 스톱, 1 : 계속)", 0, 1) == 1) 
			{
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
			}
			else break;
		}
	}
	DrawScreen();
	OutPrompt("게임이 끝났습니다.", 0);
}

//데크의 패를 무작위로 섞어 카드를 초기화
//플레이어에게 각각 10장씩 주고 담요에 8장을 깜
void Initialize()
{
	int i;

	Deck.Shuffle();
	for (i = 0; i < 10; i++) 
	{
		South.InsertCard(Deck.Pop());
		North.InsertCard(Deck.Pop());
		if (i < 8)
		{
			Blanket.InsertCard(Deck.Pop());
		}
	}
}

//화면을 지우고 모든 객체의 Draw 함수를 차례대로 호출하여 표시
void DrawScreen()
{
	clrscr();
	South.Draw(SouthTurn);
	North.Draw(!SouthTurn);
	Blanket.Draw();
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

//하단에 짧은 메시지를 출력하고 사용자가 메시지를 읽을 동안 hold
//사용자에게 현재 상태를 알려주거나 다음 행동을 지시할 때 메시지를 출력
void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) 
	{
		cout << ' '; 
	}
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);
}

//지정한 범위의 정수 하나를 입력받음
//숫자키로 게임 진행
//선택 가능한 숫자 범위 : 남은 카드 수에 따라 가변적 → 인수로 허용 범위를 전달받음
int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) 
	{
		ch = tolower(_getch());
		if (ch == 0xE0 || ch == 0) 
		{
			ch = _getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;
		if (ch == 'a')
		{
			ch = 10;
		}
		else
		{
			ch = ch - '0';
		}
		if (ch >= start && ch <= end) 
		{
			return ch;
		}
		OutPrompt("유효하지 않은 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요.");
	}
}