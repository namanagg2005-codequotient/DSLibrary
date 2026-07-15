#include <gtest/gtest.h>
#include "dynamicArray.h"
#include <string>

TEST(DynamicArrayTest, RemoveFrontString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");

    EXPECT_EQ(arr.remove(0), "Apple");

    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr[0], "Banana");
    EXPECT_EQ(arr[1], "Cherry");
}

TEST(DynamicArrayTest, RemoveMiddleString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");
    arr.append("Date");

    EXPECT_EQ(arr.remove(2), "Cherry");

    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Banana");
    EXPECT_EQ(arr[2], "Date");
}

TEST(DynamicArrayTest, RemoveBackString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");

    EXPECT_EQ(arr.remove(2), "Cherry");

    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Banana");
}

TEST(DynamicArrayTest, RemoveSingleElementString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");

    EXPECT_EQ(arr.remove(0), "Apple");

    EXPECT_EQ(arr.getSize(), 0);
}

TEST(DynamicArrayTest, RemoveInvalidIndexString)
{
    DynamicArray<std::string> arr;

    EXPECT_THROW(arr.remove(0), std::out_of_range);
}