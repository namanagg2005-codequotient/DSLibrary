#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListGetHeadTest, EmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.getHead(), nullptr);
}

TEST(LinkedListGetHeadTest, SingleElement)
{
    LinkedList<int> list;

    list.insertFront(10);

    ASSERT_NE(list.getHead(), nullptr);
    EXPECT_EQ(list.getHead()->value, 10);
}

TEST(LinkedListGetHeadTest, MultipleElements)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    ASSERT_NE(list.getHead(), nullptr);
    EXPECT_EQ(list.getHead()->value, 10);
}

TEST(LinkedListGetHeadTest, AfterDeletingHead)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.deleteFront();

    ASSERT_NE(list.getHead(), nullptr);
    EXPECT_EQ(list.getHead()->value, 20);
}