#include <gtest/gtest.h>
#include "HashMap.h"

TEST(HashMapLoadFactorTest, EmptyMap)
{
    HashMap<int, int> map;

    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}

TEST(HashMapLoadFactorTest, OneElement)
{
    HashMap<int, int> map;

    map.insert(1, 10);

    EXPECT_FLOAT_EQ(map.loadFactor(), 1.0f / 16.0f);
}

TEST(HashMapLoadFactorTest, MultipleElements)
{
    HashMap<int, int> map(10);

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    EXPECT_FLOAT_EQ(map.loadFactor(), 0.3f);
}

TEST(HashMapLoadFactorTest, DuplicateKeyDoesNotChangeLoadFactor)
{
    HashMap<int, int> map(10);

    map.insert(1, 10);
    map.insert(1, 20);

    EXPECT_FLOAT_EQ(map.loadFactor(), 0.1f);
}

TEST(HashMapLoadFactorTest, LoadFactorAfterRemove)
{
    HashMap<int, int> map(10);

    map.insert(1, 10);
    map.insert(2, 20);

    map.remove(1);

    EXPECT_FLOAT_EQ(map.loadFactor(), 0.1f);
}

TEST(HashMapLoadFactorTest, LoadFactorAfterClear)
{
    HashMap<int, int> map(10);

    for(int i = 0; i < 5; i++)
        map.insert(i, i);

    map.clear();

    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}