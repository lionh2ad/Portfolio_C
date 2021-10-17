#include"struct_vector.h"

void main() {
	run();
}

void run() {
	int count = 0, choice = 0;
	bool choice_bool = true;
	Lion* leo;
	leo = (Lion*)malloc(sizeof(Lion));
	main_display();
	while (choice_bool) {
		printf("원하는 메뉴를 선택 하시오. \n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			if (count == 0) {
				leo = first_push_data(leo);
				count++;
			}
			else {
				leo = push_data(leo);
			}
			break;
		case 2:
			leo = pop_data(leo);
			break;
		case 3:
			show_data(leo);
			break;
		case 4:
			free(leo);
			choice_bool = false;
			break;
		default:
			printf("1에서 4사이의 정수를 입력 하시오. \n");
		}
	}
}

Lion* first_push_data(Lion* leo) {
	int leo_size = 0, user_money = 0;
	float user_old = 0;

	leo[0].name = (char*)malloc(sizeof(char) * 100);

	printf("push 메뉴를 선택 하셨습니다. \n\n");
	printf("가격을 입력 하시오. \n money : ");
	scanf("%d", &user_money);
	printf("이름을 입력 하시오. \n name : ");
	scanf("%s", leo[leo_size].name);
	printf("나이를 입력 하시오. \n old : ");
	scanf("%f", &user_old);
	printf("\n\n");

	leo[0].money = user_money;
	leo[0].old = user_old;

	return leo;
}
Lion* push_data(Lion* leo) {
	int i = 0, leo_size = 0, user_money = 0;
	float user_old = 0;
	Lion* temp_leo;
	leo_size = _msize(leo) / 12;
	temp_leo = (Lion*)malloc(sizeof(Lion) * (leo_size + 1));
	for (i = 0; i < leo_size + 1; i++) {
		temp_leo[leo_size].name = (char*)malloc(sizeof(char) * 100);
	}
	for (i = 0; i < leo_size; i++) {
		temp_leo[i].money = leo[i].money;
		temp_leo[i].name = leo[i].name;
		temp_leo[i].old = leo[i].old;
	}

	free(leo);

	printf("push 메뉴를 선택 하셨습니다. \n\n");
	printf("가격을 입력 하시오. \n money : ");
	scanf("%d", &user_money);
	printf("이름을 입력 하시오. \n name : ");
	scanf("%s", temp_leo[leo_size].name);
	printf("나이를 입력 하시오. \n old : ");
	scanf("%f", &user_old);
	printf("\n\n");

	temp_leo[leo_size].money = user_money;
	temp_leo[leo_size].old = user_old;

	leo = (Lion*)malloc(sizeof(Lion) * (leo_size + 1));
	for (i = 0; i < leo_size + 1; i++) {
		leo[i].name = (char*)malloc(sizeof(char) * 100);
	}

	for (i = 0; i < leo_size + 1; i++) {
		leo[i].money = temp_leo[i].money;
		leo[i].name = temp_leo[i].name;
		leo[i].old = temp_leo[i].old;
	}

	free(temp_leo);
	return leo;
}

Lion* pop_data(Lion* leo) {
	int i = 0, leo_size = 0, user_pop_data = 0;

	Lion* temp_leo;
	leo_size = _msize(leo) / 12;
	temp_leo = (Lion*)malloc(sizeof(Lion) * (leo_size));
	for (i = 0; i < leo_size; i++) {
		temp_leo[leo_size].name = (char*)malloc(sizeof(char) * 100);
	}
	for (i = 0; i < leo_size; i++) {
		temp_leo[i].money = leo[i].money;
		temp_leo[i].name = leo[i].name;
		temp_leo[i].old = leo[i].old;
	}
	free(leo);

	printf("pop 메뉴를 선택 하셨습니다. \n\n");
	printf("pop을 진행 시킬 번호를 입력 하시오. \n");
	scanf("%d", &user_pop_data);

	leo = (Lion*)malloc(sizeof(Lion) * (leo_size - 1));
	for (i = 0; i < leo_size - 1; i++) {
		leo[i].name = (char*)malloc(sizeof(char) * 100);
	}

	for (i = 0; i < user_pop_data - 1; i++) {
		leo[i].money = temp_leo[i].money;
		leo[i].name = temp_leo[i].name;
		leo[i].old = temp_leo[i].old;
	}

	for (i = user_pop_data - 1; i < leo_size - 1; i++) {
		leo[i].money = temp_leo[i + 1].money;
		leo[i].name = temp_leo[i + 1].name;
		leo[i].old = temp_leo[i + 1].old;
	}

	free(temp_leo);

	return leo;
}
void show_data(Lion* leo) {
	int i = 0, leo_size = 0;
	leo_size = _msize(leo) / 12;
	for (i = 0; i < leo_size; i++) {
		printf("%d번째 가격은 : %d \n", i + 1, leo[i].money);
		printf("%d번째 이름은 : %s \n", i + 1, leo[i].name);
		printf("%d번째 나이는 : %.2f \n\n", i + 1, leo[i].old);
	}
}