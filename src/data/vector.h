/**
 * @file    vector.h
 * @ingroup data
 * @brief   Implementation of dynamic array (a "vector") of int (not a template).
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef SRC_DATA_VECTOR_H_
#define SRC_DATA_VECTOR_H_

#include "base/utils.h"

/**
 * @brief Implementation of dynamic array (a "vector") of int (not a template).
 */
class Vector {
 public:
  Vector();
  ~Vector();  // no need for virtual dtor

  void Reserve(const size_t new_capacity);

  void Append(const int value);

  void Truncate(const size_t size);

  const int& At(const size_t idx) const;
        int& At(const size_t idx);

  // TODO(SRombauts): Find() + comments and complexity annotations

  inline size_t GetCapacity() {
    return capacity_;
  }
  inline size_t GetSize() {
    return size_;
  }

 private:
  int*    array_;     // Pointer to the underlying C-style heap-allocated array
  size_t  capacity_;  // Capacity of the underlying array
  size_t  size_;      // Size of the used part of the array

  DISALLOW_COPY_AND_ASSIGN(Vector);
};

#endif  // SRC_DATA_VECTOR_H_

