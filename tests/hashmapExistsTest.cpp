#include <gtest/gtest.h>
#include "hashMap.h"
#include <string>

TEST(HashMapExistsTest, ExistingKeyReturnsTrue)
{
    HashMap<int, std::string> map;

    map.set(1, "One");

    EXPECT_TRUE(map.exists(1));
}

TEST(HashMapExistsTest, MissingKeyReturnsFalse)
{
    HashMap<int, std::string> map;

    EXPECT_FALSE(map.exists(100));
}

TEST(HashMapExistsTest, ExistsAfterMultipleInsertions)
{
    HashMap<int, std::string> map;

    map.set(1, "One");
    map.set(2, "Two");
    map.set(3, "Three");

    EXPECT_TRUE(map.exists(1));
    EXPECT_TRUE(map.exists(2));
    EXPECT_TRUE(map.exists(3));
}

TEST(HashMapExistsTest, ExistsAfterRemoval)
{
    HashMap<int, std::string> map;

    map.set(1, "One");
    map.remove(1);

    EXPECT_FALSE(map.exists(1));
}

TEST(HashMapExistsTest, ExistsAfterUpdatingValue)
{
    HashMap<int, std::string> map;

    map.set(10, "Alice");
    map.set(10, "Bob");

    EXPECT_TRUE(map.exists(10));
}

TEST(HashMapExistsTest, ExistsWithNegativeKey)
{
    HashMap<int, std::string> map;

    map.set(-10, "Negative");

    EXPECT_TRUE(map.exists(-10));
}

TEST(HashMapExistsTest, ExistsAfterRehash)
{
    HashMap<int, int> map;

    for (int i = 0; i < 100; i++)
    {
        map.set(i, i);
    }

    for (int i = 0; i < 100; i++)
    {
        EXPECT_TRUE(map.exists(i));
    }

    EXPECT_FALSE(map.exists(200));
}

TEST(HashMapExistsTest, StringKeys)
{
    HashMap<std::string, int> map;

    map.set("Alice", 90);
    map.set("Bob", 80);

    EXPECT_TRUE(map.exists("Alice"));
    EXPECT_TRUE(map.exists("Bob"));
    EXPECT_FALSE(map.exists("Charlie"));
}