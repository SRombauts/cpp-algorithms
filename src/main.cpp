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

#include "hash.h"
#include "random.h"

#include <iostream>
#include <iomanip>  // std::setw


int main() {
    std::cout << "Hash::sdbm('test')=" << std::hex << std::setw(8) << std::setfill('0') << Hash::sdbm("test") << std::endl;

    return 0;
}