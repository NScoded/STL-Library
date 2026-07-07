#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListLengthTest, InitiallyZero)
{
    LinkedList<int> list;

    EXPECT_EQ(list.length(), 0);
}

TEST(LinkedListLengthTest, AfterInsertions)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    EXPECT_EQ(list.length(), 3);
}

TEST(LinkedListLengthTest, AfterRemoval)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);

    list.remove(0);

    EXPECT_EQ(list.length(), 1);
}

TEST(LinkedListLengthTest, AfterClear)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);

    list.clear();

    EXPECT_EQ(list.length(), 0);
}