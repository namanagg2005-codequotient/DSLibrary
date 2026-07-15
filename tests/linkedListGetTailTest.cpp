#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListGetTailTest, EmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.getTail(), nullptr);
}

TEST(LinkedListGetTailTest, SingleElement)
{
    LinkedList<int> list;

    list.insertBack(10);

    ASSERT_NE(list.getTail(), nullptr);
    EXPECT_EQ(list.getTail()->value, 10);
}

TEST(LinkedListGetTailTest, MultipleElements)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    ASSERT_NE(list.getTail(), nullptr);
    EXPECT_EQ(list.getTail()->value, 30);
}

TEST(LinkedListGetTailTest, AfterDeletingTail)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.deleteBack();

    ASSERT_NE(list.getTail(), nullptr);
    EXPECT_EQ(list.getTail()->value, 10);
}