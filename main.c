#include <stdio.h>
#include <stdlib.h>

#define MAX_TASK 200
#define MAX_LEN 250
#define FILE_NAME "todo.txt"

typedef struct ToDo todo;
struct ToDo {
  char buffer[100];
  todo *next;
  int count;
};

todo *start = NULL;

int main(void) {
  void viewtask(void);
  void addtask(void);
  void completedtask(void);
  void deletetask(void);
  int option;
  int viewtodo;
  FILE *fp;
  fp = fopen("todo.txt", "a");
  // fputs("TESTDATA\n", fp);
  // fprintf(fp, "%s\n", str);
  fclose(fp);
  while (1) {
    // system("clear");
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
      return -1;
    }
    if (fp == NULL) {
      printf("Could not open file for write");
      return -1;
    }
  }
  return 0;
}

void viewtask(void) {
  // system("clear");
  if (start == NULL) {
    printf("To Do list is empty\n");
  }

  todo *temp;
}
char task;
void addtask(void) {
  printf("Enter task: ");
  scanf("%s", &task);
}

void completedtask(void) {}
void deletetask(void) {}
