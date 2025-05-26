#ifndef __STUDENT_H_

#define __STUDENT_H_

#include <string>

struct Student
{
    std::string name;
    int id;
    int age;
    float averageGrade;
    bool passed;

    Student(const std::string &name_, const int age_, const float averageGrade_);
    Student(const std::string &name_, const int id_, const int age_, const float averageGrade_, const bool passed_);
    std::string toString();
};

#endif