#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListInsertFrontTest, InsertIntoEmptyList)
{
    LinkedList<int> list;

    list.insertFront(10);

    EXPECT_EQ(list.size(), 1);
    ASSERT_NE(list.getHead(), nullptr);
    ASSERT_NE(list.getTail(), nullptr);

    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getTail()->value, 10);
    EXPECT_EQ(list.getHead(), list.getTail());
    EXPECT_EQ(list.getHead()->next, nullptr);
    EXPECT_EQ(list.getHead()->prev, nullptr);
}

TEST(LinkedListInsertFrontTest, InsertMultipleElements)
{
    LinkedList<int> list;

    list.insertFront(30);
    list.insertFront(20);
    list.insertFront(10);

    EXPECT_EQ(list.size(), 3);

    ASSERT_NE(list.getHead(), nullptr);
    ASSERT_NE(list.getTail(), nullptr);

    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getHead()->next->value, 20);
    EXPECT_EQ(list.getTail()->value, 30);
}

TEST(LinkedListInsertFrontTest, HeadUpdatedCorrectly)
{
    LinkedList<int> list;

    list.insertFront(20);
    list.insertFront(10);

    ASSERT_NE(list.getHead(), nullptr);

    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getHead()->prev, nullptr);
    EXPECT_EQ(list.getHead()->next->value, 20);
}

TEST(LinkedListInsertFrontTest, TailRemainsUnchanged)
{
    LinkedList<int> list;

    list.insertFront(10);
    Node<int>* originalTail = list.getTail();

    list.insertFront(20);
    list.insertFront(30);

    EXPECT_EQ(list.size(), 3);

    ASSERT_NE(list.getTail(), nullptr);

    EXPECT_EQ(list.getTail(), originalTail);
    EXPECT_EQ(list.getTail()->value, 10);
    EXPECT_EQ(list.getTail()->next, nullptr);
    EXPECT_EQ(list.getTail()->prev->value, 20);
}