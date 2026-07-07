#include <gtest/gtest.h>
#include "HashMap.h"


// Capacity Doubles After Threshold

TEST(HashMapRehashTest, CapacityDoublesAfterThreshold)
{
    HashMap<int, int> map(4);

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);
    map.insert(4, 40);

    EXPECT_EQ(map.capacity(), 8);
}


// All Elements Remain After Rehash

TEST(HashMapRehashTest, AllElementsRemainAfterRehash)
{
    HashMap<int, int> map(4);

    for(int i = 0; i < 20; i++)
        map.insert(i, i * 100);

    EXPECT_EQ(map.size(), 20);

    for(int i = 0; i < 20; i++)
    {
        EXPECT_TRUE(map.exists(i));
        EXPECT_EQ(map.get(i), i * 100);
    }
}


// Load Factor After Rehash

TEST(HashMapRehashTest, LoadFactorAfterRehash)
{
    HashMap<int, int> map(4);

    for(int i = 0; i < 4; i++)
        map.insert(i, i);

    EXPECT_LT(map.loadFactor(), 0.75f);
}


// Duplicate Key Does Not Trigger Rehash

TEST(HashMapRehashTest, DuplicateKeyDoesNotTriggerExtraRehash)
{
    HashMap<int, int> map(4);

    map.insert(1, 10);
    map.insert(1, 20);
    map.insert(1, 30);

    EXPECT_EQ(map.capacity(), 4);
    EXPECT_EQ(map.size(), 1);
}


// Multiple Rehashes

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


// Rehash Preserves Updated Values

TEST(HashMapRehashTest, RehashPreservesUpdatedValues)
{
    HashMap<int, int> map(2);

    map.insert(1, 10);
    map.insert(1, 20);

    for(int i = 2; i < 20; i++)
        map.insert(i, i);

    EXPECT_EQ(map.get(1), 20);
}


// Rehash Preserves Negative Keys

TEST(HashMapRehashTest, RehashPreservesNegativeKeys)
{
    HashMap<int, int> map(2);

    map.insert(-1, 100);
    map.insert(-2, 200);
    map.insert(1, 300);
    map.insert(2, 400);

    EXPECT_EQ(map.get(-1), 100);
    EXPECT_EQ(map.get(-2), 200);
}


// Rehash Preserves Zero Key

TEST(HashMapRehashTest, RehashPreservesZeroKey)
{
    HashMap<int, int> map(2);

    map.insert(0, 500);

    for(int i = 1; i < 20; i++)
        map.insert(i, i);

    EXPECT_EQ(map.get(0), 500);
}


// Rehash Size Remains Correct

TEST(HashMapRehashTest, RehashDoesNotChangeSize)
{
    HashMap<int, int> map(2);

    for(int i = 0; i < 50; i++)
        map.insert(i, i);

    EXPECT_EQ(map.size(), 50);
}


// Rehash Capacity Grows Only When Needed

TEST(HashMapRehashTest, CapacityDoesNotGrowBeforeThreshold)
{
    HashMap<int, int> map(8);

    map.insert(1, 1);
    map.insert(2, 2);
    map.insert(3, 3);

    EXPECT_EQ(map.capacity(), 8);
}

// Rehash Supports Continued Inserts

TEST(HashMapRehashTest, InsertWorksAfterRehash)
{
    HashMap<int, int> map(2);

    for(int i = 0; i < 20; i++)
        map.insert(i, i);

    map.insert(100, 500);

    EXPECT_EQ(map.get(100), 500);
    EXPECT_EQ(map.size(), 21);
}


// Multiple Consecutive Rehashes Preserve Data

TEST(HashMapRehashTest, ConsecutiveRehashesPreserveData)
{
    HashMap<int, int> map(2);

    for(int i = 0; i < 500; i++)
        map.insert(i, i * 2);

    EXPECT_EQ(map.size(), 500);

    for(int i = 0; i < 500; i++)
        EXPECT_EQ(map.get(i), i * 2);
}