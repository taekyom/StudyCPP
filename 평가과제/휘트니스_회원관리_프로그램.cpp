/*
	ȸ������ ���α׷�
	�ű�ȸ�� ��� : ȸ����ȣ, �̸�, ü�� �Է� �� heap������ ����
	ȸ����ȣ�� ������ �Է��ϸ� �Է� ����
	�� ȸ����, ��� ü��, �ְ� ü���� ���� ȸ������ ���

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int num;		//ȸ����ȣ
	char name[20];	//ȸ���̸�
	double weight;	//ü��
}Fitness;

Fitness* ary[100];								  //������ �迭����
void total_number(int count);					  //����� ��ü ȸ�� �� 
double average_weight(Fitness** pary, int count); //��� ü��
int max_weight(Fitness** pary, int count);		  //�ְ� ü�� ȸ�� index 
void print_info(Fitness** pary, int index);		  //ȸ�� ���� ���
void free_ary(Fitness** pary, int count);		  //���� �Ҵ� ���� 

int main()
{
	int count = 0;
	int size = sizeof(ary) / sizeof(ary[0]);

	for (int i = 0; i < size; i++)					 //������ �迭 ��üũ�⸦ �������� ũ��� ���� -> ��� ����
	{
		ary[i] = malloc(sizeof(Fitness)); //�迭 ary�� heap������ ����, �޸� ���� �Ҵ�

		printf("ȸ����ȣ�� �Է��ϼ��� : ");
		scanf("%d", &(ary[i]->num));

		if (ary[i]->num < 0)	   //ȸ����ȣ�� ������ �� �Է� ����
		{
			printf("��ȣ�� �߸� �Է��ϼ̽��ϴ�. ���α׷��� ����˴ϴ�.");
			exit(0);			   //���α׷� ����
		}
		else if (ary[i]->num >= 0) //ȸ����ȣ�� ����� ��
		{
			count++;
			printf("ȸ���̸�, ü���� �Է��ϼ��� : ");
			scanf(" %s %lf", ary[i]->name, &(ary[i]->weight));

			//���
			print_info(ary, i);
			total_number(count);									 //�� ȸ����
			printf("��� ü�� : %lf kg\n", average_weight(ary, count)); //���ü��
			printf("�ְ� ü�� : %s(%lf kg)\n", ary[i]->name, ary[i]->weight); //�ְ�ü���� ���� ȸ�� ����
			printf("***********************************\n\n");
		}
	}
	free_ary(ary, count);
	return 0;
}

//��ü ȸ�� �� 
void total_number(int count)
{
	printf("�� ȸ���� : %d\n", count);
}

//��� ü�� 
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

//�ְ� ü��
int max_weight(Fitness** pary, int count)
{
	double max;
	int i = 0;
	int max_index;

	max_index = max_weight(ary, count); //�ְ� ü���� ���� ȸ���� index
	max = pary[i]->weight; //�迭�� �ƹ� �����Ͱ� ���� ���� �����Ⱚ ��ȯ�ǹǷ� 0��° index�� weight�� ����

	for (i = 1; i < count; i++)
	{
		if (pary[i]->weight > max)
		{
			max = pary[i]->weight;
		}
	}
	return max;
}

//ȸ�� ���� ���
void print_info(Fitness** pary, int index)
{
	printf("-----------------------------------\n");
	printf("ȸ����ȣ : %d\n", pary[index]->num);
	printf("ȸ���̸� : %s\n", pary[index]->name);
	printf("ü    �� : %lf kg\n", pary[index]->weight);
	printf("-----------------------------------\n");
}

//�����Ҵ� ����
void free_ary(Fitness** pary, int count)	//�����Ҵ� ����
{
	for (int i = 0; i < count; i++)
	{
		free(pary[i]);
	}
}
