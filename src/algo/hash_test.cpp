/**
 * @file    hash_test.cpp
 * @ingroup algo
 * @brief   Simple Hash functions.
 *
 * Copyright (c) 2013-2021 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "algo/hash.h"

#include <limits>

#include "gtest/gtest.h"
#include "base/random.h"
#include "base/utils.h"


// Test that hashsum of strings does change for any bit change
TEST(Hash, sdbm) {
    EXPECT_NE(Hash::sdbm("abcd"), Hash::sdbm("abce"));

    #define NB_CHAR 10
    char str1[NB_CHAR+1];
    char str2[NB_CHAR+1];
    // Get 1000 random strings
    for (int i = 0; i < 1000; ++i) {
        Random::GenString(str1, NB_CHAR);
        const unsigned int hash1 = Hash::sdbm(str1);

        // Change only one bit of the string
        for (int j = 0; j < NB_CHAR*7; ++j) {
            snprintf(str2, NB_CHAR, "%s", str1);
            str2[j/7] ^= static_cast<char>(0x01 << (j%7));

            // Hashsum should never be equal when only one bit of the string change
            const unsigned int hash2 = Hash::sdbm(str2);
            EXPECT_NE(hash1, hash2);
        }
    }
}


// Test that hashsum of strings does change for any bit change
TEST(Hash, djb2) {
    EXPECT_NE(Hash::djb2("abcd"), Hash::djb2("abce"));

    #define NB_CHAR 10
    char str1[NB_CHAR+1];
    char str2[NB_CHAR+1];
    // Get 1000 random strings
    for (int i = 0; i < 1000; ++i) {
        Random::GenString(str1, NB_CHAR);
        const unsigned int hash1 = Hash::djb2(str1);

        // Change only one bit of the string
        for (int j = 0; j < NB_CHAR*7; ++j) {
            snprintf(str2, NB_CHAR, "%s", str1);
            str2[j/7] ^= static_cast<char>(0x01 << (j%7));

            // Hashsum should never be equal when only one bit of the string change
            const unsigned int hash2 = Hash::djb2(str2);
            EXPECT_NE(hash1, hash2);
        }
    }
}


// Test that hashsum of strings does change for any bit change
TEST(Hash, fnv1a32) {
    EXPECT_NE(Hash::fnv1a32("abcd"), Hash::fnv1a32("abce"));

    #define NB_CHAR 10
    char str1[NB_CHAR+1];
    char str2[NB_CHAR+1];
    // Get 1000 random strings
    for (unsigned int i = 0; i < 1000; ++i) {
        Random::GenString(str1, NB_CHAR);
        const unsigned int hash1 = Hash::fnv1a32(str1);

        // Change only one bit of the string
        for (unsigned int j = 0; j < NB_CHAR*7; ++j) {
            snprintf(str2, NB_CHAR, "%s", str1);
            str2[j/7] ^= static_cast<char>(0x01 << (j%7));

            // Hashsum should never be equal when only one bit of the string change
            const unsigned int hash2 = Hash::fnv1a32(str2);
            EXPECT_NE(hash1, hash2);
        }
    }
}

// Test against reference implementation for a few text values (empty string, "test" string", etc)
TEST(Hash, fnv1a32_reference) {
    EXPECT_EQ(Hash::fnv1a32(""), 0x811c9dc5);
	EXPECT_EQ(Hash::fnv1a32("a"), 0xe40c292c);
	EXPECT_EQ(Hash::fnv1a32("test"), 0xafd071e5);

    // failure
	EXPECT_NE(Hash::fnv1a32("nope"), 0xafd071e5);
}