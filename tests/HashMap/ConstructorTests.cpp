#include <gtest/gtest.h>
#include "HashMap.h"
#include <string>

TEST(HashMapConstructorTest, DefaultConstructorInitializesEmptyMap)
{
    HashMap<int, std::string> map;

    EXPECT_EQ(map.size(), 0);
    EXPECT_EQ(map.capacity(), 16);    
    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}

TEST(HashMapConstructorTest, ConstructorCreatesIndependentObjects)
{
    HashMap<int, std::string> map1;
    HashMap<int, std::string> map2;

    EXPECT_EQ(map1.size(), 0);
    EXPECT_EQ(map2.size(), 0);

    EXPECT_EQ(map1.capacity(), map2.capacity());
    EXPECT_FLOAT_EQ(map1.loadFactor(), 0.0f);
    EXPECT_FLOAT_EQ(map2.loadFactor(), 0.0f);
}

TEST(HashMapConstructorTest, EmptyMapDoesNotContainAnyKey)
{
    HashMap<int, std::string> map;

    EXPECT_FALSE(map.exists(10));
    EXPECT_FALSE(map.exists(-1));
    EXPECT_FALSE(map.exists(0));
}

TEST(HashMapConstructorTest, EmptyMapThrowsOnGet)
{
    HashMap<int, std::string> map;

    EXPECT_THROW(map.get(10), std::runtime_error);
}

TEST(HashMapConstructorTest, ConstructorWorksForDifferentKeyValueTypes)
{
    HashMap<std::string, int> map;

    EXPECT_EQ(map.size(), 0);
    EXPECT_EQ(map.capacity(), 16);     
    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}

