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
#include "random.h"

#include "gtest/gtest.h"

#include <limits>

// Test that hashum of strings does change for any bit change
TEST(Hash,sdbm)
{
    EXPECT_NE(Hash::sdbm("abcd"), Hash::sdbm("abce"));

    #define NB_CHAR 10
    char str1[NB_CHAR+1];
    char str2[NB_CHAR+1];
    // Get 1000 random strings
    for (unsigned int i = 0; i < 1000; i++) {
        Random::GenString(str1, NB_CHAR);
        const unsigned long hash1 = Hash::sdbm(str1);
        
        // Change only one bit of the string
        for (unsigned int j = 0; j < NB_CHAR*7; j++) {
            strcpy(str2, str1);
            str2[j/7] ^= (char)(0x01<<(j%7));
            
            // Hashsum should never be equal when only one bit of the string is changed
            const unsigned long hash2 = Hash::sdbm(str2);
            EXPECT_NE (hash1, hash2);
        }
    }
}


// Test that hashum of strings does change for any bit change
TEST(Hash,djb2)
{
    EXPECT_NE(Hash::djb2("abcd"), Hash::djb2("abce"));

    #define NB_CHAR 10
    char str1[NB_CHAR+1];
    char str2[NB_CHAR+1];
    // Get 1000 random strings
    for (unsigned int i = 0; i < 1000; i++) {
        Random::GenString(str1, NB_CHAR);
        const unsigned long hash1 = Hash::djb2(str1);
        
        // Change only one bit of the string
        for (unsigned int j = 0; j < NB_CHAR*7; j++) {
            strcpy(str2, str1);
            str2[j/7] ^= (char)(0x01<<(j%7));
            
            // Hashsum should never be equal when only one bit of the string is changed
            const unsigned long hash2 = Hash::djb2(str2);
            EXPECT_NE (hash1, hash2);
        }
    }
}
