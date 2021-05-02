#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

/*定义保存学生的class*/
class Student
{
public:
    int num;
    string name;
    int math_grade;
    int chi_grade;
    int eng_grade;

    Student()
    {

    }

    // std::move(_name)?? TODO
    Student(int _num, string _name, int _eng_grade, int _math_grade, int _chi_grade) : num(_num),
                                                                                       name(std::move(_name)),
                                                                                       math_grade(_math_grade),
                                                                                       chi_grade(_chi_grade),
                                                                                       eng_grade(_eng_grade)
    {
    }
};

int main()
{
    // 取得学生总数
    int N;
    cin >> N;
    // 保存学生数据的vector
    vector<Student> Students;
    // 获得每个学生的数据
    for (int cnt = 1; cnt <= N; ++cnt)
    {
        // 临时的学生对象
        int num;
        string name;
        int math_grade;
        int chi_grade;
        int eng_grade;
        cin >> num >> name >> eng_grade >> math_grade >> chi_grade;
        Student curr_student(num, name, eng_grade, math_grade, chi_grade);
        // 放入vector中
        Students.push_back(curr_student);
    }

    // 计算平均成绩 获得成绩最高的学生
    double mean_eng = 0;
    double mean_math = 0;
    double mean_chi = 0;
    Student top_student;
    int total_degree = 0;
    for (auto &student:Students)
    {
        mean_eng += student.eng_grade;
        mean_math += student.math_grade;
        mean_chi += student.chi_grade;
        if ((student.eng_grade + student.math_grade + student.chi_grade) > total_degree)
        {
            top_student = student;
            total_degree = student.eng_grade + student.math_grade + student.chi_grade;
        }
        if ((student.eng_grade + student.math_grade + student.chi_grade) == total_degree &&
            student.num < top_student.num)
        {
            top_student = student;
            total_degree = student.eng_grade + student.math_grade + student.chi_grade;
        }


    }
    mean_eng /= Students.size();
    mean_math /= Students.size();
    mean_chi /= Students.size();

    // 两位小数输出成绩
    cout << fixed << setprecision(2) << mean_eng << " "
         << fixed << setprecision(2) << mean_math << " "
         << fixed << setprecision(2) << mean_chi << endl;

    // 输出最高姓名
    cout << top_student.name;

    return 0;
}