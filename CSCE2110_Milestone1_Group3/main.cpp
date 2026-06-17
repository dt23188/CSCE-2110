#include <iostream>
#include <string>
#include "CampusMap.h"
#include "StudentList.h"
#include "FileManager.h"

using namespace std;

void displayMenu() {
    cout << endl;
    cout << "===== Medical School Campus System - Milestone 1 =====" << endl;
    cout << "1. Display Campus Map" << endl;
    cout << "2. Add Student" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Display Students" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter choice: ";
}

Student getStudentInput() {
    Student student;

    cout << "Enter student ID: ";
    cin >> student.id;

    cout << "Enter student name: ";
    cin >> student.name;

    cout << "Enter student major: ";
    cin >> student.major;

    cout << "Enter student GPA: ";
    cin >> student.gpa;

    return student;
}

int main() {
    CampusMap campusMap;
    StudentList studentList;

    string mapFilename;
    string studentFilename;

    cout << "Enter campus map filename: ";
    cin >> mapFilename;

    if (campusMap.loadMap(mapFilename)) {
        cout << "Campus map loaded successfully." << endl;
    }

    cout << "Enter student records filename: ";
    cin >> studentFilename;

    if (FileManager::loadStudents(studentFilename, studentList)) {
        cout << "Student records loaded successfully." << endl;
    }

    int choice = 0;

    while (choice != 5) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                campusMap.displayMap();
                break;

            case 2: {
                Student newStudent = getStudentInput();

                if (studentList.addStudent(newStudent)) {
                    cout << "Student added successfully." << endl;
                }

                break;
            }

            case 3: {
                int searchID;

                cout << "Enter student ID to search: ";
                cin >> searchID;

                Student* foundStudent = studentList.searchStudent(searchID);

                if (foundStudent != nullptr) {
                    cout << endl;
                    cout << "Student Found:" << endl;
                    cout << "ID: " << foundStudent->id << endl;
                    cout << "Name: " << foundStudent->name << endl;
                    cout << "Major: " << foundStudent->major << endl;
                    cout << "GPA: " << foundStudent->gpa << endl;
                } else {
                    cout << "Student not found." << endl;
                }

                break;
            }

            case 4:
                studentList.displayStudents();
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
