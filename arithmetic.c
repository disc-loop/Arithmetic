#include <stdio.h>
/* #include <stdlib.h> */
/* #include <time.h> */

// This program is designed to quiz the user on arithmetic. It does so by asking them to evaluate randomly generated expressions. Inspired by [Stack Overflow](https://stackoverflow.com/questions/14472680/how-to-get-and-evaluate-the-expressions-from-a-string-in-c) post my Steve Summit
// TODO: Generate an expression
char *genExpr(void);
// TODO: Evaluate solution for a given expression
char *eval(char *expr);
// TODO: Prompt the user with the expression
// TODO: Evaluate user's solution
// TODO: Give user feedback on their solution, e.g. right or wrong, time taken to evaluate, etc.

int main (void) {
  char *expr = genExpr();
  char *solution = eval(expr);
  char line[10];
  while (1) {
    printf("Solve: %s\n", expr);
    fgets(line, sizeof line, stdin);
    if (*line == *solution) {
      printf("Correct!\n");
    } else {
      printf("Incorrect\n");
    }
  }
}

char *genExpr(void) {
  return "2 + 2";
}

char *eval(char *expr) {
  if (expr) {};
  return "4";
}
