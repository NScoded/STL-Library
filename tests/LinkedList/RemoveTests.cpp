#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListRemoveTest, RemoveHead)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.remove(0);

    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list.head->data, 20);
    EXPECT_EQ(list.tail->data, 30);
}

TEST(LinkedListRemoveTest, RemoveMiddle)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.remove(1);

    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.head->next->data, 30);
    EXPECT_EQ(list.tail->data, 30);
}

TEST(LinkedListRemoveTest, RemoveTail)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.remove(2);

    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.tail->data, 20);
    EXPECT_EQ(list.tail->next, nullptr);
}

TEST(LinkedListRemoveTest, RemoveOnlyElement)
{
    LinkedList<int> list;

    list.append(100);

    list.remove(0);

    EXPECT_EQ(list.length(), 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

TEST(LinkedListRemoveTest, RemoveNonExistingElement)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    EXPECT_THROW(list.remove(50),std::out_of_range);
}

TEST(LinkedListRemoveTest, RemoveFromEmptyList)
{
    LinkedList<int> list;

    EXPECT_THROW(list.remove(0),std::out_of_range);
}

TEST(LinkedListRemoveTest, RemoveFirstOccurrenceOnly)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(20);
    list.append(30);

    list.remove(1);

    EXPECT_EQ(list.length(), 3);

    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.head->next->data, 20);
    EXPECT_EQ(list.tail->data, 30);
}