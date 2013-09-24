/**
 * @file    vector_test.cpp
 * @ingroup data
 * @brief   Implementation of dynamic array (a "vector").
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "data/vector.h"

#include <limits>

#include "algo/random.h"
#include "gtest/gtest.h"


// Test Vector constructors.
TEST(Vector, ctor) {
  Vector<int> vec1;
  EXPECT_EQ(0, vec1.GetCapacity());
  EXPECT_EQ(0, vec1.GetSize());
}

// Test Vector reserving.
TEST(Vector, Reserve) {
  // Reserving in a vector of size 0
  Vector<int>  vec1;
  vec1.Reserve(0);
  EXPECT_EQ(0, vec1.GetCapacity());
  EXPECT_EQ(0, vec1.GetSize());

  // Test differents capacities, not all rounded
  for (size_t reserve = 1; reserve < 1025; ++reserve) {
     vec1.Reserve(reserve);
     EXPECT_GE(vec1.GetCapacity(), reserve);
     EXPECT_EQ(0, vec1.GetSize());
  }
  // Reserving a second time does nothing
  for (size_t reserve = 1; reserve < 1025; ++reserve) {
     vec1.Reserve(reserve);
     EXPECT_GE(vec1.GetCapacity(), (size_t)1024);
  }
}

// Test Vector appending and truncating.
TEST(Vector, AppendTruncate) {
  Vector<int>  vec1;
  // Append
  for (size_t idx = 0; idx < 1024; ++idx) {
    int     value = idx;
    size_t  size  = idx+1;
    vec1.Append(value);
    EXPECT_EQ(size, vec1.GetSize());
    EXPECT_EQ(value, vec1.At(idx));
    EXPECT_GE(vec1.GetCapacity(), size);
  }
  const size_t final_capacity = vec1.GetCapacity();
  // Recheck all values
  for (size_t idx = 0; idx < 1024; ++idx) {
    int value = idx;
    EXPECT_EQ(value, vec1.At(idx));
  }
  // Truncate
  for (size_t size = 1023; size > 0; --size) {
    vec1.Truncate(size);
    EXPECT_EQ(size, vec1.GetSize());
    EXPECT_EQ(final_capacity, vec1.GetCapacity());
  }
  vec1.Truncate(0);
  EXPECT_EQ(0, vec1.GetSize());
  EXPECT_EQ(final_capacity, vec1.GetCapacity());
  // Re-Append
  for (size_t idx = 0; idx < 1024; ++idx) {
    int     value = idx;
    size_t  size  = idx+1;
    vec1.Append(value);
    EXPECT_EQ(size, vec1.GetSize());
    EXPECT_EQ(value, vec1.At(idx));
    EXPECT_EQ(final_capacity, vec1.GetCapacity());
  }
  // Recheck all values
  for (size_t idx = 0; idx < 1024; ++idx) {
    int value = idx;
    EXPECT_EQ(value, vec1.At(idx));
  }
}
