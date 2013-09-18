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
  Vector vec1;
  vec1.Reserve(0);
  EXPECT_EQ(0, vec1.GetCapacity());
  EXPECT_EQ(0, vec1.GetSize());
  vec1.Reserve(100);
  // TODO:
  //EXPECT_GE((size_t)100, vec1.GetCapacity());
  EXPECT_EQ(0, vec1.GetSize());
  vec1.Reserve(200);
  //EXPECT_GE((size_t)200, vec1.GetCapacity());
  EXPECT_EQ(0, vec1.GetSize());
}

// Test Vector appending.
TEST(Vector, Append) {
  Vector vec1;
  vec1.Append(987);
  // TODO:
  //EXPECT_GE((size_t)1, vec1.GetCapacity());
  //EXPECT_EQ(1, vec1.GetSize());
  vec1.Append(654);
  //EXPECT_GE((size_t)2, vec1.GetCapacity());
  //EXPECT_EQ(2, vec1.GetSize());
  vec1.Append(321);
  //EXPECT_GE((size_t)3, vec1.GetCapacity());
  //EXPECT_EQ(3, vec1.GetSize());
}

// Test Vector truncating.
TEST(Vector, Truncate) {
  Vector vec1;
  vec1.Append(987);
  vec1.Append(654);
  vec1.Append(321);
  //EXPECT_EQ(3, vec1.GetSize());
  vec1.Truncate(8);
  //EXPECT_EQ(3, vec1.GetSize());
  vec1.Truncate(3);
  //EXPECT_EQ(3, vec1.GetSize());
  vec1.Truncate(2);
  //EXPECT_EQ(2, vec1.GetSize());
  vec1.Truncate(1);
  //EXPECT_EQ(1, vec1.GetSize());
  vec1.Truncate(0);
  //EXPECT_EQ(0, vec1.GetSize());
}
