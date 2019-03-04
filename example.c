#include <stdio.h>
#include "tinyunit.h"

/* init test counters */
tu_tests_run = 0;
tu_tests_passed = 0;

int x = 10;
int y = -2;

char *test_x() {
  tu_assert("oops, x != 10", x == 10);
  return 0;
}
char *test_y() {
  tu_assert("oops, x > 0", x < 0);
  return 0;
}
char *all_tests() {
  tu_run_test(test_x);
  tu_run_test(test_y);
  return 0;
}

int main() {
  char *result = all_tests();
  
  if (tu_tests_run == tu_tests_passed) printf("ALL TESTS PASSED\n");
  else printf("%d TESTS FAILED OUT OF %d IN TOTAL\n", tu_tests_run - tu_tests_passed, tu_tests_run);
  return 0;
}
