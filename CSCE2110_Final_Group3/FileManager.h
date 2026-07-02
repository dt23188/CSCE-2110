#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "StudentList.h"
using namespace std;

class FileManager {
private:
    struct FileNode {
        string data;
        FileNode* next;

        FileNode(const string& value) {
            data = value;
            next = nullptr;
        }
    };

    FileNode* head;
    FileNode* tail;

public:
    FileManager();
    ~FileManager();

    bool loadFile(const string& filename);
    bool saveFile(const string& filename) const;

    // Load student records from a file into the provided StudentList
    bool loadStudents(const string& filename, StudentList& list);

    // Save student records from the provided StudentList to a file
    bool saveStudents(const string& filename, const StudentList& list) const;

    void addLine(const string& line);
    void displayLines() const;
    void clear();
};

#endif
