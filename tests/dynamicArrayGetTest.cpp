#include <gtest/gtest.h>
#include "dynamicArray.h"
#include <string>

TEST(DynamicArrayTest, GetFirstString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");

    EXPECT_EQ(arr.get(0), "Apple");
}

TEST(DynamicArrayTest, GetMiddleString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");

    EXPECT_EQ(arr.get(1), "Banana");
}

TEST(DynamicArrayTest, GetLastString)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");

    EXPECT_EQ(arr.get(2), "Cherry");
}

TEST(DynamicArrayTest, GetInvalidPositiveIndex)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");

    EXPECT_THROW(arr.get(1), std::out_of_range);
}

TEST(DynamicArrayTest, GetNegativeIndex)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");

    EXPECT_THROW(arr.get(-1), std::out_of_range);
}