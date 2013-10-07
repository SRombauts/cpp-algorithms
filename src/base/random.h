/**
 * @file    random.h
 * @ingroup base
 * @brief   Random utility functions.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once

#include <cstddef>  // size_t

/**
 * @brief Random utility functions.
 */
class Random {
 public:
  /**
   * @brief Generate a printable alphanumeric character.
   */
  static char GenChar();

  /**
   * @brief Generate a printable alphanumeric string.
   */
  static void GenString(char* str, size_t len);
};

