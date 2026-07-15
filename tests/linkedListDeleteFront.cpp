#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListDeleteFrontTest, DeleteFromSingleElementList)
{
    LinkedList<int> list;

    list.insertFront(10);

    EXPECT_EQ(list.deleteFront(), 10);

    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
}

TEST(LinkedListDeleteFrontTest, DeleteFromMultipleElementList)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_EQ(list.deleteFront(), 10);

    EXPECT_EQ(list.size(), 2);

    ASSERT_NE(list.getHead(), nullptr);
    ASSERT_NE(list.getTail(), nullptr);

    EXPECT_EQ(list.getHead()->value, 20);
    EXPECT_EQ(list.getHead()->prev, nullptr);
    EXPECT_EQ(list.getHead()->next->value, 30);

    EXPECT_EQ(list.getTail()->value, 30);
}

TEST(LinkedListDeleteFrontTest, DeleteUntilEmpty)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    EXPECT_EQ(list.deleteFront(), 10);
    EXPECT_EQ(list.deleteFront(), 20);

    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
}

TEST(LinkedListDeleteFrontTest, DeleteFromEmptyList)
{
    LinkedList<int> list;

    EXPECT_THROW(list.deleteFront(), std::out_of_range);
}