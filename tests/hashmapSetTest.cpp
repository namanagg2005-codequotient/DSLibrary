#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapSetTest, InsertSingleKeyValuePair)
{
    HashMap<int, std::string> map;

    map.set(1, "One");

    EXPECT_EQ(map.get(1), "One");
    EXPECT_TRUE(map.exists(1));
    EXPECT_EQ(map.getSize(), 1);
}

TEST(HashMapSetTest, InsertMultipleKeyValuePairs)
{
    HashMap<int, std::string> map;

    map.set(1, "One");
    map.set(2, "Two");
    map.set(3, "Three");

    EXPECT_EQ(map.get(1), "One");
    EXPECT_EQ(map.get(2), "Two");
    EXPECT_EQ(map.get(3), "Three");

    EXPECT_EQ(map.getSize(), 3);
}

TEST(HashMapSetTest, UpdatingExistingKeyChangesValue)
{
    HashMap<int, std::string> map;

    map.set(10, "Alice");
    map.set(10, "Bob");

    EXPECT_EQ(map.get(10), "Bob");
}

TEST(HashMapSetTest, UpdatingExistingKeyDoesNotIncreaseSize)
{
    HashMap<int, std::string> map;

    map.set(10, "Alice");

    int before = map.getSize();

    map.set(10, "Bob");

    EXPECT_EQ(map.getSize(), before);
}

TEST(HashMapSetTest, InsertNegativeKey)
{
    HashMap<int, std::string> map;

    map.set(-5, "Negative");

    EXPECT_TRUE(map.exists(-5));
    EXPECT_EQ(map.get(-5), "Negative");
}

TEST(HashMapSetTest, InsertStringKeys)
{
    HashMap<std::string, int> map;

    map.set("Alice", 90);
    map.set("Bob", 85);

    EXPECT_EQ(map.get("Alice"), 90);
    EXPECT_EQ(map.get("Bob"), 85);
}

TEST(HashMapSetTest, RehashPreservesAllValues)
{
    HashMap<int, int> map;

    for (int i = 0; i < 100; i++)
    {
        map.set(i, i * 10);
    }

    for (int i = 0; i < 100; i++)
    {
        EXPECT_EQ(map.get(i), i * 10);
    }

    EXPECT_EQ(map.getSize(), 100);
}

TEST(HashMapSetTest, RehashDoesNotLoseExistingData)
{
    HashMap<int, std::string> map;

    for (int i = 0; i < 50; i++)
    {
        map.set(i, "Value");
    }

    for (int i = 0; i < 50; i++)
    {
        EXPECT_TRUE(map.exists(i));
    }
}