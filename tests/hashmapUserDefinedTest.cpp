#include <gtest/gtest.h>
#include <string>
#include "hashMap.h"

class Student
{
public:
    int rollNo;
    std::string name;

    Student()
    {
        rollNo = 0;
        name = "";
    }

    Student(int rollNo, const std::string& name)
    {
        this->rollNo = rollNo;
        this->name = name;
    }

    bool operator==(const Student& other) const
    {
        return rollNo == other.rollNo &&
               name == other.name;
    }
};

template<>
class Hash<Student>
{
public:
    size_t operator()(const Student& s) const
    {
        return Hash<int>()(s.rollNo);
    }
};

TEST(HashMapUserDefinedTest, InsertAndGetUserDefinedKey)
{
    HashMap<Student, std::string> map;

    Student s1(101, "Alice");

    map.set(s1, "CSE");

    EXPECT_EQ(map.get(s1), "CSE");
}

TEST(HashMapUserDefinedTest, ExistsUserDefinedKey)
{
    HashMap<Student, int> map;

    Student s1(1, "Alice");

    map.set(s1, 95);

    EXPECT_TRUE(map.exists(s1));
}

TEST(HashMapUserDefinedTest, RemoveUserDefinedKey)
{
    HashMap<Student, int> map;

    Student s1(1, "Alice");

    map.set(s1, 100);

    map.remove(s1);

    EXPECT_FALSE(map.exists(s1));
    EXPECT_EQ(map.getSize(), 0);
}

TEST(HashMapUserDefinedTest, UpdateExistingUserDefinedKey)
{
    HashMap<Student, std::string> map;

    Student s1(10, "Rahul");

    map.set(s1, "Physics");
    map.set(s1, "Mathematics");

    EXPECT_EQ(map.get(s1), "Mathematics");
    EXPECT_EQ(map.getSize(), 1);
}

TEST(HashMapUserDefinedTest, UserDefinedValueType)
{
    HashMap<int, Student> map;

    Student s1(201, "Naman");

    map.set(1, s1);

    Student result = map.get(1);

    EXPECT_EQ(result.rollNo, 201);
    EXPECT_EQ(result.name, "Naman");
}

TEST(HashMapUserDefinedTest, MultipleUserDefinedKeys)
{
    HashMap<Student, int> map;

    Student s1(1, "Alice");
    Student s2(2, "Bob");
    Student s3(3, "Charlie");

    map.set(s1, 90);
    map.set(s2, 85);
    map.set(s3, 95);

    EXPECT_EQ(map.get(s1), 90);
    EXPECT_EQ(map.get(s2), 85);
    EXPECT_EQ(map.get(s3), 95);

    EXPECT_EQ(map.getSize(), 3);
}

TEST(HashMapUserDefinedTest, UserDefinedKeyAfterRehash)
{
    HashMap<Student, int> map;

    for(int i = 0; i < 100; i++)
    {
        Student s(i, "Student");
        map.set(s, i);
    }

    for(int i = 0; i < 100; i++)
    {
        Student s(i, "Student");
        EXPECT_EQ(map.get(s), i);
    }

    EXPECT_EQ(map.getSize(), 100);
}

TEST(HashMapUserDefinedTest, MissingUserDefinedKeyThrows)
{
    HashMap<Student, int> map;

    Student s1(10, "Rahul");

    EXPECT_THROW(map.get(s1), std::out_of_range);
}