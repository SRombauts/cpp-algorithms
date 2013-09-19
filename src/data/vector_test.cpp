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
  Vector vec1;
  EXPECT_EQ(0, vec1.GetCapacity());
  EXPECT_EQ(0, vec1.GetSize());
}

// Test Vector reserving.
TEST(Vector, Reserve) {
  // Reserving in a vector of size 0
  Vector vec1;
  vec1.Reserve(0);
  EXPECT_EQ(0, vec1.GetCapacity());
  EXPECT_EQ(0, vec1.GetSize());

  // TODO(SRO): test differents capacities, not all rounded => "for" loop!
  for (size_t reserve = 1; reserve < 1025; ++reserve) {
     vec1.Reserve(reserve);
     EXPECT_GE(vec1.GetCapacity(), reserve);
     EXPECT_EQ(0, vec1.GetSize());
  }
  EXPECT_GE(vec1.GetCapacity(), 1024);
  // Reserving a second time does nothing
  for (size_t reserve = 1; reserve < 1025; ++reserve) {
     vec1.Reserve(reserve);
     EXPECT_GE(vec1.GetCapacity(), 1024);
  }

  // Reserving in a vector of size not 0
  Vector vec2;
  vec2.Append(987);
  vec2.Append(456);
  vec2.Append(321);
  EXPECT_GE(vec2.GetCapacity(), (size_t)3);
  EXPECT_EQ(3, vec2.GetSize());
  for (size_t reserve = 1; reserve < 1025; ++reserve) {
     vec2.Reserve(reserve);
     EXPECT_GE(vec2.GetCapacity(), reserve);
     EXPECT_EQ(3, vec2.GetSize());
  }
  EXPECT_GE(vec1.GetCapacity(), 1024);
}

// Test Vector appending.
TEST(Vector, Append) {
  Vector vec1;
  vec1.Append(987);
  // TODO(SRO):
  EXPECT_GE(vec1.GetCapacity(), (size_t)1);
  EXPECT_EQ(1, vec1.GetSize());
  vec1.Append(654);
  EXPECT_GE(vec1.GetCapacity(), (size_t)2);
  EXPECT_EQ(2, vec1.GetSize());
  vec1.Append(321);
  EXPECT_GE(vec1.GetCapacity(), (size_t)3);
  EXPECT_EQ(3, vec1.GetSize());
}

// Test Vector truncating.
TEST(Vector, Truncate) {
  Vector vec1;
  vec1.Append(987);
  vec1.Append(654);
  vec1.Append(321);
  const size_t capacity = vec1.GetCapacity();
  EXPECT_EQ(3, vec1.GetSize());
  EXPECT_EQ(capacity, vec1.GetCapacity());
  vec1.Truncate(8);
  EXPECT_EQ(3, vec1.GetSize());
  EXPECT_EQ(capacity, vec1.GetCapacity());
  vec1.Truncate(3);
  EXPECT_EQ(3, vec1.GetSize());
  EXPECT_EQ(capacity, vec1.GetCapacity());
  vec1.Truncate(2);
  EXPECT_EQ(2, vec1.GetSize());
  EXPECT_EQ(capacity, vec1.GetCapacity());
  vec1.Truncate(1);
  EXPECT_EQ(1, vec1.GetSize());
  EXPECT_EQ(capacity, vec1.GetCapacity());
  vec1.Truncate(0);
  EXPECT_EQ(0, vec1.GetSize());
  EXPECT_EQ(capacity, vec1.GetCapacity());
}
