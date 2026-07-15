#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListRemoveTest, RemoveHead)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.remove(10));

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.getHead()->value, 20);
    EXPECT_EQ(list.getTail()->value, 30);
}

TEST(LinkedListRemoveTest, RemoveMiddle)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.remove(20));

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getHead()->next->value, 30);
    EXPECT_EQ(list.getTail()->value, 30);
}

TEST(LinkedListRemoveTest, RemoveTail)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.remove(30));

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getTail()->value, 20);
    EXPECT_EQ(list.getTail()->next, nullptr);
}

TEST(LinkedListRemoveTest, RemoveOnlyNode)
{
    LinkedList<int> list;

    list.insertBack(10);

    EXPECT_TRUE(list.remove(10));

    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
}

TEST(LinkedListRemoveTest, RemoveNonExistingNode)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    EXPECT_FALSE(list.remove(30));

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getTail()->value, 20);
}