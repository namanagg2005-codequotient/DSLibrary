#include <gtest/gtest.h>
#include <stdexcept>
#include "hashMap.h"

TEST(HashMapGetTest, GetExistingKey)
{
    HashMap<int, std::string> map;

    map.set(1, "One");

    EXPECT_EQ(map.get(1), "One");
}

TEST(HashMapGetTest, GetMultipleKeys)
{
    HashMap<int, std::string> map;

    map.set(1, "One");
    map.set(2, "Two");
    map.set(3, "Three");

    EXPECT_EQ(map.get(1), "One");
    EXPECT_EQ(map.get(2), "Two");
    EXPECT_EQ(map.get(3), "Three");
}

TEST(HashMapGetTest, GetThrowsExceptionForMissingKey)
{
    HashMap<int, std::string> map;

    EXPECT_THROW(map.get(100), std::out_of_range);
}

TEST(HashMapGetTest, GetAfterUpdatingValue)
{
    HashMap<int, std::string> map;

    map.set(1, "One");
    map.set(1, "Updated");

    EXPECT_EQ(map.get(1), "Updated");
}

TEST(HashMapGetTest, GetAfterRehash)
{
    HashMap<int, int> map;

    for(int i = 0; i < 100; i++)
    {
        map.set(i, i * 10);
    }

    for(int i = 0; i < 100; i++)
    {
        EXPECT_EQ(map.get(i), i * 10);
    }
}

TEST(HashMapGetTest, ReturnedReferenceCanModifyValue)
{
    HashMap<int, std::string> map;

    map.set(10, "Alice");

    map.get(10) = "Bob";

    EXPECT_EQ(map.get(10), "Bob");
}

TEST(HashMapGetTest, GetNegativeKey)
{
    HashMap<int, std::string> map;

    map.set(-5, "Negative");

    EXPECT_EQ(map.get(-5), "Negative");
}