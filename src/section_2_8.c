#include <string.h>
#include <limits.h>
#include "chapter2.h"

/*
 *  Excercises from K&R C, section 2.8
 *  @bugs aaylward@gmail.com <Andy Aylward>
 */

/*
 *  Excercise 2-5:
 *  Write a function `any(char s[], char t[])`, which returns the first location
 *  in the string `s` where any character from `t` occurs, or `-1` if s contains
 *  no characters from t.
 *
 *  This only works with ascii strings.
 */
int any(char s[], char t[]) {
    char ascii_map[UCHAR_MAX] = { 0 };
    size_t i, j;

    /* map of characters in t */
    for (i=0; i<strlen(t); i++) {
        ascii_map[(int) t[i]] = 1;
    }

    /* find first occurence of a character in t */
    for (j=0; j<strlen(s); j++) {
        if (ascii_map[(int) s[j]]) {
            return j;
        }
    }

    return NOT_FOUND;
}

