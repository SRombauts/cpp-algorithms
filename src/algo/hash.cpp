/**
 * @file    hash.cpp
 * @ingroup algo
 * @brief   Simple Hash functions.
 *
 * Copyright (c) 2013-2021 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "algo/hash.h"

// Famous 32 bits fast hash function used by the sdbm public-domain database library.
uint32_t Hash::sdbm(const char* apStr) {
    uint32_t hash = 0;

    for (uint32_t idx = 0; apStr[idx] != 0; ++idx) {
        // hash = hash * 65599 + char
        hash = (hash << 6) + (hash << 16) - hash + static_cast<unsigned char>(apStr[idx]);
    }

    return hash;
}

// Famous very fast 32 bits hash function by Daniel J. Bernstein. (warning, see header)
uint32_t Hash::djb2(const char* apStr) {
    uint32_t hash = 5381;

    for (uint32_t idx = 0; apStr[idx] != 0; ++idx) {
        // hash = hash * 33 + c
        hash = ((hash << 5) + hash) + static_cast<unsigned char>(apStr[idx]);
    }

    return hash;
}

// Famous 32 bits FNV-1a hash function by Glenn Fowler, Landon Curt Noll, and Phong Vo.
uint32_t Hash::fnv1a32(const char* apStr) {
    uint32_t hash = 2166136261U; // 32 bit offset_basis = 2166136261U

    for (uint32_t idx = 0; apStr[idx] != 0; ++idx) {
        // 32 bit FNV_prime = 224 + 28 + 0x93 = 16777619
        hash = 16777619U * (hash ^ static_cast<unsigned char>(apStr[idx]));
    }

    return hash;
}

// Famous 64 bits FNV-1a hash function by Glenn Fowler, Landon Curt Noll, and Phong Vo.
uint64_t Hash::fnv1a64(const char* apStr) {
    uint64_t hash = 14695981039346656037ULL; // 64 bit offset_basis = 14695981039346656037

    for (uint32_t idx = 0; apStr[idx] != 0; ++idx) {
        // 64 bit FNV_prime = 240 + 28 + 0xb3 = 1099511628211
        hash = 1099511628211ULL * (hash ^ static_cast<unsigned char>(apStr[idx]));
    }

    return hash;
}
