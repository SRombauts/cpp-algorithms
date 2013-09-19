/**
 * @file    vector.cpp
 * @ingroup data
 * @brief   Implementation of dynamic array (a "vector").
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "data/vector.h"

// Public default constructor
Vector::Vector()
    : array_(nullptr), capacity_(0), size_(0) {
}

// Public destructor (not virtual)
Vector::~Vector() {
  if (array_ != nullptr) {
    delete [] array_;
  }
}

void Vector::Reserve(const size_t capacity) {
  if (capacity_ < capacity) {
    // TODO(SRO): reserve
    capacity_ = capacity;
  }
}

void Vector::Append(const int value) {
  size_t next_size = size_ + 1;
  // reserve if needed
  Reserve(next_size);
  // TODO(SRO): append !
  size_ = next_size;
}

void Vector::Truncate(const size_t size) {
  if (size < size_) {
    // TODO(SRO): resize
    size_ = size;
  }
}

const int& Vector::At(const size_t idx) const {
  // TODO(SRO): check bounds
  return array_[idx];
}

int& Vector::At(const size_t idx) {
  // TODO(SRO): check bounds
  return array_[idx];
}

