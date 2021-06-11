/*
	���� ���α׷� : 
	
	-���� ���� ȭ��
	1. �÷��̾� 2���� �ϴ� �°��������� ����
	2. �÷��̾� 2���� ȭ���и� ȭ���� �Ʒ��ʰ� ���ʿ� ǥ��
	3. ȭ�� �߾ӿ� ��䰡 �ְ� �� ���� ������ ī�带 ����, �������� ī��� ???�� ǥ��
	4. ȭ�� �����ʿ� �� �÷��̾ ���� ī��� ����, �� Ƚ���� ǥ��
	5. ����Ű�� �� ����(ex. [1][2][3][4][5])
	6. ī�� �Ӽ� : ���ڿ� ����, 1~12���� �� 4�徿 �� 48��, ��, ��, ��, �� �������� ����
	7. ��ũ : ��� �߾ӿ� ī�带 �׾Ƴ��� ��, �÷��̾ ī�带 �� ������ �� �徿 ������ ���� ���� �� ��� ī�� �����ϸ� ��

	-description
	1. ȭ���ǿ� �����ϴ� ��� �繰�� �߻�ȭ�Ͽ� Ŭ������ ����
	2. ���� ���� ������ �ڵ�� ����

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"cursor.h" //gotoxy, delay�Լ� ����ϱ� ����
#include<assert.h>
#include<iostream>
using namespace std;

const int MaxCard = 48;		  //�� ȭ������ ����(1~12���� �� 4�徿)
const int CardGap = 4;		  //ī�� ���� ����(�ϳ��� ī�带 �� ���� ���̷� ����ϹǷ� NULL���ڱ��� 4�� ����)
const int Speed = 1000;		  //ī�带 ���ų� �޽��� ��� �� ����� �ð�, ��ü���� ���� ���� �ӵ� ����(�������� ��ȭ��Ȳ/�޽��� Ȯ�� �ð� �ο�)
const int PromptSpeed = 2000; //��

//ȭ�� �� ���� ǥ���ϴ� Ŭ����
struct SCard
{
	char Name[4];
	SCard() { Name[0] = 0; } //����Ʈ ������ : ī�带 ���� �� or ���濡�� �ǰ� ���� ���(Ư�� ��Ȳ)
	SCard(const char* pName) //�μ��� 1���� ������
	{
		strcpy(Name, pName);
	}

	//GetNumber, GetKind : ī�带 ���� �� �ִ���, ���� �и� ��� ����� �� ������ �� ���
	int GetNumber() const //ȭ���� ���� ���� : 1~9������ ���� ����, J, B, D�� 10~12�����ϰ� ������� ī�� ����
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
		return 12; //B�� ��
	};

	//ȭ���� ���� ���� : Name + 1�� �ѱ��� �о� 0~3������ ���ڿ� ������Ŵ
	int GetKind() const {
		if (strcmp(Name + 1, "��") == 0)
		{
			return 0;
		}
		else if (strcmp(Name + 1, "��") == 0)
		{
			return 1;
		}
		else if (strcmp(Name + 1, "��") == 0)
		{
			return 2;
		}
		else return 3;
	}
	friend ostream& operator <<(ostream& c, const SCard& C) //ī�� ���
	{
		return c << C.Name;
	}
	bool operator ==(const SCard& Other) const  //�� ī�尡 ������ ����
	{
		return (strcmp(Name, Other.Name) == 0); //�� �̸��� ��ġ�ϸ� ���� ī�� 
	}
	bool operator <(const SCard& Other) const   //�� ī���� ��Ҹ� �� : ���� �� �� ���� ��ġ �� ���� ��, ������ ���� ���� �ű� 
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

//ȭ���� �ʱ� ī�� ��� : �� ���ڸ��� ������ �޶� ������ ��ĢX
SCard HwaToo[MaxCard] = { "1��", "1��", "1��", "1��", "2��", "2��", "2��", "2��", "3��", "3��", "3��", "3��",
							"4��", "4��", "4��", "4��",	"5��", "5��", "5��", "5��",	"6��", "6��", "6��", "6��",
							"7��", "7��", "7��", "7��",	"8��", "8��", "8��", "8��", "9��", "9��", "9��", "9��",
							"J��", "J��", "J��", "J��", "D��", "D��", "D��", "D��", "B��", "B��", "B��", "6��", };

//ī���� ������ �����ϴ� �⺻���� Ŭ����(��ü �ڵ� �� ī�� ������ ���� �θ� ����)
class CCardSet
{
protected:
	SCard Card[MaxCard]; //�ִ� 48���� SCard ��ü �迭 ����
	int Num;			 //���տ� ���Ե� ī���� ���� ����, ī�尡 ����/�����Ǹ鼭 ����
	const int sx, sy;	 //ī�� ������ ȭ����� ��ǥ(��� ��ġ ���� �� ����� ����)
	CCardSet(int asx, int asy) : sx(asx), sy(asy)
	{
		Num = 0;		 //���޹��� ȭ�� ��ǥ�� ����, ī�尳���� 0���� �ʱ�ȭ
	}

public:
	int GetNum() { return Num; }
	SCard GetCard(int idx) { return Card[idx]; }
	void Reset() //������ ���� �� �� �� ���ʱ�ȭ�� ����
	{
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
		Num = 0;
	}
	void InsertCard(SCard C);
	SCard RemoveCard(int idx);
	int FindSameCard(SCard C, int* pSame);
	int FindFirstCard(const char* pName);
};

//ī�� ����
void CCardSet::InsertCard(SCard C) {
	int i;

	if (C.Name[0] == 0)	//�� ī�� ���� �ź�
	{
		return;
	}
	for (i = 0; i < Num; i++)	//��ȿ�� ī��� ���ĵ� ��ġ�� ����
	{
		if (C < Card[i]) break; //ī�������� ��ȸ �� ������ ī�庸�� ū ������ ī�带 ã�� �� ��ġ�� ����
	}
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));
	Card[i] = C;
	Num++;
}

//������ ÷���� ī�带 �����ϰ� �ش� ī�� ����
//ī�带 ���ų� ��ũ���� ī�带 ������ �� ȣ�� �� ī�� �ϳ� choice
SCard CCardSet::RemoveCard(int idx) 
{
	assert(idx < Num);
	SCard C = Card[idx];
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--; //���� ���¸� �����ϱ� ���� ���ŵ� ī�� ������ �� ĭ�� ������ �̵��ϸ� 1 ����
	return C;
}

//C�� ��ġ�ϴ� ī�� ����
//���� ���� ī�尡 ��ġ�� �� ���� �� �迭�� ī�� ��� �ۼ�, ���� ����
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
	*p = -1;	//�迭�� ��
	return num; //���� ����
}

//ī���� ���翩�� �ż��� �˻�
//�κ� ���ڿ� �˻����� ���ڳ� ������ ��ġ�ϴ� ������ ī�� �˻�(ex. 8 : ������ ������� 8�� �ִ��� ����)
int CCardSet::FindFirstCard(const char* pName) {
	int i;

	for (i = 0; i < Num; i++) //���� �˻�
	{
		if (strstr(Card[i].Name, pName) != NULL) 
		{
			return i;
		}
	}
	return -1;				 //��ġ�ϴ� �� ������ -1 ����
}

//��ũ
class CDeck : public CCardSet //ī�� �����̹Ƿ� CCardSet�κ��� ���
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }
	void Shuffle()			  //ī�带 �������� ���� �Լ�
	{
		int i, n;
		for (i = 0; i < MaxCard; i++) //48�� ���� ī�尡 �ұ�Ģ�ϰ� ����
		{
			do {
				n = random(MaxCard);
			} while (Card[n].Name[0] != NULL);
			Card[n] = HwaToo[i];	  //HwaToo�迭�� ī�带 Card�迭�� ���� ��ġ�� �������
			Num++;
		}
	}
	SCard Pop()						  //���������� ������� �� �徿 ���� ��信 ���� �÷��̾�鿡�� ���� ��
	{
		return RemoveCard(Num - 1);   //������ ī�� �ϳ��� �����Ͽ� ����
	}
	bool IsEmpty()					  //ī�尡 0���� ���� �� ���� ������ ����
	{
		return Num == 0;
	}
	bool IsNotLast()				  //������ �������� ����
	{
		return Num > 1;				  //���� ī�尡 2�� �̻� �� ������ ���� X, 1�� �� ������ ����
	}
	void Draw(bool bFlip)			  //ȭ�鿡 ��ũ ǥ��
	{
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   "); //��� �������� �����Ƿ� ???�� ���, ī�� �� ���� �� �������� �� �� �� ī�常 ���
	}
};

//�÷��̾� : �°��� �� 10������ ����
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }
	void Draw(bool MyTurn) //�÷��̾��� �и� ��Ÿ��
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

//���
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
	void Draw()
	{
		CPlayer::Draw(false);	//���� ī�带 �����ֱ⸸ �ϹǷ� MyTurn�� �μ��� �׻� false
	}
	void DrawSelNum(int* pSame) //�÷��̾ �� ī�峪 ��ũ���� ������ ī��� ��ġ�ϴ� ī�尡 �� �̻� �� �Ϸù�ȣ ǥ��
	{
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++)
		{
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	void DrawTempCard(int idx, SCard C) //�÷��̾ �� ī�带 ���� ī�� �Ʒ��ʿ� ���, �� ī�尡 ��ġ���� ������
	{
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

//�÷��̾ ���� ī���� ���� : ���� �п� ���� ����
class CPlayerPae : public CCardSet
{
private:
	int nGo;	  //�� Ƚ��
public:
	int OldScore; //����
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
	void IncreaseGo() //�� Ƚ���� ������ ����(�����ϴ� ���� X)
	{
		nGo++; 
	}
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

//���� �и� ȭ�鿡 �������� ���
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
	cout << "���� : " << CalcScore() << "��, " << nGo << "��";
}

//������ 3���� �ѹ��� �԰ų� �Ͼ������� ��, �� ������ �����Ͽ� ��뿡�� ��
SCard CPlayerPae::RemovePee()
{
	int idx;

	idx = FindFirstCard("��");
	if (idx != -1)
	{
		return RemoveCard(idx);
	}
	return SCard(); //������ ���� �п� ����
}

//���� ��Ģ��� ���� ���
//�� ������ ���� 3�� �̻��� ���� 3, 4, 15������ ���, ���� ���Ե� 3���� 2��
//�ʰ� ���� 5����� 1������ ���
//Ư�� ī�� ������ �� ����� ���� ���� �߰� : û��, �ʴ�, ȫ���� �� 3��, ������ 5��
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
	if (n[0] == 3 && FindFirstCard("B��") != -1 && FindFirstCard("2��") != -1)
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
	if (FindFirstCard("8��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("2��") != -1)
	{
		NewScore += 5;
	}
	if (FindFirstCard("1��") != -1 && FindFirstCard("2��") != -1 && FindFirstCard("3��") != -1)
	{
		NewScore += 3;
	}
	if (FindFirstCard("4��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("7��") != -1)
	{
		NewScore += 3;
	}
	if (FindFirstCard("9��") != -1 && FindFirstCard("J��") != -1 && FindFirstCard("6��") != -1)
	{
		NewScore += 3;
	}
	return NewScore;
}


//����� �Լ� 
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

//���� ����(���� ���ݿ� ���ǹǷ�)
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn; //���� ���� ī�带 �� �������� ���

//main �Լ�
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

	randomize();  //������ ���� ���� �� ���� �߻��� �ʱ�ȭ
	Initialize(); //�� ������ ������ ����
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) //���� ����(ī�� 1���� �� �� 1�� �ݺ�)
	{
		DrawScreen();
		if (SouthTurn) //�������� ����
		{
			Turn = &South;
			TurnPae = &SouthPae; //��� �и� �̸� ����
			OtherPae = &NorthPae;
		}
		else 
		{
			Turn = &North;
			TurnPae = &NorthPae; //��� �и� �̸� ����
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "���� ���� ȭ���� �����ϼ���(1 ~ %d, 0 : ����) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) //0�� �Է��ϸ� ���� ����
		{
			if (InputInt("���� �����ðڽ��ϱ�?(0 : ��, 1 : �ƴϿ�)", 0, 1) == 0) //�Ǽ� �Է� ���� ����
				return;
			else continue;
		}

		//�÷��̾ ī�带 1���� ��
		UserTriple = DeckTriple = false;
		UserIdx = ch - 1;
		UserCard = Turn->GetCard(UserIdx);
		SameNum = Blanket.FindSameCard(UserCard, arSame); //�÷��̾ �� ī��� ��信 �� ī���� ��ġ ���� ���
		switch (SameNum) 
		{
		case 0: //��ġ�ϴ� ī�尡 ���� ���
			UserSel = -1; //�ƹ��͵� ���� ���ϹǷ� -1
			Blanket.InsertCard(Turn->RemoveCard(UserIdx)); //����ī��� ��� ��信 ����(�������)
			DrawScreen();
			break;
		case 1: //1���� ��ġ�ϴ� ���
			UserSel = arSame[0]; //�ش� ī�带 ����
			break;
		case 2: //2���� ��ġ�ϴ� ���
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) //2���� ī�尡 ���� ���� ����X
			{
				UserSel = arSame[0];
			}
			else 
			{
				Blanket.DrawSelNum(arSame);
				sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1 ~ %d)", SameNum); 
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1]; //������ ī�� ����
			}
			break;
		case 3: //3���� ��ġ�ϴ� ���
			UserSel = arSame[1];
			UserTriple = true; //3���� ����
			break;
		}

		if (UserSel != -1) 
		{
			Blanket.DrawTempCard(UserSel, UserCard);
		}
		delay(Speed); //�÷��̾ �� ī�带 ���� ī�� �Ʒ��ʿ� ǥ���ϰ� 1�ʰ� ���� �� ��Ȳ Ȯ��

		//��ũ���� 1���� ������
		Deck.Draw(true);
		delay(Speed);		   //������ ī�带 �����ֱ� ���� ����
		DeckCard = Deck.Pop(); //��ũ �� �� ī�带 ����
		SameNum = Blanket.FindSameCard(DeckCard, arSame);
		switch (SameNum) 
		{
		case 0: //��ġ�ϴ� ī�尡 ���� ���
			DeckSel = -1; //���� �� ����
			break;
		case 1: //1���� ��ġ�ϴ� ���
			DeckSel = arSame[0];
			if (DeckSel == UserSel) //��ũ�� ī�带 �������� �� ����ڰ� �� ī��� ��ũ�� ī�尡 ��ġ�ϸ�
			{
				if (Deck.IsNotLast()) 
				{
					Blanket.InsertCard(DeckCard); //��� ī�带 ���� �ݳ�
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));
					OutPrompt("�����߽��ϴ�.", PromptSpeed);
					continue;
				}
				else 
				{
					DeckSel = -1; //���ǿ��� ����X
				}
			}
			break;
		case 2: //2���� ��ġ�ϴ� ���
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
					sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3: //3���� ��ġ�ϴ� ���
			DeckSel = arSame[1];
			DeckTriple = true; //��� ī�带 �� ������
			break;
		}
		if (DeckSel != -1) 
		{
			Blanket.DrawTempCard(DeckSel, DeckCard);
		}
		Deck.Draw(false);
		delay(Speed);

		//��ġ�ϴ� ī�带 ����(3���� ���� ���� ���� get)
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
		else //DeckSel = -1�� ��
		{
			Blanket.InsertCard(DeckCard);
		}

		//��, ����, �Ͼ��� ������ �����ϰ� ������ �Ǹ� ����
		//�� : ���� �� ī�带 ��ũ���� ������ �ٽ� ���� ���
		//���� : �÷��̾ �� ī��� ����� ī�带 �԰� ��ũ���� ������ ī��ε� �Ե� 4���� ���ڰ� ��� ��ġ�ϴ� ���
		//�Ͼ��� : ��信 ���� ī�尡 �ϳ��� ����� ��
		//��, ����, ���� �Ա�� ���ÿ� �߻�x �� nSnatch�� �ִ밪�� 3
		nSnatch = 0;
		if (Deck.IsNotLast()) 
		{
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) 
			{
				nSnatch++;
				OutPrompt("���Դϴ�.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) 
			{
				nSnatch++;
				OutPrompt("�����Դϴ�.", PromptSpeed); 
			}
			if (Blanket.GetNum() == 0) 
			{
				nSnatch++;
				OutPrompt("�Ͼ����Դϴ�.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) 
			{
				OutPrompt("�Ѳ����� �� ���� �Ծ����ϴ�.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		for (i = 0; i < nSnatch; i++) 
		{
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		//���� ���, ��/���� ���� ����
		NewScore = TurnPae->CalcScore();
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) 
		{
			DrawScreen();
			if (InputInt("�߰� ������ ȹ���߽��ϴ�.(0 : ����, 1 : ���)", 0, 1) == 1) 
			{
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
			}
			else break;
		}
	}
	DrawScreen();
	OutPrompt("������ �������ϴ�.", 0);
}

//��ũ�� �и� �������� ���� ī�带 �ʱ�ȭ
//�÷��̾�� ���� 10�徿 �ְ� ��信 8���� ��
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

//ȭ���� ����� ��� ��ü�� Draw �Լ��� ���ʴ�� ȣ���Ͽ� ǥ��
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

//�ϴܿ� ª�� �޽����� ����ϰ� ����ڰ� �޽����� ���� ���� hold
//����ڿ��� ���� ���¸� �˷��ְų� ���� �ൿ�� ������ �� �޽����� ���
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

//������ ������ ���� �ϳ��� �Է¹���
//����Ű�� ���� ����
//���� ������ ���� ���� : ���� ī�� ���� ���� ������ �� �μ��� ��� ������ ���޹���
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
		OutPrompt("��ȿ���� ���� ��ȣ�Դϴ�. ������ ������ �°� �ٽ� �Է��� �ּ���.");
	}
}