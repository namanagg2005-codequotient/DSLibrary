#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListInsertTest, InsertAtBeginning)
{
    LinkedList<int> list;

    list.insertBack(20);
    list.insertBack(30);

    list.insert(0, 10);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getHead()->next->value, 20);
    EXPECT_EQ(list.getTail()->value, 30);
}

TEST(LinkedListInsertTest, InsertInMiddle)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(30);

    list.insert(1, 20);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getHead()->next->value, 20);
    EXPECT_EQ(list.getTail()->value, 30);
}

TEST(LinkedListInsertTest, InsertAtEnd)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.insert(5, 30);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.getTail()->value, 30);
    EXPECT_EQ(list.getTail()->prev->value, 20);
}

TEST(LinkedListInsertTest, InsertInvalidIndex)
{
    LinkedList<int> list;

    EXPECT_THROW(list.insert(-1, 10), std::out_of_range);
}