#include <iostream>
#include <string>
#include <limits>
#include "CampusMap.h"
#include "StudentList.h"
#include "FileManager.h"

using namespace std;

// Function to display the main menu
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

// Function to get a valid integer input from the user
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

// Function to get a valid student ID (greater than zero) from the user
int getValidStudentID(const string& prompt) {
    while (true) {
        int id = getValidInteger(prompt);

        if (id > 0) {
            return id;
        }

        cout << "Student ID must be greater than zero." << endl;
    }
}

// Function to get a valid GPA (between 0.0 and 4.0) from the user
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

//  Function to get student input from the user and return a Student object
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

// Main function to run the program
int main() {
	// Create instances of CampusMap and StudentList
    CampusMap campusMap;
    StudentList studentList;

	// Prompt the user for filenames and load the campus map and student records
    string mapFilename;
    string studentFilename;

	// Load campus map and student records from files
    cout << "Enter campus map filename: ";
    cin >> mapFilename;

	// Load the campus map from campus_map.txt
    if (campusMap.loadMap(mapFilename)) {
        cout << "Campus map loaded successfully." << endl;
    }

	// Load student records from student_records.txt
    cout << "Enter student records filename: ";
    cin >> studentFilename;

	// Load the student records from student_records.txt
    if (FileManager::loadStudents(studentFilename, studentList)) {
        cout << "Student records loaded successfully." << endl;
    }

	// Main loop to display the menu and handle user choices
    int choice = 0;

	// Loop until the user chooses menu options 1-4, option 5 exits
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
            }
            else {
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
