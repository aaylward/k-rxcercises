#ifndef CHAPTER_2_EXCERCISES
#define CHAPTER_2_EXCERCISES

#include <string.h>
#include <limits.h>

#define NOT_FOUND -1

/*
 *  HashMap on the cheap ;)
 *  hash(x) = x
 */
void initializeAsciiArray(char ascii[]);

/* Excercise 2.5 */
int any(char s[], char t[]);

unsigned getbits(unsigned x, int n, int p);

/* Excercise 2.6 */
unsigned setbits(unsigned x, int p, int n, unsigned y);

/* Excercise 2.7 */
unsigned invert(unsigned x, int p, int n);

#endif
