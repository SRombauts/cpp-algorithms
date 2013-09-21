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
 *
 * @todo(SRombauts) comments and complexity annotations
 * @todo(SRombauts) Template
 * @todo(SRombauts) Iterator
 */
class Vector {
 public:
  /// @brief Constructor
  Vector();
  /// @brief Destructor: no need for virtual dtor
  ~Vector();

  /**
   * @brief Increase the capacity of the array.
   *
   * Allocate an array of greater size, and copy the content of the former one.
   * Does nothing if new capacity is not greater than former capacity.
   *
   * Complexity is linear, O(size) (but not O(capacity)).
   *
   * @param[in] capacity  Capacity required for the new array.
   */
  void Reserve(const size_t capacity);

  /**
   * @brief Append a value at the end of the array.
   *
   * Copy the provided value at the back of the array, increasing its size.
   * If capacity is not enough, #Reserve a greater array before doing so.
   *
   * Complexity is constant, O(1) if no reallocation occurs (see #Reserve).
   *
   * @param[in] value Value tu copy at the back of the array.
   */
  void Append(const int value);

  /**
   * @brief Truncate the array by reducing its size.
   *
   * There is no reduction of capacity (no reallocation).
   * Does nothing if size is not lesser than former size.
   *
   * Complexity is constant, O(1).
   *
   * @param[in] size  New (smaller) size of the array.
   */
  void Truncate(const size_t size);

  /**
   * @brief Access element at given index.
   *
   * Complexity is constant, O(1).
   *
   * throw std::out_of_range() if idx >= size_
   *
   * @param[in] idx Index (0-based) of the element to access.
   */
  const int& At(const size_t idx) const;
        int& At(const size_t idx);

  /**
   * @brief Returns the capacity (size of the underlying array).
   */
  inline size_t GetCapacity() {
    return capacity_;
  }
  /**
   * @brief Returns the current size (number of data in the array).
   */
  inline size_t GetSize() {
    return size_;
  }

 private:
  int*    array_;     ///< Pointer to the underlying raw heap-allocated array
  size_t  capacity_;  ///< Capacity of the underlying array
  size_t  size_;      ///< Size of the used part of the array

  DISALLOW_COPY_AND_ASSIGN(Vector);
};

#endif  // SRC_DATA_VECTOR_H_

