#include <gtest/gtest.h>
#include "HashMap.h"
#include <string>

TEST(HashMapRemoveTest, RemoveExistingKey)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.remove(1);

    EXPECT_EQ(map.size(), 0);
    EXPECT_FALSE(map.exists(1));
}

TEST(HashMapRemoveTest, RemoveFromMultipleElements)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.insert(2, "Two");
    map.insert(3, "Three");

    map.remove(2);

    EXPECT_EQ(map.size(), 2);
    EXPECT_TRUE(map.exists(1));
    EXPECT_FALSE(map.exists(2));
    EXPECT_TRUE(map.exists(3));
}

TEST(HashMapRemoveTest, RemoveFirstInsertedElement)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    map.remove(1);

    EXPECT_FALSE(map.exists(1));
    EXPECT_TRUE(map.exists(2));
    EXPECT_TRUE(map.exists(3));
    EXPECT_EQ(map.size(), 2);
}

TEST(HashMapRemoveTest, RemoveLastInsertedElement)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    map.remove(3);

    EXPECT_TRUE(map.exists(1));
    EXPECT_TRUE(map.exists(2));
    EXPECT_FALSE(map.exists(3));
    EXPECT_EQ(map.size(), 2);
}

TEST(HashMapRemoveTest, RemoveMiddleElement)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    map.remove(2);

    EXPECT_TRUE(map.exists(1));
    EXPECT_FALSE(map.exists(2));
    EXPECT_TRUE(map.exists(3));
    EXPECT_EQ(map.size(), 2);
}

TEST(HashMapRemoveTest, RemoveNegativeKey)
{
    HashMap<int, std::string> map;

    map.insert(-5, "Negative");
    map.remove(-5);

    EXPECT_FALSE(map.exists(-5));
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapRemoveTest, RemoveZeroKey)
{
    HashMap<int, std::string> map;

    map.insert(0, "Zero");
    map.remove(0);

    EXPECT_FALSE(map.exists(0));
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapRemoveTest, RemoveNonExistingKey)
{
    HashMap<int, int> map;

    EXPECT_EQ(map.remove(100), false);
}

TEST(HashMapRemoveTest, RemoveFromEmptyMap)
{
    HashMap<int, int> map;

    EXPECT_EQ(map.remove(1), false);
}

TEST(HashMapRemoveTest, RemoveAllElements)
{
    HashMap<int, int> map;

    for (int i = 0; i < 10; i++)
        map.insert(i, i);

    for (int i = 0; i < 10; i++)
        map.remove(i);

    EXPECT_EQ(map.size(), 0);

    for (int i = 0; i < 10; i++)
        EXPECT_FALSE(map.exists(i));
}