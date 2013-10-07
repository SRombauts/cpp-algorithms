/**
 * @file    hash.h
 * @ingroup algo
 * @brief   Simple Hash functions.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once

/**
 * @brief Simple Hash functions.
 */
class Hash {
 public:
  /**
   * @brief Famous hash function used by the sdbm public-domain database library.
   */
  static unsigned int sdbm(const char* str);

  /**
   * @brief Famous hash function by Daniel J. Bernstein.
   */
  static unsigned int djb2(const char* str);
};

