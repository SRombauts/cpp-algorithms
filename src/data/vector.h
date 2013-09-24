/**
 * @file    vector.h
 * @ingroup data
 * @brief   Implementation of dynamic array (a "vector") of type T
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef SRC_DATA_VECTOR_H_
#define SRC_DATA_VECTOR_H_

#include <cstring>        // memcpy
#include <stdexcept>      // out_of_range

#include "base/utils.h"   // DISALLOW_COPY_AND_ASSIGN

/**
 * @brief Implementation of dynamic array (a "vector") of type T
 *
 * @todo(SRombauts) Iterator
 */
template<class T>
class Vector {
 public:
  /// @brief Alias for the managed type
  typedef T element_type;

  /// @brief Public default constructor
  Vector()
    : array_(nullptr), capacity_(0), size_(0) {
  }

  /// @brief Destructor: no need for virtual dtor
  ~Vector() {
    if (array_ != nullptr) {
      delete [] array_;
    }
  }

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
  void Reserve(const size_t capacity) {
    if (capacity_ < capacity) {
      const T* old_array = array_;
      // allocate a new array
      array_    = new T[capacity];  // can throw std::bad_alloc
      capacity_ = capacity;
      // copy old data, then destroy the old array
      std::memcpy(array_, old_array, size_*sizeof(array_[0]));
      delete [] old_array;
    }
  }

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
  void Append(const T& value) {
    if (size_ == capacity_) {
      // reserve more space if needed: 0,10,23,39,60,88,124,171,232,311,414...
      size_t new_capacity = static_cast<size_t>(capacity_ * 1.3 + 10);
      Reserve(new_capacity);
    }
    // append value
    array_[size_] = value;
    size_ += 1;
  }

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
  void Truncate(const size_t size) {
    if (size < size_) {
      // simply resize
      size_ = size;
    }
  }

  /**
   * @brief Access element at given index.
   *
   * Complexity is constant, O(1).
   *
   * throw std::out_of_range() if idx >= size_
   *
   * @param[in] idx Index (0-based) of the element to access.
   */
  const T& At(const size_t idx) const {
    // basic boundary check
    if (idx >= size_) {
      throw std::out_of_range("Vector::At: idx >= size_");
    }
    return array_[idx];
  }
  T& At(const size_t idx) {
    // basic boundary check
    if (idx >= size_) {
      throw std::out_of_range("Vector::At: idx >= size_");
    }
    return array_[idx];
  }

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
  T*      array_;     ///< Pointer to the underlying raw heap-allocated array
  size_t  capacity_;  ///< Capacity of the underlying array
  size_t  size_;      ///< Size of the used part of the array

  // Forbid
  DISALLOW_COPY_AND_ASSIGN(Vector);
};

#endif  // SRC_DATA_VECTOR_H_

