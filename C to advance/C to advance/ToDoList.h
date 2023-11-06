/*
*
* Add list
* Remove List
* Mark Task When Complete
*
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


char toDoList[100][2][1024];
int currentIndex = 0;

void add();
void clean();
void mark();

void ToDo_main() {
	int i; //index uses
	int option;

	do {
		system("cls");
		printf("[To Do List]\n\n");
		printf("Please select the following option :\n");
		printf("[1] Add list\n");
		printf("[2] Remove list\n");
		printf("[3] Mark list\n\n");

		printf(">> ");
		scanf("%d", &option);
		rewind(stdin);
	} while (option != 1 && option != 2 && option != 3);

	switch (option) {
	case 1:
		add();
		break;
	case 2:
		clean();
		break;
	case 3:
		mark();
		break;
	default:
		printf("[Error]\n");
	}
}

void add() {
	char task[500];
	do {
		system("cls");
		printf("[To Do List]\n\n");
		printf("_________________________________________________\n");
		for (int i = 0; i < currentIndex; i++) {
			printf("%02d. %-50s %s\n", i + 1, toDoList[i][0], toDoList[i][1]);
		}
		printf("\n\n\n");
		printf("Please enter your task (0 to exit) >> ");
		scanf("%[^\n]", &task);
		rewind(stdin);

		if (strcmp(task, "0") != 0) {
			strcpy(toDoList[currentIndex][0], task);
			strcpy(toDoList[currentIndex][1], "");

			system("cls");
			currentIndex += 1;
		}
	} while (strcmp(task, "0") != 0);
	
	ToDo_main();

}

void clean() {
	int select;
	do {
		system("cls");
		printf("[To Do List]\n\n");
		printf("_________________________________________________\n");
		for (int i = 0; i < currentIndex; i++) {
			printf("%02d. %-50s %s\n", i + 1, toDoList[i][0], toDoList[i][1]);
		}
		printf("\n\nSelect its index number to delete (0 to exit)\n");
		printf(">> ");
		scanf("%d", &select);
		rewind(stdin);
		if (select != 0) {
			strcpy(toDoList[select - 1][0], "[Canceled]");
			strcpy(toDoList[select - 1][1], "[Canceled]");
		}
			

	} while (select != 0);
	ToDo_main();
}

void mark() {
	int select;
	do {
		system("cls");
		printf("[To Do List]\n\n");
		printf("_________________________________________________\n");
		for (int i = 0; i < currentIndex; i++) {
			printf("%02d. %-50s %s\n", i + 1, toDoList[i][0], toDoList[i][1]);
		}
		printf("\n\nSelect its index number when completed (0 to exit)\n");
		printf(">> ");
		scanf("%d", &select);
		rewind(stdin);
		if (select != 0) {
			if (strcmp(toDoList[select - 1][1],"")==0)
				strcpy(toDoList[select - 1][1], "[Completed]");
		}
			
		
	} while (select != 0);
	ToDo_main();
}