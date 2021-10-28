#include"Linked_list.h"

void main() {
	run();
}

void run() {
	int choice = 0;
	bool main_choice = true;

	Computer* head;
	head = (Computer*)malloc(sizeof(Computer));
	head->next = NULL;

	main_display();

	while (main_choice) {
		printf("원하는 메뉴를 선택 하시오. \n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			push_computer(head);
			break;
		case 2:
			pop_computer(head);
			break;
		case 3:
			show_computer(head);
			break;
		case 4:
			main_choice = false;
			break;
		default:
			printf("1에서 4사이의 정수를 입력 하시오. \n");
			break;
		}
	}

	while (head->next != NULL) {
		Computer* next = head->next->next;
		free(head->next);
		head->next = next;
	}
	free(head);
}

void push_computer(Computer* main_com) {
	int user_ram = 0;

	Computer* temp_com;
	temp_com = (Computer*)malloc(sizeof(Computer));

	temp_com->cpu = (char*)malloc(sizeof(char) * 50);
	temp_com->name = (char*)malloc(sizeof(char) * 50);

	temp_com->next = main_com->next;
	main_com->next = temp_com;
	printf("1. push 할 데이터를 입력 하시오.\n");
	printf("ram  : ");
	scanf("%d", &user_ram);
	temp_com->ram = user_ram;
	printf("cpu  : ");
	scanf("%s", temp_com->cpu);
	printf("name : ");
	scanf("%s", temp_com->name);
}

void pop_computer(Computer* main_com) {
	Computer* pop_com;
	Computer* temp_com;
	pop_com = (Computer*)malloc(sizeof(Computer));
	temp_com = (Computer*)malloc(sizeof(Computer));
	pop_com->name = (char*)malloc(sizeof(char) * 50);

	printf("1. pop 할 데이터를 입력 하시오.\n");
	printf("name : ");
	scanf("%s", pop_com->name);
	while (main_com -> next != NULL) {
		if (strcmp(main_com->next->name , pop_com->name)==0) {
			temp_com->next = main_com->next->next;
			//free(main_com->next);
			main_com->next = temp_com->next;
			free(temp_com);
		}
		main_com = main_com->next;
		if (main_com == NULL) {
			break;
		}
	}
}

void show_computer(Computer* head) {
	Computer* show_com;
	show_com = (Computer*)malloc(sizeof(Computer));
	show_com = head->next;

	int count = 1;
	while (show_com != NULL) {
		printf("%d. ram  : %d\n", count, show_com->ram);
		printf("%d. cpu  : %s\n", count, show_com->cpu);
		printf("%d. name : %s\n \n", count, show_com->name);
		show_com = show_com->next;
		count++;
	}
}