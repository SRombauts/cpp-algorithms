#include "hash.h"
#include "gtest/gtest.h"

#include <limits>

TEST(Hash,sdbm)
{
    EXPECT_NE(Hash::sdbm("abcd"), Hash::sdbm("abce"));
}
