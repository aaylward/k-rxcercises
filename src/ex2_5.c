#include <string.h>
#include <limits.h>
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
    char ascii[UCHAR_MAX];
    size_t i, j;

    initializeAsciiArray(ascii);

    /* map of characters in t */
    for (i=0; i<strlen(t); i++) {
        ascii[(int) t[i]] = 1;
    }

    /* find first occurence of a character in t */
    for (j=0; j<strlen(s); j++) {
        if (ascii[(int) s[j]] == 1) {
            return j;
        }

    }

    return NOT_FOUND;
}

