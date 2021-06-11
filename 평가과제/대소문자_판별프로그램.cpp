/*
    ��ҹ��� �Ǻ� ���α׷�
    �迭 ���� :
    1. �Է¹��� �迭 �̸� : input_ary
    2. �迭�� ũ��� 10
    3. �������� ���
    4. �������� �˰����� �Լ��� ����
    5. �ҹ��� ���� �迭�̸� : lower_ary
       �빮�� ���� �迭�̸� : upper_ary

    ���Ḯ��Ʈ ���� :
    1. 2. 4 ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void insertionSort(char* pary, int sz);	// ���� ���� �Լ�
void swap(char* a, char* b);		    // swap �Լ�

int main()
{
    char input_ary[10];            //ũ�Ⱑ 10�� �迭
    char* upper_ary, * lower_ary; //��/�ҹ��� ���� �迭

    //��/�ҹ��� �����Ҵ�
    upper_ary = (char*)malloc(sizeof(char));
    lower_ary = (char*)malloc(sizeof(char));

    int i;
    int size = sizeof(input_ary) / sizeof(input_ary[0]);

    printf("���ĺ��� 10���� �Է��ϼ��� : ");
    for (i = 0; i < size; i++)
    {
        scanf(" %c", &input_ary[i]);
    }
    printf("\n");

    //�������� �� ���
    insertionSort(input_ary, size);
    printf("�������� ��� : ");
    for (i = 0; i < size; i++)
    {
        printf("%c", input_ary[i]);
    }

    int j = 0;
    int k = 0;
    //��/�ҹ��� ����
    for (i = 0; i < size; i++) //�迭 ũ�⸸ŭ �ݺ�
    {
        if ((input_ary[i] >= 'A') && (input_ary[i]) <= 'Z')     //�빮���̸�
        {
            upper_ary[j] = input_ary[i]; //�빮�� �迭 0��° index���� ���� ����
            j++;
        }
        else if ((input_ary[i] >= 'a') && (input_ary[i] <= 'z')) //�ҹ����̸�
        {
            lower_ary[k] = input_ary[i]; //�ҹ��� �迭�� ����
            k++;
        }
    }

    //�빮�� ���� ���
    printf("\n\n------�빮��------\n");
    for (i = 0; i < j; i++) //i�� j������ �ݺ��ؾ� ���� �迭�� ������ ���� �� ��
    {
        printf(" %c", upper_ary[i]);
    }

    //�ҹ��� ���� ���
    printf("\n------�ҹ���------\n");
    for (i = 0; i < k; i++) //i�� k������ �ݺ��ؾ� ���� �迭�� ������ ���� �� ��
    {
        printf(" %c", lower_ary[i]);
    }

    return 0;
}

//��������
void insertionSort(char* pary, int sz)
{
    for (int i = 1; i < sz; i++)        //2��° index���� ����
    {
        for (int j = i; j > 0; j--)
        {
            if (pary[j] < pary[j - 1])  //j�� j-1�� ��
            {
                swap(&pary[j], &(pary[j - 1]));
            }
        }
    }
}

//swap
void swap(char* a, char* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp; //*b = *a 
}