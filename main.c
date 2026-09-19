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
  int choice;
  FILE *fp;
  fp = fopen("todo.txt", "a");
  fclose(fp);
  while (1) {
    printf("\n --CLI To-Do-- \n");
    printf("1 = View a task\n");
    printf("2 = Add a task\n");
    printf("3 = Task Completed\n");
    printf("4 = Delete a task\n");
    printf("5 = Exit\n");
    printf("Choose any option frm 1 to 5\n");
    scanf(" %d", &choice);
    if (choice > 5) {
      printf("Invalid Number !!!\n");
      exit(choice);
    }
  }
  return 0;
}
