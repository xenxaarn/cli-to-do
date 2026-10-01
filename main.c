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
  while (1) {
    printf("\n --CLI-TO-DO-- \n");
    printf("1. = View a task\n");
    printf("2. = Add a task\n");
    printf("3. = Completed task\n");
    printf("4. = Delete a task\n");
    printf("5. = Exit\n");
    printf("Choose any option : ");
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
  }
  return 0;
}

todo *temp;
char str[255];
FILE *fp;

void viewtask(void) {
  fp = fopen("todo.txt", "r");
  int i = 1;
  if (fp == NULL) {
    printf("Empty\n");
    return;
  }
  while (fgets(str, 255, fp) != NULL) {
    printf("%d, %s", i, str);
    i++;
  }
  fclose(fp);
}

char task[100];
FILE *fp;
void addtask(void) {
  fp = fopen("todo.txt", "a");
  printf("Addtask : ");
  scanf(" %99[^\n]", task);
  fprintf(fp, "%s\n", task);
  system("clear");
  fclose(fp);
}

void completedtask(void) {
  fp = fopen("todo.txt", "r");
  int line_numc;
  int i = 1;
  if (fp == NULL) {
    printf("Empty\n");
    return;
  }
  while (fgets(str, 255, fp) != NULL) {
    printf("%d, %s", i, str);
    i++;
  }

  printf("Enter task line number :");
  scanf("%d", &line_numc);

  printf("Task has been Completed !\n");
  fclose(fp);
}

void deletetask(void) {
  fp = fopen("todo.txt", "r");
  int line_num;
  int i = 1;
  if (fp == NULL) {
    printf("Empty\n");
    return;
  }
  while (fgets(str, 255, fp) != NULL) {
    printf("%d, %s", i, str);
    i++;
  }
  printf("delete : ");
  scanf("%d", &line_num);

  printf("\nTask has been deleted !!\n");
  fclose(fp);
}
