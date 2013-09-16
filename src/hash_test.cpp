/**
 * @file    hash_test.cpp
 * @ingroup CppAlgorithms
 * @brief   Simple Hash functions.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "hash.h"
#include "gtest/gtest.h"

#include <limits>

TEST(Hash,sdbm)
{
    EXPECT_NE(Hash::sdbm("abcd"), Hash::sdbm("abce"));
}
