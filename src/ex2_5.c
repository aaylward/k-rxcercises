#include <string.h>
#include "chapter2.h"

/*
 *  Excercise 2-5:
 *  Write a function `any(char s[], char t[])`, which returns the first location
 *  in the string `s` where any character from `t` occurs, or `-1` if s contains
 *  no characters from t.
 *
 *  This function assumes that both s and t are ascii strings.
 *  @bugs aaylward@gmail.com <Andy Aylward>
 */
int any(char s[], char t[]) {
    char ascii[MAX_ASCII];
    size_t i, j;

    i = j = 0;

    initializeAsciiArray(ascii);

    /* map of characters in t */
    for (; j<strlen(t); j++) {
        ascii[(int) t[j]] = 1;
    }

    for (; i<strlen(s); i++) {
        if (ascii[(int) s[i]] == 1) {
            return i;
        }

    }

    return NOT_FOUND;
}

