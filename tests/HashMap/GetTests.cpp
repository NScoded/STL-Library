#include <gtest/gtest.h>
#include "HashMap.h"
#include <string>

TEST(HashMapGetTest, GetSingleElement)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");

    EXPECT_EQ(map.get(1), "One");
}

TEST(HashMapGetTest, GetMultipleElements)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.insert(2, "Two");
    map.insert(3, "Three");

    EXPECT_EQ(map.get(1), "One");
    EXPECT_EQ(map.get(2), "Two");
    EXPECT_EQ(map.get(3), "Three");
}

TEST(HashMapGetTest, GetUpdatedValue)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.insert(1, "Updated");

    EXPECT_EQ(map.get(1), "Updated");
}

TEST(HashMapGetTest, GetNegativeKey)
{
    HashMap<int, std::string> map;

    map.insert(-10, "Negative");

    EXPECT_EQ(map.get(-10), "Negative");
}

TEST(HashMapGetTest, GetZeroKey)
{
    HashMap<int, std::string> map;

    map.insert(0, "Zero");

    EXPECT_EQ(map.get(0), "Zero");
}

TEST(HashMapGetTest, GetStringKey)
{
    HashMap<std::string, int> map;

    map.insert("Apple", 10);
    map.insert("Banana", 20);

    EXPECT_EQ(map.get("Apple"), 10);
    EXPECT_EQ(map.get("Banana"), 20);
}

TEST(HashMapGetTest, GetNonExistingKeyThrows)
{
    HashMap<int, int> map;

    EXPECT_THROW(map.get(100), std::runtime_error);
}

TEST(HashMapGetTest, GetAfterRemoveThrows)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.remove(1);

    EXPECT_THROW(map.get(1), std::runtime_error);
}