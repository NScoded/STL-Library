#include <gtest/gtest.h>
#include "HashMap.h"

TEST(HashMapRehashTest, CapacityDoublesAfterThreshold)
{
    HashMap<int, int> map(4);

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);
    map.insert(4, 40);

    EXPECT_EQ(map.capacity(), 8);
}

TEST(HashMapRehashTest, AllElementsRemainAfterRehash)
{
    HashMap<int, int> map(4);

    for(int i = 0; i < 20; i++)
        map.insert(i, i * 100);

    EXPECT_EQ(map.size(), 20);

    for(int i = 0; i < 20; i++)
        EXPECT_TRUE(map.exists(i));

    for(int i = 0; i < 20; i++)
        EXPECT_EQ(map.get(i), i * 100);
}

TEST(HashMapRehashTest, LoadFactorAfterRehash)
{
    HashMap<int, int> map(4);

    for(int i = 0; i < 4; i++)
        map.insert(i, i);

    EXPECT_LT(map.loadFactor(), 0.75f);
}

TEST(HashMapRehashTest, DuplicateKeyDoesNotTriggerExtraRehash)
{
    HashMap<int, int> map(4);

    map.insert(1, 10);
    map.insert(1, 20);
    map.insert(1, 30);

    EXPECT_EQ(map.capacity(), 4);
    EXPECT_EQ(map.size(), 1);
}

TEST(HashMapRehashTest, MultipleRehashes)
{
    HashMap<int, int> map(2);

    for(int i = 0; i < 100; i++)
        map.insert(i, i);

    EXPECT_EQ(map.size(), 100);

    for(int i = 0; i < 100; i++)
        EXPECT_EQ(map.get(i), i);

    EXPECT_GE(map.capacity(), 128);
}