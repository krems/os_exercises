#include "aplusb.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

static const char* formatStr = "Result is %d. Should be %d";

void assert(int statement, char* erMsg) {
  if (!statement) {
    fprintf(stderr, "FAIL\n%s\n", erMsg);
  } else {
    fprintf(stdout, "PASSED\n");
  }
}


void test_ordinary_case() {
  printf("test_ordinary_case\n");
  int act = add(3, 2);
  int exp = 5;
  char out[strlen(formatStr) + 1];
  sprintf(out, formatStr, exp, act);
  assert(act == exp, out);
}

void test_negatives() {
  printf("test_negatives\n");
  int act = add(-3, -2);
  int exp = -5;
  char out[strlen(formatStr) + 1];
  sprintf(out, formatStr, exp, act);
  assert(act == exp, out);
}

void test_negative_and_positive() {
  printf("test_negative_and_positive\n");
  int act = add(-3, 2);
  int exp = -1;
  char out[strlen(formatStr) + 1];
  sprintf(out, formatStr, exp, act);
  assert(act == exp, out);
}

void test_positive_and_negative() {
  printf("test_positive_and_negative\n");
  int act = add(3, -2);
  int exp = 1;
  char out[strlen(formatStr) + 1];
  sprintf(out, formatStr, exp, act);
  assert(act == exp, out);
}

void test_zeros() {
  printf("test_zeros\n");
  int act = add(0, 0);
  int exp = 0;
  char out[strlen(formatStr) + 1];
  sprintf(out, formatStr, exp, act);
  assert(act == exp, out);
}

void test_one_zero() {
  printf("test_one_zero\n");
  int act = add(0, 9);
  int exp = 9;
  char out[strlen(formatStr) + 1];
  sprintf(out, formatStr, exp, act);
  assert(act == exp, out);
}

void test_very_big_numbers() {
  printf("test_very_big_numbers\n");
  int act = add(INT_MAX, INT_MAX);
  const char* fmt = "Expected less than zero. Actual %d\n";
  char out[strlen(fmt) + 1];
  sprintf(out, fmt, act);
  assert(act = 0, out);
}

int main() {
  test_ordinary_case();
  test_negatives();
  test_negative_and_positive();
  test_positive_and_negative();
  test_zeros();
  test_one_zero();
  test_very_big_numbers();
  return 0;
}
