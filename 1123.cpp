#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

class Course
{
public:
    string course_name[10];
    Course() {}
    string getname(int no)
    {
        return course_name[no];
    }
    int getno(string name)
    {
        for (int i = 0; i < 10; ++i) {
            if (course_name[i]==name) {
                return i;
            }
        }
    }
    void shuru(int no,string name)
    {
        course_name[no] = name;
    }

};
class Teacher
{
public:

    Course course;
    Teacher(Course &rcourse) {
        course=rcourse;
    }
    int homework(string name)
    {
        return course.getno(name);
    }
    int review(int answer)
    {
        if (answer>60) {
            return 88;
        }
        else
            return 44;
    }
};

class Student
{
public:
    Course course;
    Student(Course &cs) {
        course=cs;
    }
    int dohomework(int course_no)
    {
        return pow(course_no,2);
    }
};

int main()
{
    Course course;
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        int no;
        string name;
        cin>>no>>name;
        course.shuru(no,name);
    }

    Teacher teacher(course);
    Student student(course);
    int n;
    cin>>n;
    if (n<t) {
        for (int i = 0; i < n; ++i) {
            string homework;
            cin>>homework;
            cout<<teacher.review(student.dohomework(teacher.homework(homework)))<<endl;
        }
    }
    return 0;
}
