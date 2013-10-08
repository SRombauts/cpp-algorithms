/**
 * @file    hash.cpp
 * @ingroup algo
 * @brief   Simple Hash functions.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "algo/hash.h"

// Famous hash function used by the sdbm public-domain database library.
unsigned int Hash::sdbm(const char* str) {
  unsigned int hash = 0;

  for (unsigned int idx = 0; str[idx] != 0; ++idx) {
    // hash = hash * 65599 + char
    hash = (hash << 6) + (hash << 16) - hash + str[idx];
  }

  return hash;
}

// Famous very simple hash function by Daniel J. Bernstein.
unsigned int Hash::djb2(const char* str) {
  unsigned int hash = 5381;

  for (unsigned int idx = 0; str[idx] != 0; ++idx) {
    // hash = hash * 33 + c
    hash = ((hash << 5) + hash) + str[idx];
  }

  return hash;
}
