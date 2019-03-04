#include <stdio.h>
#include "tinyunit.h"

/* init test counters */
tu_tests_run = 0;
tu_tests_passed = 0;

void func1(int x) {
  tu_assert("oops, x < 0", x >= 0);
}

void func2(int x) {
  tu_assert("oops, x == 5", x != 5);
}

/* this test doesn't pass */
char *test_func1() {
  tu_run_test(func1(-2));
  return 0;
}

/* this test passes */
char *test_func2() {
  tu_run_test(func2(6));
  return 0;
}

int main() {
  char *result = NULL;
  result = test_func1();
  printf("test_func1: %s\n", result);
  result = test_func2();
  printf("test_func2: %s\n", result);
  
  if (tu_tests_run == tu_tests_passed) printf("ALL TESTS PASSED\n");
  else printf("%d TESTS FAILED OUT OF %d IN TOTAL\n", tu_tests_run - tests_passed, tu_tests_run);
  return 0;
}
