#include <string.h>
#include <limits.h>
#include "chapter2.h"

void initializeAsciiArray(char ascii[] /* size should always be MAX_ASCII */) {
    for (int i=0; i<UCHAR_MAX; i++) {
        ascii[i] = 0;
    }
}
