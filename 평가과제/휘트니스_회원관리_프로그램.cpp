/*
	회원관리 프로그램
	신규회원 등록 : 회원번호, 이름, 체중 입력 → heap영역에 저장
	회원번호를 음수로 입력하면 입력 종료
	총 회원수, 평균 체중, 최고 체중을 갖는 회원정보 출력

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int num;		//회원번호
	char name[20];	//회원이름
	double weight;	//체중
}Fitness;

Fitness* ary[100];								  //포인터 배열선언
void total_number(int count);					  //등록한 전체 회원 수 
double average_weight(Fitness** pary, int count); //평균 체중
int max_weight(Fitness** pary, int count);		  //최고 체중 회원 index 
void print_info(Fitness** pary, int index);		  //회원 정보 출력
void free_ary(Fitness** pary, int count);		  //동적 할당 해제 

int main()
{
	int count = 0;
	int size = sizeof(ary) / sizeof(ary[0]);

	for (int i = 0; i < size; i++)					 //포인터 배열 전체크기를 포인터의 크기로 나눔 -> 요소 개수
	{
		ary[i] = malloc(sizeof(Fitness)); //배열 ary를 heap영역에 저장, 메모리 동적 할당

		printf("회원번호를 입력하세요 : ");
		scanf("%d", &(ary[i]->num));

		if (ary[i]->num < 0)	   //회원번호가 음수일 때 입력 종료
		{
			printf("번호를 잘못 입력하셨습니다. 프로그램이 종료됩니다.");
			exit(0);			   //프로그램 종료
		}
		else if (ary[i]->num >= 0) //회원번호가 양수일 때
		{
			count++;
			printf("회원이름, 체중을 입력하세요 : ");
			scanf(" %s %lf", ary[i]->name, &(ary[i]->weight));

			//출력
			print_info(ary, i);
			total_number(count);									 //총 회원수
			printf("평균 체중 : %lf kg\n", average_weight(ary, count)); //평균체중
			printf("최고 체중 : %s(%lf kg)\n", ary[i]->name, ary[i]->weight); //최고체중을 가진 회원 정보
			printf("***********************************\n\n");
		}
	}
	free_ary(ary, count);
	return 0;
}

//전체 회원 수 
void total_number(int count)
{
	printf("총 회원수 : %d\n", count);
}

//평균 체중 
double average_weight(Fitness** pary, int count)
{
	double sum = 0;
	double avg = 0;

	for (int i = 0; i < count; i++)
	{
		sum += pary[i]->weight;
	}
	avg = sum / count;

	return avg;
}

//최고 체중
int max_weight(Fitness** pary, int count)
{
	double max;
	int i = 0;
	int max_index;

	max_index = max_weight(ary, count); //최고 체중을 가진 회원의 index
	max = pary[i]->weight; //배열에 아무 데이터가 없을 때는 쓰레기값 반환되므로 0번째 index의 weight로 지정

	for (i = 1; i < count; i++)
	{
		if (pary[i]->weight > max)
		{
			max = pary[i]->weight;
		}
	}
	return max;
}

//회원 정보 출력
void print_info(Fitness** pary, int index)
{
	printf("-----------------------------------\n");
	printf("회원번호 : %d\n", pary[index]->num);
	printf("회원이름 : %s\n", pary[index]->name);
	printf("체    중 : %lf kg\n", pary[index]->weight);
	printf("-----------------------------------\n");
}

//동적할당 해제
void free_ary(Fitness** pary, int count)	//동적할당 해제
{
	for (int i = 0; i < count; i++)
	{
		free(pary[i]);
	}
}
