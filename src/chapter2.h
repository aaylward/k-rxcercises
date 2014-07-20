#ifndef CHAPTER_2_EXCERCISES
#define CHAPTER_2_EXCERCISES

#define MAX_ASCII 255
#define NOT_FOUND -1

/*
 *  HashMap on the cheap ;)
 *  hash function f:Z/Z_(ascii_range)->Z/Z_(ascii_range)
 *  f(x) = x
 */
void initializeAsciiArray(char ascii[]);

int any(char s[], char t[]);

#endif
