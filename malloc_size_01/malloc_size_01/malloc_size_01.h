#include<stdio.h>
#pragma warning(disable:4996)
void run();
int* first_push_data(int* pnum);
int* push_data(int* pnum);
int* pop_data(int* pnum);
void show(int* pnum);
void main_display() {
    printf("--------MENU--------\n");
    printf("----- 1. push ------\n");
    printf("----- 2. pop  ------\n");
    printf("----- 3. show ------\n");
    printf("----- 4. end  ------\n");
    printf("--------------------\n");
    printf("상단의 메뉴를 통하여 원하는 배열을 만드시오.\n");
}
/*
--문제--
 MENU
 1. push
 2. pop
 3. show
 4. end

 breif
 1. push 데이터 삽입
 2. pop 데이터 해제 //그 숫자만 삭제
 3. 데이터 출력
*/