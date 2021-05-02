#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
    int num = 0;
    int grade = 0;
};

int main()
{
    int N;
    cin >> N;
    vector<Student> students;
    for (int i = 1; i <= N; ++i)
    {
        Student curr_student;
        cin >> curr_student.num >> curr_student.grade;
        students.push_back(curr_student);
    }
    double sum_grade = 0;
    for (auto &student:students)
    {
        if (student.num % 9 == 0)
        {
            student.grade = 59;
        }
        if ((student.num % 10 == 9) || ((student.num / 10) % 10 == 9) || (student.num / 100 == 9))
        {
            student.grade = 59;
        }
        sum_grade += student.grade;
    }
    cout << sum_grade;
}