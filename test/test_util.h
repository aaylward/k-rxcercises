#ifndef TEST_UTIL
#define TEST_UTIL

#include <stdio.h>

#define ERROR -1
#define SUCCESS 0

/* TEST should be an int */
#define ASSERT( MESSAGE , TEST , EXPECTED ) ({ \
    int actual = TEST; \
    if (actual != EXPECTED) { \
        printf("%s Expected: %d, Got: %d\n", MESSAGE, EXPECTED, actual); \
        return ERROR; \
    } \
})

#endif
