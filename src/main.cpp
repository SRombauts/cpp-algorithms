/**
 * @file    main.cpp
 * @ingroup CppAlgorithms
 * @brief   Experimenting with well known algorithms and data structures.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <cstdio>

#include "algo/hash.h"

/**
 * @brief For experimenting
 *
 * @todo(SRombauts) Evaluate different initial value for Hash::sdbm() (see Hash::djb2)
*/
int main() {
    printf("Hash::sdbm('test')=%x\n", Hash::sdbm("test"));

    return 0;
}
