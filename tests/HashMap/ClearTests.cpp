#include <gtest/gtest.h>
#include "HashMap.h"

TEST(HashMapClearTest, ClearEmptyMap)
{
    HashMap<int, int> map;

    map.clear();

    EXPECT_EQ(map.size(), 0);
    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}

TEST(HashMapClearTest, ClearAfterSingleInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);

    map.clear();

    EXPECT_EQ(map.size(), 0);
    EXPECT_FALSE(map.exists(1));
    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}

TEST(HashMapClearTest, ClearAfterMultipleInserts)
{
    HashMap<int, int> map;

    for(int i = 0; i < 20; i++)
        map.insert(i, i * 10);

    map.clear();

    EXPECT_EQ(map.size(), 0);
    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);

    for(int i = 0; i < 20; i++)
        EXPECT_FALSE(map.exists(i));
}

TEST(HashMapClearTest, InsertAfterClear)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    map.clear();

    map.insert(3, 30);

    EXPECT_EQ(map.size(), 1);
    EXPECT_TRUE(map.exists(3));
    EXPECT_EQ(map.get(3), 30);
}

TEST(HashMapClearTest, CapacityRemainsSameAfterClear)
{
    HashMap<int, int> map(16);

    for(int i = 0; i < 20; i++)
        map.insert(i, i);

    int cap = map.capacity();

    map.clear();

    EXPECT_EQ(map.capacity(), cap);
}