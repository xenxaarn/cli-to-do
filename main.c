#include <stdio.h>
#include <stdlib.h>

#define MAX_TASK 200
#define MAX_LEN 250
#define FILE_NAME "todo.txt"
#define TMP_FILE "temp.txt"

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

char str[255];
FILE *fp;
FILE *ftmp;

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
  int line_numc, i = 1;
  fp = fopen(FILE_NAME, "r");
  if (fp == NULL) {
    printf("Empty\n");
    return;
  }
  while (fgets(str, 255, fp) != NULL) {
    printf("%d. %s", i++, str);
  }
  printf("Task Number: ");
  scanf("%d", &line_numc);
  rewind(fp);
  ftmp = fopen(TMP_FILE, "w");
  i = 1;
  while (fgets(str, 255, fp) != NULL) {
    if (i == line_numc) {
      fprintf(ftmp, "[*] %s", str);
    } else {
      fputs(str, ftmp);
    }
    i++;
  }
  fclose(fp);
  fclose(ftmp);
  remove(FILE_NAME);
  rename(TMP_FILE, FILE_NAME);
  printf("Completed!\n");
}

void deletetask(void) {
  int line_num, i = 1;
  fp = fopen(FILE_NAME, "r");
  if (fp == NULL) {
    printf("Empty\n");
    return;
  }
  while (fgets(str, 255, fp) != NULL) {
    printf("%d. %s", i++, str);
  }
  printf("Enter task line number to delete: ");
  scanf("%d", &line_num);
  rewind(fp);
  ftmp = fopen(TMP_FILE, "w");
  i = 1;
  while (fgets(str, 255, fp) != NULL) {
    if (i != line_num) {
      fputs(str, ftmp);
    }
    i++;
  }
  fclose(fp);
  fclose(ftmp);
  remove(FILE_NAME);
  rename(TMP_FILE, FILE_NAME);
  printf("Task deleted!\n");
}
