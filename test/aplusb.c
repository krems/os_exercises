#include <stdio.h>
#include "aplusb.h"

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int result = add(a, b);
  printf("%d + %d = %d\n", a, b, result);
  return 0;
}

