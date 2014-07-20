#include <stdio.h>
#include "../src/chapter2.h"
#include "test_util.h"

static char *test_string = "Hamburgers";
static char *other = "pretty";
static char *none_in_common = "zzzzzzzzzzz";
static char *last_matches = "zips";
static const int INDEX_OF_R = 5;
static const int INDEX_OF_S= 9;

int test_2_5() {
    ASSERT_INT( "`any` failed to find first instance of 'r'", any(test_string, other), INDEX_OF_R);
    ASSERT_INT( "`any` should return -1 if there are no characters in common", any(test_string, none_in_common), NOT_FOUND);
    ASSERT_INT( "`any` failed to find first instance of 's'", any(test_string, last_matches), INDEX_OF_S);
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

