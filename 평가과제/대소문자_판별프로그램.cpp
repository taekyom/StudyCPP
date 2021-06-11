/*
    대소문자 판별 프로그램
    배열 사용시 :
    1. 입력받을 배열 이름 : input_ary
    2. 배열의 크기는 10
    3. 삽입정렬 사용
    4. 삽입정렬 알고리즘을 함수로 구현
    5. 소문자 저장 배열이름 : lower_ary
       대문자 저장 배열이름 : upper_ary

    연결리스트 사용시 :
    1. 2. 4 동일
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void insertionSort(char* pary, int sz);	// 삽입 정렬 함수
void swap(char* a, char* b);		    // swap 함수

int main()
{
    char input_ary[10];            //크기가 10인 배열
    char* upper_ary, * lower_ary; //대/소문자 저장 배열

    //대/소문자 동적할당
    upper_ary = (char*)malloc(sizeof(char));
    lower_ary = (char*)malloc(sizeof(char));

    int i;
    int size = sizeof(input_ary) / sizeof(input_ary[0]);

    printf("알파벳을 10개를 입력하세요 : ");
    for (i = 0; i < size; i++)
    {
        scanf(" %c", &input_ary[i]);
    }
    printf("\n");

    //삽입정렬 후 출력
    insertionSort(input_ary, size);
    printf("삽입정렬 결과 : ");
    for (i = 0; i < size; i++)
    {
        printf("%c", input_ary[i]);
    }

    int j = 0;
    int k = 0;
    //대/소문자 구별
    for (i = 0; i < size; i++) //배열 크기만큼 반복
    {
        if ((input_ary[i] >= 'A') && (input_ary[i]) <= 'Z')     //대문자이면
        {
            upper_ary[j] = input_ary[i]; //대문자 배열 0번째 index부터 저장 시작
            j++;
        }
        else if ((input_ary[i] >= 'a') && (input_ary[i] <= 'z')) //소문자이면
        {
            lower_ary[k] = input_ary[i]; //소문자 배열에 저장
            k++;
        }
    }

    //대문자 정렬 출력
    printf("\n\n------대문자------\n");
    for (i = 0; i < j; i++) //i가 j까지만 반복해야 남는 배열에 쓰레기 값이 안 들어감
    {
        printf(" %c", upper_ary[i]);
    }

    //소문자 정렬 출력
    printf("\n------소문자------\n");
    for (i = 0; i < k; i++) //i가 k까지만 반복해야 남는 배열에 쓰레기 값이 안 들어감
    {
        printf(" %c", lower_ary[i]);
    }

    return 0;
}

//삽입정렬
void insertionSort(char* pary, int sz)
{
    for (int i = 1; i < sz; i++)        //2번째 index부터 시작
    {
        for (int j = i; j > 0; j--)
        {
            if (pary[j] < pary[j - 1])  //j와 j-1만 비교
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