#include <gtest/gtest.h>
#include "HashMap.h"
#include <string>

//
// Insert Single Element
//
TEST(HashMapInsertTest, InsertSingleElement)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");

    EXPECT_EQ(map.size(), 1);
    EXPECT_TRUE(map.exists(1));
    EXPECT_EQ(map.get(1), "One");
}

//
// Insert Multiple Elements
//
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

//
// Insert Duplicate Key
//
TEST(HashMapInsertTest, InsertDuplicateKeyUpdatesValue)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.insert(1, "Updated");

    EXPECT_EQ(map.size(), 1);
    EXPECT_EQ(map.get(1), "Updated");
}

//
// Insert Negative Key
//
TEST(HashMapInsertTest, InsertNegativeKey)
{
    HashMap<int, std::string> map;

    map.insert(-10, "Negative");

    EXPECT_TRUE(map.exists(-10));
    EXPECT_EQ(map.get(-10), "Negative");
}

//
// Insert Zero Key
//
TEST(HashMapInsertTest, InsertZeroKey)
{
    HashMap<int, std::string> map;

    map.insert(0, "Zero");

    EXPECT_TRUE(map.exists(0));
    EXPECT_EQ(map.get(0), "Zero");
}

//
// Insert Many Elements
//
TEST(HashMapInsertTest, InsertManyElements)
{
    HashMap<int, int> map;

    for(int i = 0; i < 100; i++)
        map.insert(i, i * 10);

    EXPECT_EQ(map.size(), 100);

    for(int i = 0; i < 100; i++)
    {
        EXPECT_TRUE(map.exists(i));
        EXPECT_EQ(map.get(i), i * 10);
    }
}

//
// Insert String Keys
//
TEST(HashMapInsertTest, InsertStringKeys)
{
    HashMap<std::string, int> map;

    map.insert("Apple", 10);
    map.insert("Banana", 20);

    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.get("Apple"), 10);
    EXPECT_EQ(map.get("Banana"), 20);
}

//
// Insert Duplicate Multiple Times
//
TEST(HashMapInsertTest, InsertAfterDuplicateUpdatesOnlyValue)
{
    HashMap<int, int> map;

    map.insert(5, 100);
    map.insert(5, 200);
    map.insert(5, 300);

    EXPECT_EQ(map.size(), 1);
    EXPECT_EQ(map.get(5), 300);
}

//
// Insert Maintains Existing Elements
//
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

//
// Insert Triggers Rehash
//
TEST(HashMapInsertTest, InsertTriggersRehash)
{
    HashMap<int, int> map(4);

    for(int i = 0; i < 10; i++)
        map.insert(i, i);

    EXPECT_GT(map.capacity(), 4);
    EXPECT_EQ(map.size(), 10);

    for(int i = 0; i < 10; i++)
        EXPECT_EQ(map.get(i), i);
}

//
// Insert Large Integer Keys
//
TEST(HashMapInsertTest, InsertLargeIntegerKeys)
{
    HashMap<int, int> map;

    map.insert(INT_MAX, 100);
    map.insert(INT_MIN, 200);

    EXPECT_EQ(map.get(INT_MAX), 100);
    EXPECT_EQ(map.get(INT_MIN), 200);
}

//
// Insert Empty String Key
//
TEST(HashMapInsertTest, InsertEmptyStringKey)
{
    HashMap<std::string, int> map;

    map.insert("", 50);

    EXPECT_TRUE(map.exists(""));
    EXPECT_EQ(map.get(""), 50);
}

//
// Insert Empty String Value
//
TEST(HashMapInsertTest, InsertEmptyStringValue)
{
    HashMap<int, std::string> map;

    map.insert(1, "");

    EXPECT_TRUE(map.exists(1));
    EXPECT_EQ(map.get(1), "");
}

//
// Insert After Rehash
//
TEST(HashMapInsertTest, InsertAfterRehash)
{
    HashMap<int, int> map(2);

    for(int i = 0; i < 20; i++)
        map.insert(i, i * 5);

    map.insert(100, 500);

    EXPECT_EQ(map.get(100), 500);
    EXPECT_EQ(map.size(), 21);
}

//
// Insert Same Value Different Keys
//
TEST(HashMapInsertTest, InsertSameValueDifferentKeys)
{
    HashMap<int, std::string> map;

    map.insert(1, "Same");
    map.insert(2, "Same");
    map.insert(3, "Same");

    EXPECT_EQ(map.size(), 3);

    EXPECT_EQ(map.get(1), "Same");
    EXPECT_EQ(map.get(2), "Same");
    EXPECT_EQ(map.get(3), "Same");
}