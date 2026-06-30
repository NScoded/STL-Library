#include <gtest/gtest.h>
#include "HashMap.h"
#include <string>

TEST(HashMapInsertTest, InsertSingleElement)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");

    EXPECT_EQ(map.size(), 1);
    EXPECT_TRUE(map.exists(1));
    EXPECT_EQ(map.get(1), "One");
}

TEST(HashMapInsertTest, InsertMultipleElements)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.insert(2, "Two");
    map.insert(3, "Three");

    EXPECT_EQ(map.size(), 3);

    EXPECT_EQ(map.get(1), "One");
    EXPECT_EQ(map.get(2), "Two");
    EXPECT_EQ(map.get(3), "Three");
}

TEST(HashMapInsertTest, InsertDuplicateKeyUpdatesValue)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.insert(1, "Updated");

    EXPECT_EQ(map.size(), 1);
    EXPECT_EQ(map.get(1), "Updated");
}

TEST(HashMapInsertTest, InsertNegativeKey)
{
    HashMap<int, std::string> map;

    map.insert(-10, "Negative");

    EXPECT_TRUE(map.exists(-10));
    EXPECT_EQ(map.get(-10), "Negative");
}

TEST(HashMapInsertTest, InsertZeroKey)
{
    HashMap<int, std::string> map;

    map.insert(0, "Zero");

    EXPECT_TRUE(map.exists(0));
    EXPECT_EQ(map.get(0), "Zero");
}

TEST(HashMapInsertTest, InsertManyElements)
{
    HashMap<int, int> map;

    for (int i = 0; i < 100; i++)
    {
        map.insert(i, i * 10);
    }

    EXPECT_EQ(map.size(), 100);

    for (int i = 0; i < 100; i++)
    {
        EXPECT_TRUE(map.exists(i));
        EXPECT_EQ(map.get(i), i * 10);
    }
}

TEST(HashMapInsertTest, InsertStringKeys)
{
    HashMap<std::string, int> map;

    map.insert("Apple", 10);
    map.insert("Banana", 20);

    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.get("Apple"), 10);
    EXPECT_EQ(map.get("Banana"), 20);
}

TEST(HashMapInsertTest, InsertAfterDuplicateUpdatesOnlyValue)
{
    HashMap<int, int> map;

    map.insert(5, 100);
    map.insert(5, 200);
    map.insert(5, 300);

    EXPECT_EQ(map.size(), 1);
    EXPECT_EQ(map.get(5), 300);
}

TEST(HashMapInsertTest, InsertMaintainsOtherElements)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.insert(2, "Two");
    map.insert(2, "Updated");
    map.insert(3, "Three");

    EXPECT_EQ(map.size(), 3);

    EXPECT_EQ(map.get(1), "One");
    EXPECT_EQ(map.get(2), "Updated");
    EXPECT_EQ(map.get(3), "Three");
}

