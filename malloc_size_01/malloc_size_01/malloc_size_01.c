#include"malloc_size_01.h"

void main() {
	run();
}

void run() {
	int count = 0, choice = 0;
	int* pnum;
	int* temp;
	pnum = (int*)malloc(sizeof(int));
	temp = (int*)malloc(sizeof(int));
	main_display();
	while (1) {
		printf("원하는 메뉴를 선택 하시오, \n");
		scanf("%d",&choice);
		if (1<=choice&&choice<=3) {
			switch (choice) {
			case 1:
				if (count == 0) {
					pnum = first_push_data(pnum);
					count++;
					break;
				}else
				pnum = push_data(pnum);
				break;
			case 2:
				pnum = pop_data(pnum);
				break;
			case 3 :
				show(pnum);
				break;
			}
		}else if (choice == 4) {
			free(pnum);
			break;
		}else{
			printf("1에서 4 사이의 정수를 입력 하시오.");
		}
	}
}

int* first_push_data(int* pnum) {
	int user_num = 0;
	printf("push 하고 싶은 데이터를 입력 하시오. \n");
	scanf("%d", &user_num);
	pnum[0] = user_num;
	return pnum;
}

int* push_data(int* pnum) {
	int i = 0, pnum_size=0, user_num=0;
	int* temp;
	pnum_size = _msize(pnum)/4;
	printf("push 하고 싶은 데이터를 입력 하시오. \n");
	scanf("%d", &user_num);
	temp = (int*)malloc(sizeof(int) * (pnum_size+1));
	for (i=0;i< pnum_size;i++) {
		temp[i] = pnum[i];
	}
	temp[pnum_size] = user_num;
	free(pnum);
	pnum = (int*)malloc(sizeof(int) * (pnum_size+1));
	for (i=0;i<pnum_size+1;i++) {
		pnum[i] = temp[i];
	}
	free(temp);
	return pnum;
}
int* pop_data(int* pnum) {
	int i = 0, pnum_size = 0, user_num = 0, user_count=0;
	int* temp;
	pnum_size = _msize(pnum) / 4;
	printf("pop 하고 싶은 데이터를 입력 하시오. \n");
	scanf("%d", &user_num);
	temp = (int*)malloc(sizeof(int) * (pnum_size));
	for (i = 0;i<pnum_size;i++) {
		if (pnum[i] != user_num) {
			temp[user_count] = pnum[i];
			user_count++;
		}
	}
	free(pnum);
	pnum = (int*)malloc(sizeof(int) * (user_count));
	for (i=0;i<user_count;i++) {
		pnum[i] = temp[i];
	}
	free(temp);
	return pnum;
}

void show(int* pnum) {
	int i = 0, pnum_size=0;
	pnum_size = _msize(pnum)/4;
	for (i=0;i<pnum_size;i++) {
		printf("%d pnum : %d \n", i+1, *(pnum+i));
	}
}