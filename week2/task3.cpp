#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Student
{
public:
    unsigned num = 0;
    double height = 0;
    unsigned pos = 0;
};

int main()
{
    unsigned N;
    cin >> N;
    list<Student> students;
    for (unsigned cnt = 1; cnt <= N; ++cnt)
    {

        Student curr_student;
        curr_student.num = cnt;
        cin >> curr_student.height;
        students.push_back(curr_student);
    }

    students.sort([](Student &a, Student &b)
                  {
                      return a.height > b.height;
                  });

    unsigned pos = 1;
    for (auto &student:students)
    {
        student.pos = pos;
        ++pos;
    }

    for (unsigned num = 1; num <= N; ++num)
    {
        auto it = find_if(students.begin(), students.end(), [&num](Student student)
        { return student.num == num; });
        cout << it->pos << " ";

        if (it == students.cbegin())
        {
            cout << "0 ";
        } else
        {
            --it;
            cout << it->num << " ";
            ++it;
        }

        ++it;
        if (it == students.cend())
        {
            cout << "0";
        } else
        {
            cout << it->num;
        }
        cout << endl;
    }
    return 0;
}