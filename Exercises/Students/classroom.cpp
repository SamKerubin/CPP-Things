#include "classroom.h"
#include "file_manager.h"
#include <iostream>
#include <filesystem>

// Constructor to create an standar classroom (unique classroom name needed)
Classroom::Classroom(const std::string &className_)
    : className(className_)
{
    // Loads possibles students saved in the .txt file
    students = FileManager::loadStudents("..\\Classrooms\\" + className + ".txt");

    // If loaded, then updates the last ID to the ID of the last student in the loaded list
    // If the list is empty, then it just sets the ID to -1 (the default ID)
    currentId = students.empty() ? -1 : (--students.end())->second->id;
}

// Returns the student who have an specific ID assigned
std::shared_ptr<Student> Classroom::getStudentById(const int id_) { return students.find(id_)->second; }

// Automatically generates an ID, just add one to the new ID
int Classroom::genId()
{
    return currentId += 1;
}

// A students is aproved if their average grade is above or equals to 3.0
bool Classroom::isAproved(const float average_) { return average_ >= 3.0f; }

void Classroom::addStudent(const std::shared_ptr<Student> &student_)
{
    // Doesnt allow you to add more than the maximum specified (100 students per classroom)
    if (students.size() >= __MAX_STUDENTS_PER_CLASSROM)
    {
        std::cerr << "Max students possible reached in this class, please try with other class" << std::endl;
        return;
    }

    // Generates a new ID for the new student
    student_->id = genId();

    if (students.count(student_->id))
    {
        return;
    }

    student_->passed = isAproved(student_->averageGrade);

    // Add the new student to the student list
    students.emplace(student_->id, student_);

    // Saves the value to the .txt file
    FileManager::saveStudents("..\\Classrooms\\" + className + ".txt", students);
}

// Shows every student in the classroom
void Classroom::getAllStudents()
{
    for (auto it = students.begin(); it != students.end(); it++)
    {
        std::cout << it->second->toString() << std::endl;
    }
}

// I... think it explains itself??
float Classroom::calculateOverallAverageGrade()
{
    float grade{0};
    for (auto it = students.begin(); it != students.end(); it++)
    {
        grade += it->second->averageGrade;
    }

    return (students.empty()) ? 0.0f : grade / static_cast<float>(students.size());
}