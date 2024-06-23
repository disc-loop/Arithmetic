#include <stdio.h>
/* #include <stdlib.h> */
/* #include <time.h> */

// This program is designed to quiz the user on arithmetic. It does so by asking them to evaluate randomly generated expressions.
// TODO: Generate an expression
// TODO: Generate solution for a given expression
// TODO: Prompt the user with the expression
// TODO: Evaluate expression
// TODO: Give user feedback on their solution, e.g. right or wrong, time taken to evaluate, etc.
int main () {
  char line[10];
  while (1) {
    printf("Say something\n");
    fgets(line, sizeof line, stdin);
    printf("%s", line);
  }
}
