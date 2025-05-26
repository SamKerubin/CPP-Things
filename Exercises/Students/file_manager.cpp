#include "file_manager.h"
#include "student.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <regex>

// This is honestly not mine...
// Splits a string using a pattern as a regex
std::vector<std::string> split(const std::string &str, std::string &&pattern)
{
    std::regex re(pattern); // Create a regex using a string pattern

    // Creates an iterator and advances it for every token (match) found in the string
    std::sregex_token_iterator it(str.begin(), str.end(), re, -1);
    std::sregex_token_iterator end;

    return {it, end};
}

// Saves (or also creates) the file that will hold the information of
// every student from a classroom
void FileManager::saveStudents(const std::string &path_, const std::map<const int, std::shared_ptr<Student>> &students_)
{
    // Opens a file to be written, if it doesnt exists, creates it
    std::ofstream file(path_, std::ofstream::out); // Notice the second parameter, its used to clear the file once is opened

    // If for some reason the file cant be opened or created,
    // The program stop the saving and continue with its process
    if (!file)
    {
        std::cerr << "Error while trying to access file " << path_ << std::endl;
        return;
    }

    // Iterates over all students in a classroom and saves them in the file as strings
    for (auto it = students_.begin(); it != students_.end(); it++)
    {
        file << it->second->name << ", " << it->second->id << ", "
            << it->second->age << ", " << it->second->averageGrade
            << ", " << it->second->passed << std::endl;
    }

    file.close();
}

// Loads the students saved in a created .txt file
std::map<const int, std::shared_ptr<Student>> FileManager::loadStudents(const std::string &path_)
{
    std::map<const int, std::shared_ptr<Student>> students;

    // If the file doesnt exists, it means that the classroom its empty
    if (!std::filesystem::exists(path_))
    {
        // Creates a new file with the path
        std::ofstream file(path_);
        return students; // And return an empty list of students
    }

    // If not, opens the file to read it
    std::ifstream file(path_);
    std::string content;
    while (std::getline(file, content))
    {
        // Uses the split method to match every value from the student
        std::vector<std::string> matches = split(content, ", ");
        if (matches.size() != 5) // Idk why this would happen, but better prevent
        {
            continue;
        }

        // The matches needs to contain 5 values:
        // 0 -> name, 1 -> id, 2 -> age, 3 -> grade, 4 -> if its approved
        std::string name = matches[0];
        int id = std::stoi(matches[1]);
        int age = std::stoi(matches[2]);
        float averageGrade = std::stof(matches[3]);
        bool passed = (matches[4] == "1") ? true : false;

        // Creates an new student and then adds it to the temp lists of students
        std::shared_ptr<Student> student = std::make_shared<Student>(name, id, age, averageGrade, passed);
        students.emplace(id, student);
    }

    return students;
}