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
    printf("����� �޴��� ���Ͽ� ���ϴ� �迭�� ����ÿ�.\n");
}
/*
--����--
 MENU
 1. push
 2. pop
 3. show
 4. end

 breif
 1. push ������ ����
 2. pop ������ ���� //�� ���ڸ� ����
 3. ������ ���
*/