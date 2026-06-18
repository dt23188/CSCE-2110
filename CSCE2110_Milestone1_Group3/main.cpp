#include <iostream>
#include <string>
#include <limits>
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

int getValidInteger(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input. Please enter a whole number." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int getValidStudentID(const string& prompt) {
    while (true) {
        int id = getValidInteger(prompt);

        if (id > 0) {
            return id;
        }

        cout << "Student ID must be greater than zero." << endl;
    }
}

float getValidGPA(const string& prompt) {
    float gpa;

    while (true) {
        cout << prompt;

        if (cin >> gpa && gpa >= 0.0f && gpa <= 4.0f) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return gpa;
        }

        cout << "Invalid GPA. Enter a value from 0.0 to 4.0." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


Student getStudentInput() {
    Student student;

    student.id = getValidStudentID("Enter student ID: ");

    cout << "Enter student name: ";
    cin >> student.name;

    cout << "Enter student major: ";
    cin >> student.major;

    student.gpa = getValidGPA("Enter student GPA: ");

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
        choice = getValidInteger("");

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
                int searchID = getValidStudentID(
                "Enter student ID to search: "
            );

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
