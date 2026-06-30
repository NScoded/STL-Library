#include <gtest/gtest.h>
#include "HashMap.h"
#include <string>

TEST(HashMapExistsTest, ExistingKeyReturnsTrue)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");

    EXPECT_TRUE(map.exists(1));
}

TEST(HashMapExistsTest, NonExistingKeyReturnsFalse)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");

    EXPECT_FALSE(map.exists(2));
}

TEST(HashMapExistsTest, EmptyMapReturnsFalse)
{
    HashMap<int, std::string> map;

    EXPECT_FALSE(map.exists(1));
}

TEST(HashMapExistsTest, NegativeKey)
{
    HashMap<int, std::string> map;

    map.insert(-10, "Negative");

    EXPECT_TRUE(map.exists(-10));
    EXPECT_FALSE(map.exists(-20));
}

TEST(HashMapExistsTest, ZeroKey)
{
    HashMap<int, std::string> map;

    map.insert(0, "Zero");

    EXPECT_TRUE(map.exists(0));
}

TEST(HashMapExistsTest, AfterRemoveReturnsFalse)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.remove(1);

    EXPECT_FALSE(map.exists(1));
}

TEST(HashMapExistsTest, MultipleElements)
{
    HashMap<int, int> map;

    for (int i = 0; i < 50; i++)
        map.insert(i, i * 10);

    for (int i = 0; i < 50; i++)
        EXPECT_TRUE(map.exists(i));

    EXPECT_FALSE(map.exists(100));
}

TEST(HashMapExistsTest, StringKeys)
{
    HashMap<std::string, int> map;

    map.insert("Apple", 10);
    map.insert("Banana", 20);

    EXPECT_TRUE(map.exists("Apple"));
    EXPECT_TRUE(map.exists("Banana"));
    EXPECT_FALSE(map.exists("Orange"));
}

TEST(HashMapExistsTest, DuplicateInsertStillExists)
{
    HashMap<int, int> map;

    map.insert(5, 10);
    map.insert(5, 20);

    EXPECT_TRUE(map.exists(5));
    EXPECT_EQ(map.size(), 1);
}