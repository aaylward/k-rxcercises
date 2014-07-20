#include <stdio.h>
#include "../src/chapter2.h"

static char *test_string = "Hamburgers";
static char *other = "pretty";
static char *none_in_common = "zzzzzzzzzzz";
static const int INDEX_OF_R = 5;

int main() {
    if (any(test_string, other) != INDEX_OF_R) {
        printf("any failed on `any(%s, %s)==%d`\n", test_string, other, INDEX_OF_R);
        return NOT_FOUND;
    } else {
        printf("`any(%s, %s)==%d`\n", test_string, other, INDEX_OF_R);
    }

    if (any(test_string, none_in_common) != NOT_FOUND) {
        printf("any failed on `any(%s, %s)==%d`\n", test_string, none_in_common, NOT_FOUND);
        return NOT_FOUND;
    } else {
        printf("`any(%s, %s)==%d`\n", test_string, none_in_common, NOT_FOUND);
    }

    printf("all tests passed!\n");
    return 0;
}

