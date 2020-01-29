/****************************************************************************************************
 * Exercise 1: prompt the user for input and draw a diamond shape out of numbers
 *or an inverted diamond depending on the user choice. No arrays should be used
 *and the algorithm must rely only on loops.
 ****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Number of rows for half of the diamond.
int rows = 9;

char *get_input() {
  char ch;
  static char input[1];
  printf("\n");
  printf("Enter either: \n 1 - Diamon \n 2 - Inverted Diamond \n anything else "
         "will quit:\n ");
  ch = getchar();
  int char_count = 0;
  while ((ch != '\n') && (char_count < 3)) {
    input[char_count++] = ch;
    ch = getchar();
  }
  input[char_count] = '\0';

  printf("\n");
  return input;
}

void diamond() {
  // upper part
  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= (rows - i) + 2; j++) {
      printf(" ");
    }
    for (int j = 1; j <= i * 2; j++) {
      printf("%d", i);
    }
    printf("\n");
  }
  // lower part
  for (int i = rows - 1; i >= 1; i--) {
    for (int j = 1; j <= (rows - i) + 2; j++) {
      printf(" ");
    }
    for (int j = 1; j <= i * 2; j++) {
      printf("%d", i);
    }
    printf("\n");
  }
}

void inverted_diamond() {
  // upper part
  for (int i = 1; i <= rows; i++) {
    for (int j = i; j <= rows; j++) {
      printf("%d", (rows - i) + 1);
    }
    for (int j = 1; j < (2 * i - 1); j++) {
      printf(" ");
    }
    for (int j = i; j <= rows; j++) {
      printf("%d", (rows - i) + 1);
    }
    printf("\n");
  }

  // lower part
  for (int i = 2; i <= rows; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%d", i);
    }
    for (int j = i; j <= (2 * rows - i - 1); j++) {
      printf(" ");
    }
    for (int j = 1; j <= i; j++) {
      printf("%d", i);
    }
    printf("\n");
  }
}

int main() {
  int choice;
  choice = atoi(get_input());

  while (choice == 1 || choice == 2) {
    switch (choice) {
    case 1:
      diamond();
      choice = atoi(get_input());
      break;
    case 2:
      inverted_diamond();
      choice = atoi(get_input());
      break;
    default:
      printf("Adios!\n");
      exit(0);
    }
  }
  return 0;
}
