/**
 * @file    random.cpp
 * @ingroup base
 * @brief   Random utility functions.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "base/random.h"

#include <cstdlib>  // rand_r()

// Generate a printable alphanumeric character.
char Random::GenChar() {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    return alphanum[std::rand() % (sizeof(alphanum) - 1)]; // NOLINT
}

// Generate a printable alphanumeric string.
void Random::GenString(char* str, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        str[i] = Random::GenChar();
    }

    str[len] = '\0';
}
