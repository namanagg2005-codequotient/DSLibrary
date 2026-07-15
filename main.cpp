#include <iostream>
#include "hashMap.h"
using namespace std;
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
        return rollNo == other.rollNo;
    }

    size_t createHash() const
    {
        return Hash<int>()(rollNo);
    }
};
int main()
{
HashMap<Student, float> mp;

mp.set(Student(1,"Naman"),8.7f);
mp.set(Student(2,"Rahul"),9.1f);

std::cout<<mp.get(Student(1,""))<<'\n';
std::cout<<mp.get(Student(2,""))<<'\n';
}


