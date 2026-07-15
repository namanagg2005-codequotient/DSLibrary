#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListSizeTest, EmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListSizeTest, AfterInsertAndDeleteOperations)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertFront(5);

    EXPECT_EQ(list.size(), 3);

    list.deleteFront();
    EXPECT_EQ(list.size(), 2);

    list.deleteBack();
    EXPECT_EQ(list.size(), 1);
}