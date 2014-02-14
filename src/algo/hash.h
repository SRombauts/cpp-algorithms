/**
 * @file    hash.h
 * @ingroup algo
 * @brief   Simple Hash functions.
 *
 * Copyright (c) 2013-2014 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once

/**
 * @brief Simple Hash functions.
 *
 * @todo quicker integer variants (with no loop)
 * @todo std::string variants
 */
class Hash {
public:
    /**
     * @brief Famous fast 32 bits hash function used by the sdbm public-domain database library.
     *
     * @see http://stackoverflow.com/a/14409947/1163698
     */
    static unsigned long sdbm(const char* apStr);

    /**
     * @brief Famous very fast 32 bits hash function by Daniel J. Bernstein.
     *
     * @see http://stackoverflow.com/a/14409947/1163698
     */
    static unsigned long djb2(const char* apStr);

    /**
     * @brief Famous 32 bits FNV-1a hash function by Glenn Fowler, Landon Curt Noll, and Phong Vo.
     *
     * @see http://www.isthe.com/chongo/tech/comp/fnv/index.html#FNV-1a
     */
    static unsigned long fnv1a32(const char* apStr);

    /**
     * @brief Famous 64 bits FNV-1a hash function by Glenn Fowler, Landon Curt Noll, and Phong Vo.
     *
     * @see http://www.isthe.com/chongo/tech/comp/fnv/index.html#FNV-1a
     */
    static unsigned long long fnv1a64(const char* apStr);
};

