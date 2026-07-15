#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapRemoveTest, RemoveExistingKey)
{
    HashMap<int, std::string> map;

    map.set(1, "One");

    map.remove(1);

    EXPECT_FALSE(map.exists(1));
    EXPECT_EQ(map.getSize(), 0);
}

TEST(HashMapRemoveTest, RemoveFromMultipleKeys)
{
    HashMap<int, std::string> map;

    map.set(1, "One");
    map.set(2, "Two");
    map.set(3, "Three");

    map.remove(2);

    EXPECT_TRUE(map.exists(1));
    EXPECT_FALSE(map.exists(2));
    EXPECT_TRUE(map.exists(3));

    EXPECT_EQ(map.getSize(), 2);
}

TEST(HashMapRemoveTest, RemoveFirstInsertedKey)
{
    HashMap<int, int> map;

    map.set(10, 100);
    map.set(20, 200);

    map.remove(10);

    EXPECT_FALSE(map.exists(10));
    EXPECT_TRUE(map.exists(20));
}

TEST(HashMapRemoveTest, RemoveLastRemainingKey)
{
    HashMap<int, int> map;

    map.set(5, 50);

    map.remove(5);

    EXPECT_EQ(map.getSize(), 0);
    EXPECT_FALSE(map.exists(5));
}

TEST(HashMapRemoveTest, RemoveNonExistingKeyDoesNotChangeSize)
{
    HashMap<int, int> map;

    map.set(1, 10);
    map.set(2, 20);

    int before = map.getSize();

    map.remove(100);

    EXPECT_EQ(map.getSize(), before);
}

TEST(HashMapRemoveTest, RemoveNegativeKey)
{
    HashMap<int, std::string> map;

    map.set(-10, "Negative");

    map.remove(-10);

    EXPECT_FALSE(map.exists(-10));
}

TEST(HashMapRemoveTest, RemoveAfterRehash)
{
    HashMap<int, int> map;

    for(int i = 0; i < 100; i++)
    {
        map.set(i, i * 5);
    }

    map.remove(50);

    EXPECT_FALSE(map.exists(50));
    EXPECT_EQ(map.getSize(), 99);

    EXPECT_EQ(map.get(10), 50);
    EXPECT_EQ(map.get(99), 495);
}

TEST(HashMapRemoveTest, RemoveAllKeys)
{
    HashMap<int, int> map;

    for(int i = 0; i < 20; i++)
    {
        map.set(i, i);
    }

    for(int i = 0; i < 20; i++)
    {
        map.remove(i);
    }

    EXPECT_EQ(map.getSize(), 0);

    for(int i = 0; i < 20; i++)
    {
        EXPECT_FALSE(map.exists(i));
    }
}