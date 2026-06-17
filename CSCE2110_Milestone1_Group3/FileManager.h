#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "StudentList.h"

class FileManager {
public:
    static bool loadStudents(const std::string& filename, StudentList& studentList);
};

#endif
