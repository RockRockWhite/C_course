#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
    int num = 0;
    int _class = 0;
    string name;

};

bool cmp(Student a, Student b)
{
    if (a._class < b._class)
    {
        return true;
    } else if (a._class == b._class)
    {
        return a.num < b.num;
    } else
    {
        return false;
    }

}

int main()
{
    int N;
    cin >> N;
    vector<Student> students;
    for (int cnt = 1; cnt <= N; ++cnt)
    {
        Student curr_student;
        cin >> curr_student.num >> curr_student._class >> curr_student.name;
        students.push_back(curr_student);
    }


    sort(students.begin(), students.end(), cmp);

    for (auto &student:students)
    {
        cout << student.name << endl;
    }
    return 0;
}