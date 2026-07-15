#include <gtest/gtest.h>
#include "dynamicArray.h"
#include <string>

TEST(DynamicArrayTest, GetSizeEmptyArray)
{
    DynamicArray<std::string> arr;

    EXPECT_EQ(arr.getSize(), 0);
}

TEST(DynamicArrayTest, GetSizeAfterAppend)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");

    EXPECT_EQ(arr.getSize(), 3);
}

TEST(DynamicArrayTest, GetSizeAfterInsert)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Cherry");

    arr.insert(1, "Banana");

    EXPECT_EQ(arr.getSize(), 3);
}

TEST(DynamicArrayTest, GetSizeAfterRemove)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");

    arr.remove(1);

    EXPECT_EQ(arr.getSize(), 2);
}