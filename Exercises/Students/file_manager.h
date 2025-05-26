#ifndef __FILE_MANAGER_H_

#define __FILE_MANAGER_H_

#include "student.h"
#include <map>
#include <memory>
#include <fstream>

struct FileManager
{
    static void saveStudents(const std::string &path_, const std::map<const int, std::shared_ptr<Student>> &students_);
    static std::map<const int, std::shared_ptr<Student>> loadStudents(const std::string &path_);
};

#endif