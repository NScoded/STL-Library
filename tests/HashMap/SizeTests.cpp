#include <gtest/gtest.h>
#include "HashMap.h"

TEST(HashMapSizeTest, EmptyMapSizeIsZero)
{
    HashMap<int, int> map;

    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapSizeTest, SizeAfterSingleInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);

    EXPECT_EQ(map.size(), 1);
}

TEST(HashMapSizeTest, SizeAfterMultipleInserts)
{
    HashMap<int, int> map;

    for(int i = 0; i < 10; i++)
        map.insert(i, i);

    EXPECT_EQ(map.size(), 10);
}

TEST(HashMapSizeTest, DuplicateKeyDoesNotIncreaseSize)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(1, 20);

    EXPECT_EQ(map.size(), 1);
}

TEST(HashMapSizeTest, SizeAfterRemove)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    map.remove(1);

    EXPECT_EQ(map.size(), 1);
}

TEST(HashMapSizeTest, SizeAfterClear)
{
    HashMap<int, int> map;

    for(int i = 0; i < 20; i++)
        map.insert(i, i);

    map.clear();

    EXPECT_EQ(map.size(), 0);
}