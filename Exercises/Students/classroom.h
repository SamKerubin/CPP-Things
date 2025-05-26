#ifndef __CLASSROOM_H_

#define __CLASSROOM_H_

// Constant value to prevent too much students in a same calssroom
#define __MAX_STUDENTS_PER_CLASSROM 100

#include "student.h"
#include <map>
#include <memory>
#include <fstream>

struct Classroom
{
    std::string className;
    std::map<const int, std::shared_ptr<Student>> students;
    int currentId;

    Classroom(const std::string &className_);

    std::shared_ptr<Student> getStudentById(const int id_);
    void addStudent(const std::shared_ptr<Student> &student_);
    void getAllStudents();
    float calculateOverallAverageGrade();

private:
    bool isAproved(const float average_);
    int genId();
};

#endif