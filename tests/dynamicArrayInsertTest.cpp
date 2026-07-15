#include <gtest/gtest.h>
#include "dynamicArray.h"
#include <string>

TEST(DynamicArrayTest, InsertFrontString)
{
    DynamicArray<std::string> arr;

    arr.append("Banana");
    arr.append("Cherry");

    arr.insert(0, "Apple");

    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Banana");
    EXPECT_EQ(arr[2], "Cherry");
}

TEST(DynamicArrayTest, InsertMiddleString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Cherry");

    arr.insert(1, "Banana");

    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Banana");
    EXPECT_EQ(arr[2], "Cherry");
}

TEST(DynamicArrayTest, InsertBackString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");

    arr.insert(2, "Cherry");

    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Banana");
    EXPECT_EQ(arr[2], "Cherry");
}

TEST(DynamicArrayTest, InsertIntoEmptyArray)
{
    DynamicArray<std::string> arr;

    arr.insert(0, "Apple");

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr[0], "Apple");
}

TEST(DynamicArrayTest, InsertTriggersResize)
{
    DynamicArray<std::string> arr;

    arr.append("A");
    arr.append("B");
    arr.append("D");
    arr.append("E");

    arr.insert(2, "C");

    EXPECT_EQ(arr.getSize(), 5);
    EXPECT_EQ(arr.getCapacity(), 8);

    EXPECT_EQ(arr[0], "A");
    EXPECT_EQ(arr[1], "B");
    EXPECT_EQ(arr[2], "C");
    EXPECT_EQ(arr[3], "D");
    EXPECT_EQ(arr[4], "E");
}

TEST(DynamicArrayTest, InsertInvalidPositiveIndex)
{
    DynamicArray<std::string> arr;

    EXPECT_THROW(arr.insert(1, "Apple"), std::out_of_range);
}

TEST(DynamicArrayTest, InsertNegativeIndex)
{
    DynamicArray<std::string> arr;

    EXPECT_THROW(arr.insert(-1, "Apple"), std::out_of_range);
}