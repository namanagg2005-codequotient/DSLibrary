#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListInsertBackTest, InsertIntoEmptyList)
{
    LinkedList<int> list;

    list.insertBack(10);

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getTail()->value, 10);
}

TEST(LinkedListInsertBackTest, InsertMultipleElements)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getHead()->next->value, 20);
    EXPECT_EQ(list.getTail()->value, 30);
}

TEST(LinkedListInsertBackTest, TailUpdatedCorrectly)
{
    LinkedList<int> list;

    list.insertBack(5);
    list.insertBack(15);

    EXPECT_EQ(list.getTail()->value, 15);
    EXPECT_EQ(list.getTail()->prev->value, 5);
    EXPECT_EQ(list.getTail()->next, nullptr);
}

TEST(LinkedListInsertBackTest, HeadRemainsUnchanged)
{
    LinkedList<int> list;

    list.insertBack(10);
    Node<int>* firstHead = list.getHead();

    list.insertBack(20);
    list.insertBack(30);

    EXPECT_EQ(list.getHead(), firstHead);
    EXPECT_EQ(list.getHead()->value, 10);
}