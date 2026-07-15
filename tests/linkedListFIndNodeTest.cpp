#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListFindNodeTest, FindHeadNode)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    Node<int>* node = list.findNode(10);

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 10);
    EXPECT_EQ(node, list.getHead());
}

TEST(LinkedListFindNodeTest, FindMiddleNode)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    Node<int>* node = list.findNode(20);

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 20);
    EXPECT_EQ(node->prev->value, 10);
    EXPECT_EQ(node->next->value, 30);
}

TEST(LinkedListFindNodeTest, FindTailNode)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    Node<int>* node = list.findNode(30);

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 30);
    EXPECT_EQ(node, list.getTail());
}

TEST(LinkedListFindNodeTest, FindNonExistingNode)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    Node<int>* node = list.findNode(40);

    EXPECT_EQ(node, nullptr);
}