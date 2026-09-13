#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK = 200;
#define MAX_LEN = 250;
#define FILE_NAME = "todo.txt";

int main() {
  while (1) {
    printf("\n --CLI To-Do-- \n");
    printf("1= View a task?\n");
    printf("2= Add a task?\n");
    printf("3= Task Completed?\n");
    printf("4= Delete a task?\n");
    printf("5= Exit?\n");
    printf("Enter any num frm 1 to 5\n");
  }
  return 0;
}
