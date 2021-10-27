#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#pragma warning(disable:4996)

typedef struct computer {
    int ram;
    char* cpu;
    char* name;
    struct computer* next;
}Computer;

void run();
void push_computer(Computer* main_com);
void pop_computer(Computer* main_com);
void show_computer(Computer* show_com);

void main_display() {
    printf("------  menu   ------\n");
    printf("------ 1. push ------\n");
    printf("------ 2. pop  ------\n");
    printf("------ 3. show ------\n");
    printf("------ 4. end  ------\n");
    printf("---------------------\n");
}