#include <iostream>
#include <list>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    unsigned age = 0;

    bool operator==(Student &b) const
    {
        return this->age == b.age;
    }
};

int main()
{
    unsigned N;
    cin >> N;
    list<Student> students;

    for (unsigned cnt = 1; cnt <= N; ++cnt)
    {
        Student curr_student;
        cin >> curr_student.name >> curr_student.age;
        students.push_back(curr_student);
    }
    Student ming;
    cin >> ming.age;


    for (auto it = students.begin(); it != students.cend();)
    {
        auto curr_it = it;
        ++it;
        if (*curr_it == ming)
        {
            students.erase(curr_it);
        }
    }

    for (auto &student:students)
    {
        cout << student.name;
        if (student.name != (--students.end())->name)
        {
            cout << " ";
        }

    }

    return 0;
}