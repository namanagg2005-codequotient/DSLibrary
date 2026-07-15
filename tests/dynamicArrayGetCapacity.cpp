#include <gtest/gtest.h>
#include "dynamicArray.h"
#include <string>

TEST(DynamicArrayTest, GetCapacityDefaultConstructor)
{
    DynamicArray<std::string> arr;

    EXPECT_EQ(arr.getCapacity(), 4);
}

TEST(DynamicArrayTest, GetCapacityParameterizedConstructor)
{
    DynamicArray<std::string> arr(10);

    EXPECT_EQ(arr.getCapacity(), 16);
}

TEST(DynamicArrayTest, GetCapacityAfterSingleResize)
{
    DynamicArray<std::string> arr;

    arr.append("A");
    arr.append("B");
    arr.append("C");
    arr.append("D");
    arr.append("E");   // Resize from 4 → 8

    EXPECT_EQ(arr.getCapacity(), 8);
}

TEST(DynamicArrayTest, GetCapacityAfterMultipleResizes)
{
    DynamicArray<std::string> arr;

    for (int i = 0; i < 20; i++)
    {
        arr.append("Element");
    }

    EXPECT_GE(arr.getCapacity(), 20);
}