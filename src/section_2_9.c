#include "chapter2.h"

/*
 *  Excercises from K&R C, section 2.9
 *  @bugs aaylward@gmail.com <Andy Aylward>
 */

/*
 *  getbits(x, p, n) returns the right adjusted n-bit field of x that begins at
 *  position p. implementation by K&R
 */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

/*
 *  Excercise 2-6:
 *  Write a function `setbits(unsigned x, int p, int n, unsigned y)` that returns x with the
 *  n bits that begin at position p set to the rightmost bits of y, leaving the
 *  others unchanged.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned stuff_to_keep, stuff_to_write;
    stuff_to_keep = x >> (p+1-n);
    stuff_to_write = y >> n;
    return x;
}

