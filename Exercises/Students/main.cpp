#include "student.h"
#include "classroom.h"
#include <iostream>

/*
    So, this was basically an exercise made to create a basic (but realistic)
    implementation of everything id learnt along this repository,
    the last exercise was a bit... "Uncomplete", so, this one make so much more

    This exercise is a classroom system, allows you to create different classrooms and store students inside of it,
    When created a classroom, a .txt file is also created, and then, when a student is created, they are added
    to the .txt file (like a database)
*/

int main()
{
    std::shared_ptr<Student> student = std::make_shared<Student>("Sam", 16, 5.0f);
    Classroom classroom{"Class1"};
    classroom.addStudent(student);
    classroom.getAllStudents();
    std::cout << classroom.calculateOverallAverageGrade() << std::endl;

    return 0;
}