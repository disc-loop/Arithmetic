#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/* #include <time.h> */

// This program is designed to quiz the user on arithmetic. It does so by asking them to evaluate randomly generated expressions. Inspired by [Stack Overflow](https://stackoverflow.com/questions/14472680/how-to-get-and-evaluate-the-expressions-from-a-string-in-c) post my Steve Summit

// TODO: Generate an expression
char *genExpr(void);

int eval(const char *);
int evalexpr(const char **);
int evalterm(const char **);
int evalpri(const char **);
int gettok(const char **, int *);
void ungettok(int, const char **);
void skipwhite(const char **);

// TODO: Evaluate user's solution
//
// TODO: Give user feedback on their solution, e.g. right or wrong, time taken to evaluate, etc.

int main (void) {
  char *expr = genExpr();
  int solution = eval(expr);
  char line[100];
  while (1) {
    printf("Solve: %s\n", expr);
    fgets(line, sizeof line, stdin);
    if (eval(line) == solution) {
      printf("Correct!\n");
    } else {
      printf("Incorrect\n");
    }
    printf("\n");
  }
}

char *genExpr(void) {
  return "2 + 2";
}

int eval(const char *expr) {
  return evalexpr(&expr);
}

int evalexpr(const char **p) {
  int result = evalterm(p);
  while (1) {
    int token = gettok(p, NULL);
    switch (token) {
      case '+': result += evalterm(p); break;
      case '-': result -= evalterm(p); break;
      default: ungettok(token, p); return result;
    }
  }
}

int evalterm(const char **p) {
  int result = evalpri(p);
  while(1) {
    int token = gettok(p, NULL);
    switch (token) {
      case '*': result *= evalpri(p); break;
      case '/': result /= evalpri(p); break;
      default: ungettok(token, p); return result;
    }
  }
}

int evalpri(const char **p) {
  int v;
  int token = gettok(p, &v);
  switch (token) {
    case '1': return v;
    case '-': return -evalpri(p);
    case '(':
      v = evalexpr(p);
      token = gettok(p, NULL);
      if(token != ')') {
        fprintf(stderr, "missing ')'\n");
        ungettok(token, p);
      }
      return v;
  }
  // FIXME: I've only put this here because the compiler was complaining about not being able to return
  return 0;
}

int gettok(const char **p, int *vp) {
  skipwhite(p);
  // This gets the actual "token" (character at current pointer)
  char c = **p;
  if (isdigit(c)) {
    char *p2;
    int v = strtoul(*p, &p2, 0);
    *p = p2;
    // What is the purpose of this? What is going on with the if statement?
    if (vp) *vp =v; 
      return '1';
  }
  (*p)++;
  return c;
}

void skipwhite(const char **p) {
  while (isspace(**p)) {
    // Moves the pointer to point to the next character
    (*p)++;
  }
}

void ungettok(int op, const char **p) {
  (*p)--;
}
