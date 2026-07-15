#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapGetterTest, DefaultSizeIsZero)
{
    HashMap<int, int> map;

    EXPECT_EQ(map.getSize(), 0);
}

TEST(HashMapGetterTest, SizeAfterSingleInsertion)
{
    HashMap<int, int> map;

    map.set(1, 10);

    EXPECT_EQ(map.getSize(), 1);
}

TEST(HashMapGetterTest, SizeAfterMultipleInsertions)
{
    HashMap<int, int> map;

    map.set(1, 10);
    map.set(2, 20);
    map.set(3, 30);

    EXPECT_EQ(map.getSize(), 3);
}

TEST(HashMapGetterTest, SizeDoesNotIncreaseForDuplicateKey)
{
    HashMap<int, int> map;

    map.set(1, 10);
    map.set(1, 20);

    EXPECT_EQ(map.getSize(), 1);
}

TEST(HashMapGetterTest, SizeDecreasesAfterRemoval)
{
    HashMap<int, int> map;

    map.set(1, 10);
    map.set(2, 20);

    map.remove(1);

    EXPECT_EQ(map.getSize(), 1);
}

TEST(HashMapGetterTest, DefaultLoadFactorIsZero)
{
    HashMap<int, int> map;

    EXPECT_FLOAT_EQ(map.getLoadFactor(), 0.0f);
}

TEST(HashMapGetterTest, LoadFactorAfterOneInsertion)
{
    HashMap<int, int> map;

    map.set(1, 10);

    EXPECT_FLOAT_EQ(map.getLoadFactor(), 1.0f / 8.0f);
}

TEST(HashMapGetterTest, LoadFactorAfterMultipleInsertions)
{
    HashMap<int, int> map;

    map.set(1, 10);
    map.set(2, 20);
    map.set(3, 30);

    EXPECT_FLOAT_EQ(map.getLoadFactor(), 3.0f / 8.0f);
}

TEST(HashMapGetterTest, LoadFactorAfterRemoval)
{
    HashMap<int, int> map;

    map.set(1, 10);
    map.set(2, 20);

    map.remove(1);

    EXPECT_FLOAT_EQ(map.getLoadFactor(), 1.0f / 8.0f);
}

