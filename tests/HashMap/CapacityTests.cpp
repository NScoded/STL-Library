#include <gtest/gtest.h>
#include "HashMap.h"

TEST(HashMapCapacityTest, DefaultCapacity)
{
    HashMap<int, int> map;

    EXPECT_EQ(map.capacity(), 16);
}

TEST(HashMapCapacityTest, CustomCapacity)
{
    HashMap<int, int> map(32);

    EXPECT_EQ(map.capacity(), 32);
}

TEST(HashMapCapacityTest, CapacityAfterInsertWithoutRehash)
{
    HashMap<int, int> map(16);

    for(int i = 0; i < 5; i++)
        map.insert(i, i);

    EXPECT_EQ(map.capacity(), 16);
}

TEST(HashMapCapacityTest, CapacityAfterRehash)
{
    HashMap<int, int> map(4);

    for(int i = 0; i < 4; i++)
        map.insert(i, i);

    EXPECT_EQ(map.capacity(), 8);
}