#include<stdio.h>
#include<stdbool.h>
#pragma warning(disable:4996)

typedef struct lion {
    int money;
    char* name;
    float old;
}Lion;

void run();
Lion* first_push_data(Lion* leo);
Lion* push_data(Lion* leo);
Lion* pop_data(Lion* leo);
void show_data(Lion* leo);

void main_display() {
    printf("--------MENU--------\n");
    printf("----- 1. push ------\n");
    printf("----- 2. pop  ------\n");
    printf("----- 3. show ------\n");
    printf("----- 4. end  ------\n");
    printf("--------------------\n");
    printf("상단의 메뉴를 통하여 원하는 사자의 목록을 만드시오.\n");
}