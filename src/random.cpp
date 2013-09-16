/**
 * @file    random.cpp
 * @ingroup CppAlgorithms
 * @brief   Random utility functions.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "random.h"

#include <cstdlib>  // rand()


// Generate a printable alphanumeric character.
char Random::GenChar() {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    return alphanum[rand() % (sizeof(alphanum) - 1)];
}

// Generate a printable alphanumeric string.
void Random::GenString(char* str, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        str[i] = Random::GenChar();
    }

    str[len] = '\0';
}
