#include <gtest/gtest.h>
#include "dynamicArray.h"
#include <string>

TEST(DynamicArrayTest, AppendSingleString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr[0], "Apple");
}

TEST(DynamicArrayTest, AppendMultipleStrings)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");

    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Banana");
    EXPECT_EQ(arr[2], "Cherry");
}

TEST(DynamicArrayTest, AppendDuplicateStrings)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Apple");

    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Apple");
}

TEST(DynamicArrayTest, AppendTriggersResize)
{
    DynamicArray<std::string> arr;

    arr.append("A");
    arr.append("B");
    arr.append("C");
    arr.append("D");
    arr.append("E");   // Triggers resize from 4 to 8

    EXPECT_EQ(arr.getSize(), 5);
    EXPECT_EQ(arr.getCapacity(), 8);

    EXPECT_EQ(arr[0], "A");
    EXPECT_EQ(arr[1], "B");
    EXPECT_EQ(arr[2], "C");
    EXPECT_EQ(arr[3], "D");
    EXPECT_EQ(arr[4], "E");
}