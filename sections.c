#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *gptr;
char *gptr_init = "Hello";
char gbuffer[666];
char gbuffer_init[] = "abcdef";
int gvar;
int gvar_init = 111;
static int gstatic;
static int gstatic_init = 222;


void f(int a, char *b) {
  int lvar;
  int lvar_init = 333;
  static int lstatic;
  static int lstatic_init = 444;
  char lbuffer[777];
  char lbuffer_init[] = "zyxwvu";

  char* lptr;
  char* lptr_init = malloc(1000 * sizeof(char));
  gptr = lptr_init;
  lptr = gptr;
  strncpy(lptr, "abcde", 5);
  strncpy(lbuffer, "fghij", 5);
  strncpy(gbuffer, "klmnop", 6);
  strncat(lptr, lbuffer, 5);
  strncat(lptr, gbuffer, 6);
  strncat(lptr, b, 1000 - strlen(lptr));
  
  lvar = a;
  lstatic = lvar;
  gstatic = lvar;
  lstatic_init += 1;
  printf("%d %d\n", lstatic, lstatic_init);
}

int main() {
  f(1, "string");
  fprintf(stderr, "%s\n", gptr_init);
  printf("%s\n", gptr);
  f(1, "qrstuvwxyz");
  return 0;
}

