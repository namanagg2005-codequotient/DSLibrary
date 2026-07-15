#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListDeleteBackTest, DeleteFromSingleElementList)
{
    LinkedList<int> list;

    list.insertBack(10);

    EXPECT_EQ(list.deleteBack(), 10);

    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
}

TEST(LinkedListDeleteBackTest, DeleteFromMultipleElementList)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_EQ(list.deleteBack(), 30);

    EXPECT_EQ(list.size(), 2);

    ASSERT_NE(list.getHead(), nullptr);
    ASSERT_NE(list.getTail(), nullptr);

    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getHead()->next->value, 20);

    EXPECT_EQ(list.getTail()->value, 20);
    EXPECT_EQ(list.getTail()->next, nullptr);
    EXPECT_EQ(list.getTail()->prev->value, 10);
}

TEST(LinkedListDeleteBackTest, DeleteUntilEmpty)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    EXPECT_EQ(list.deleteBack(), 20);
    EXPECT_EQ(list.deleteBack(), 10);

    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
}

TEST(LinkedListDeleteBackTest, DeleteFromEmptyList)
{
    LinkedList<int> list;

    EXPECT_THROW(list.deleteBack(), std::out_of_range);
}