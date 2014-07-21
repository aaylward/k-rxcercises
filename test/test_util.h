#ifndef TEST_UTIL
#define TEST_UTIL

#include <stdio.h>

#define ERROR -1
#define SUCCESS 0

/* TEST functions that return `int` */
#define ASSERT_INT( MESSAGE , EXPECTED , TEST ) { \
    int _actual = TEST; \
    if (_actual != EXPECTED) { \
        printf("%s Expected: %d, Got: %d\n", MESSAGE, EXPECTED, _actual); \
        return ERROR; \
    } \
}

#endif
