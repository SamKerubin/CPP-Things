#include "student.h"
#include <sstream>

// Consturctor made to create an standar student struct
Student::Student(const std::string &name_, const int age_, const float averageGrade_)
    : name(name_), age(age_), averageGrade(averageGrade_)
{
}

// Constructor made to create a pre-loaded student struct
Student::Student(const std::string &name_, const int id_, const int age_, const float averageGrade_, const bool passed_)
    : name(name_), id(id_), age(age_), averageGrade(averageGrade_), passed(passed_)
{
}

// Parses all the properties from a Student to a formated string
std::string Student::toString()
{
    std::stringstream format;
    format << "Name: " << name
            << "\nID: " << id
            << "\nAge: " << age
            << "\nAverage Grade: " << averageGrade
            << "\nAproved: " << (passed ? "Yes" : "No");

    return format.str();
}