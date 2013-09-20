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

#include <cstring>
#include <stdexcept>

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
    const int* old_array = array_;
    // allocate a new array
    array_    = new int[capacity]; // can throw std::bad_alloc
    capacity_ = capacity;
    // copy old datas, then destroy the old array
    std::memcpy(array_, old_array, size_*sizeof(array_[0]));
    delete [] old_array;
  }
}

void Vector::Append(const int value) {
  if (size_ == capacity_) {
    // reserve more space if needed: 0,10,23,39,60,88,124,171,232,311,414,548...
    size_t new_capacity = static_cast<size_t>(capacity_ * 1.3 + 10);
    Reserve(new_capacity);
  }
  // append value
  array_[size_] = value;
  size_ += 1;
}

void Vector::Truncate(const size_t size) {
  if (size < size_) {
    // simply resize
    size_ = size;
  }
}

const int& Vector::At(const size_t idx) const {
  // basic boundary check
  if (idx >= size_) {
    throw std::out_of_range("Vector::At: idx >= size_");
  }
  return array_[idx];
}

int& Vector::At(const size_t idx) {
  // basic boundary check
  if (idx >= size_) {
    throw std::out_of_range("Vector::At: idx >= size_");
  }
  return array_[idx];
}

