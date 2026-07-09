#include <gtest/gtest.h>
#include "HashMap.h"

TEST(HashMapGetKeysTest, EmptyHashMap)
{
    HashMap<std::string, int> map;

    DynamicArray<std::string> keys = map.getkeys();

    EXPECT_EQ(keys.size(), 0);
}

TEST(HashMapGetKeysTest, SingleElement)
{
    HashMap<std::string, int> map;

    map.insert("apple", 10);

    DynamicArray<std::string> keys = map.getkeys();

    ASSERT_EQ(keys.size(), 1);
    EXPECT_EQ(keys[0], "apple");
}

TEST(HashMapGetKeysTest, MultipleElements)
{
    HashMap<std::string, int> map;

    map.insert("apple", 10);
    map.insert("banana", 20);
    map.insert("orange", 30);

    DynamicArray<std::string> keys = map.getkeys();

    EXPECT_EQ(keys.size(), 3);

    bool foundApple = false;
    bool foundBanana = false;
    bool foundOrange = false;

    for (int i = 0; i < keys.size(); i++)
    {
        if (keys[i] == "apple") foundApple = true;
        if (keys[i] == "banana") foundBanana = true;
        if (keys[i] == "orange") foundOrange = true;
    }

    EXPECT_TRUE(foundApple);
    EXPECT_TRUE(foundBanana);
    EXPECT_TRUE(foundOrange);
}

TEST(HashMapGetKeysTest, DuplicateInsertUpdatesValue)
{
    HashMap<std::string, int> map;

    map.insert("apple", 10);
    map.insert("apple", 50);

    DynamicArray<std::string> keys = map.getkeys();

    ASSERT_EQ(keys.size(), 1);
    EXPECT_EQ(keys[0], "apple");
}

TEST(HashMapGetKeysTest, IntegerKeys)
{
    HashMap<int, std::string> map;

    map.insert(10, "A");
    map.insert(20, "B");
    map.insert(30, "C");

    DynamicArray<int> keys = map.getkeys();

    EXPECT_EQ(keys.size(), 3);

    bool found10 = false;
    bool found20 = false;
    bool found30 = false;

    for (int i = 0; i < keys.size(); i++)
    {
        if (keys[i] == 10) found10 = true;
        if (keys[i] == 20) found20 = true;
        if (keys[i] == 30) found30 = true;
    }

    EXPECT_TRUE(found10);
    EXPECT_TRUE(found20);
    EXPECT_TRUE(found30);
}