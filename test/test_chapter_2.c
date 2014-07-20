#include <stdio.h>
#include "../src/chapter2.h"

static char *test_string = "Hamburgers";
static char *other = "pretty";
static char *none_in_common = "zzzzzzzzzzz";
static const int INDEX_OF_R = 5;

int test_2_5() {
    int index;

    if ((index = any(test_string, other)) != INDEX_OF_R) {
        printf("any failed on `any(%s, %s)==%d` -- %d\n", test_string, other, INDEX_OF_R, index);
        return NOT_FOUND;
    } else {
        printf("`any(%s, %s)==%d`\n", test_string, other, INDEX_OF_R);
    }

    if ((index = any(test_string, none_in_common)) != NOT_FOUND) {
        printf("any failed on `any(%s, %s)==%d` -- actual:%d\n", test_string, none_in_common, NOT_FOUND, index);
        return NOT_FOUND;
    } else {
        printf("`any(%s, %s)==%d`\n", test_string, none_in_common, NOT_FOUND);
    }

    return 0;
}

int main() {
    if (!test_2_5()) {
        printf("all tests passed!\n");
        return 0;
    } else {
        return 1;
    }
}

