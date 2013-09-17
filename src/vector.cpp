/**
 * @file    vector.cpp
 * @ingroup CppAlgorithms
 * @brief   Implementation of dynamic array (a "vector").
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "vector.h"


// Public default constructor
Vector::Vector() : array_(NULL) {
}

// Public destructor (not virtual)
Vector::~Vector() {
   if (array_ != NULL) {
      delete [] array_;
   }
}
