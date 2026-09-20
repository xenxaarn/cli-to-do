#include <stdio.h>
#include <stdlib.h>

#define MAX_TASK 200
#define MAX_LEN 250
#define FILE_NAME = "todo.txt";

typedef struct ToDo todo;
struct ToDo {
  char buffer[100];
  todo *next;
  int count;
};

int main(void) {
  void viewtask();
  void addtask();
  void completedtask();
  void deletetask();
  int option;
  int viewtodo;
  FILE *fp;
  fp = fopen("todo.txt", "w");
  fclose(fp);
  while (1) {
    system("clear");
    printf("\n --CLI To-Do-- \n");
    printf("1. = View a task\n");
    printf("2. = Add a task\n");
    printf("3. = Completed task\n");
    printf("4. = Delete a task\n");
    printf("5. = Exit\n");
    printf("Choose any option\n");
    scanf(" %d", &option);
    switch (option) {
    case 1:
      viewtask();
      break;
    case 2:
      addtask();
      break;
    case 3:
      completedtask();
      break;
    case 4:
      deletetask();
      break;
    }
    if (option == 5) {
      exit(1);
    }
    if (option > 5) {
      printf("\nInvalid Number\n");
    }
    if (fp == NULL) {
      printf("Could not open file for write");
      return 1;
    }
  }
  return 0;
}

void viewtask();
void addtask();
void completedtask();
void deletetask();
