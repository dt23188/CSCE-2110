#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

bool FileManager::loadStudents(const string& filename, StudentList& studentList) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error: Could not open student file." << endl;
        return false;
    }

    Student student;
    int count = 0;

    while (inputFile >> student.id >> student.name >> student.major >> student.gpa) {
        if (studentList.addStudent(student)) {
            count++;
        }
    }

    inputFile.close();

    cout << count << " student record(s) loaded." << endl;
    return true;
}
