#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListSearchTest, SearchExistingElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.search(20));
}

TEST(LinkedListSearchTest, SearchNonExistingElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_FALSE(list.search(40));
}

TEST(LinkedListSearchTest, SearchInEmptyList)
{
    LinkedList<int> list;

    EXPECT_FALSE(list.search(10));
}

TEST(LinkedListSearchTest, SearchAfterDeletion)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    list.deleteFront();

    EXPECT_FALSE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}