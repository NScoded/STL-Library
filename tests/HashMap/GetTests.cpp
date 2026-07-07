#include <gtest/gtest.h>
#include "HashMap.h"
#include <string>
#include <climits>

//
// Get Single Element
//
TEST(HashMapGetTest, GetSingleElement)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");

    EXPECT_EQ(map.get(1), "One");
}

//
// Get Multiple Elements
//
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

//
// Get Updated Value
//
TEST(HashMapGetTest, GetUpdatedValue)
{
    HashMap<int, std::string> map;

    map.insert(1, "One");
    map.insert(1, "Updated");

    EXPECT_EQ(map.get(1), "Updated");
}

//
// Get Negative Key
//
TEST(HashMapGetTest, GetNegativeKey)
{
    HashMap<int, std::string> map;

    map.insert(-10, "Negative");

    EXPECT_EQ(map.get(-10), "Negative");
}

//
// Get Zero Key
//
TEST(HashMapGetTest, GetZeroKey)
{
    HashMap<int, std::string> map;

    map.insert(0, "Zero");

    EXPECT_EQ(map.get(0), "Zero");
}

//
// Get String Key
//
TEST(HashMapGetTest, GetStringKey)
{
    HashMap<std::string, int> map;

    map.insert("Apple", 10);
    map.insert("Banana", 20);

    EXPECT_EQ(map.get("Apple"), 10);
    EXPECT_EQ(map.get("Banana"), 20);
}

//
// Get Large Integer Keys
//
TEST(HashMapGetTest, GetLargeIntegerKeys)
{
    HashMap<int, int> map;

    map.insert(INT_MAX, 100);
    map.insert(INT_MIN, 200);

    EXPECT_EQ(map.get(INT_MAX), 100);
    EXPECT_EQ(map.get(INT_MIN), 200);
}

//
// Get Empty String Key
//
TEST(HashMapGetTest, GetEmptyStringKey)
{
    HashMap<std::string, int> map;

    map.insert("", 50);

    EXPECT_EQ(map.get(""), 50);
}

//
// Get After Rehash
//
TEST(HashMapGetTest, GetAfterRehash)
{
    HashMap<int, int> map(2);

    for(int i = 0; i < 20; i++)
        map.insert(i, i * 10);

    for(int i = 0; i < 20; i++)
        EXPECT_EQ(map.get(i), i * 10);
}

//
// Get Non Existing Key
//
TEST(HashMapGetTest, GetNonExistingKeyThrows)
{
    HashMap<int, int> map;

    EXPECT_THROW(map.get(100), std::out_of_range);
}

//
// Get After Remove
//
TEST(HashMapGetTest, GetAfterRemoveThrows)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.remove(1);

    EXPECT_THROW(map.get(1), std::out_of_range);
}

//
// Get From Empty Map
//
TEST(HashMapGetTest, GetFromEmptyMapThrows)
{
    HashMap<int, int> map;

    EXPECT_THROW(map.get(1), std::out_of_range);
}

//
// Get Missing Key Among Existing Keys
//
TEST(HashMapGetTest, GetMissingKeyAmongExistingKeysThrows)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    EXPECT_THROW(map.get(4), std::out_of_range);
}

//
// Get Does Not Modify Map
//
TEST(HashMapGetTest, GetDoesNotModifyMap)
{
    HashMap<int, int> map;

    map.insert(1, 10);

    int sizeBefore = map.size();

    EXPECT_EQ(map.get(1), 10);
    EXPECT_EQ(map.size(), sizeBefore);
}