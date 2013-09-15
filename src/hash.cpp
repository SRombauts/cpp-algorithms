#include "hash.h"

// Simple and famous hash used by the sdbm public-domain database library.
unsigned long Hash::sdbm(const char* str) {
    unsigned long hash = 0;
    int c;

    while (c = *str++) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}

