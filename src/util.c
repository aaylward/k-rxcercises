#include <string.h>
#include "chapter2.h"

void initializeAsciiArray(char ascii[] /* size should always be MAX_ASCII */) {
    for (int i=0; i<MAX_ASCII; i++) {
        ascii[i] = 0;
    }
}
