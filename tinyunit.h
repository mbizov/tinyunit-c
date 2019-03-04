#ifndef _TINYUNIT_H_
#define _TINYUNIT_H_
#endif

extern int tu_tests_run;
extern int tu_tests_passed;

#define tu_assert(test, msg) do { if (!(test)) return msg; } while (0)
#define tu_run_test(test) do { \
                            char *msg = test(); \
                            tu_tests_run++; \
                            if (msg) return msg; \
                            tu_tests_passed++; \
                          } while (0)
