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

FILE *fp;

todo *start = NULL;

int main(void) {
  void viewtask(void);
  void addtask(void);
  void completedtask(void);
  void deletetask(void);
  int option;
  fp = fopen("todo.txt", "a");
  while (1) {
    system("clear");
    printf("\n --CLI-TO-DO-- \n");
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
      return 0;
    }
    if (option > 5) {
      printf("\nInvalid Number\n");
      return 0;
    }
    if (fp == NULL) {
      printf("Could not open file for write");
      return 1;
    }
    if (start == NULL) {
      printf("To Do list is empty\n");
    }
  }

  fclose(fp);
  return 0;
}

todo *temp;
// should display the content based on the todo number thats in the file
void viewtask(void) {}

char task[100];
void addtask(void) {
  printf("Addtask : ");
  scanf("%s\n", task);
  fprintf(fp, "%s\n", task);
  system("clear");
}

void completedtask(void) {}

void deletetask(void) {}
