#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "CampusMap.h"
#include "StudentList.h"
#include "FileManager.h"
#include "QueueSystem.h"

using namespace std;

// Function to display the main menu
void displayMenu() {
    cout << endl;
    cout << "===== Medical School Campus System =====" << endl;
    cout << "1. Display Campus Map" << endl;
    cout << "2. Explore Location" << endl;
    cout << "3. Add Student" << endl;
    cout << "4. Remove Student" << endl;
    cout << "5. Search Student" << endl;
    cout << "6. Display Students" << endl;
    cout << "7. Sort Students by ID" << endl;
    cout << "8. Add Advising Request" << endl;
    cout << "9. Process Advising Request" << endl;
    cout << "10. Display Pending Requests" << endl;
    cout << "11. Display Statistics" << endl;
    cout << "12. Exit" << endl;
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
    QueueSystem advisingQueue;

	// Prompt the user for filenames and load the campus map and student records
    string mapFilename;
    string studentFilename;

	do {
        cout << "Enter campus map filename: ";
        cin >> mapFilename;
    } while (!campusMap.loadMap(mapFilename));

    cout << "Campus map loaded successfully." << endl;

    do {
        cout << "Enter student records filename: ";
        cin >> studentFilename;
    } while (!FileManager::loadStudents(
    studentFilename,
    studentList
    ));

    cout << "Student records loaded successfully." << endl;

    int choice = 0;

	// Loop until the user chooses menu options 1-4, option 5 exits
    while (choice != 12) {
    displayMenu();
    choice = getValidInteger("");

    switch (choice) {
        case 1:
            campusMap.displayMap();
            break;

        case 2: {
            int row = getValidInteger("Enter row: ");
            int col = getValidInteger("Enter column: ");

            // Convert user coordinates from 1-based to 0-based.
            row--;
            col--;

            if (!campusMap.isValidCoordinate(row, col)) {
                cout << "Invalid map coordinates." << endl;
                break;
            }

            cout << "Location Type: "
                 << campusMap.getLocationType(row, col)
                 << endl;

            cout << "Blocked: "
                 << (campusMap.isBlocked(row, col)
                         ? "Yes"
                         : "No")
                 << endl;

            campusMap.displayNeighbors(row, col);
            break;
        }

        case 3: {
            Student newStudent = getStudentInput();

            if (studentList.addStudent(newStudent)) {
                cout << "Student added successfully." << endl;
            }

            break;
        }

        case 4: {
            int id = getValidStudentID(
                "Enter student ID to remove: "
            );

            if (studentList.removeStudent(id)) {
                cout << "Student removed successfully." << endl;
            } else {
                cout << "Student not found." << endl;
            }

            break;
        }

        case 5: {
            int searchID = getValidStudentID(
                "Enter student ID to search: "
            );

            Student* foundStudent =
                studentList.searchStudent(searchID);

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

        case 6:
            studentList.displayStudents();
            break;

        case 7:
            studentList.sortByID();
            cout << "Students sorted by ID." << endl;
            studentList.displayStudents();
            break;

        case 8: {
            AdvisingRequest request;

            request.studentID = getValidStudentID(
                "Enter student ID: "
            );

            cout << "Enter issue description: ";
            getline(cin, request.issueDescription);

            while (request.issueDescription.empty()) {
                cout << "Issue cannot be empty. Enter issue: ";
                getline(cin, request.issueDescription);
            }

            advisingQueue.addRequest(request);
            break;
        }

        case 9:
            advisingQueue.processNextRequest();
            break;

        case 10:
            advisingQueue.displayPendingRequests();
            break;

        case 11:
            cout << endl;
            cout << "Campus Statistics:" << endl;

            cout << "Total students: "
                 << studentList.getStudentCount()
                 << endl;

            cout << fixed << setprecision(2);

            cout << "Average GPA: "
                 << studentList.getAverageGPA()
                 << endl;

            cout << "Buildings: "
                 << campusMap.countSymbol('B')
                 << endl;

            cout << "Classrooms: "
                 << campusMap.countSymbol('C')
                 << endl;

            cout << "Libraries: "
                 << campusMap.countSymbol('L')
                 << endl;

            cout << "Roads: "
                 << campusMap.countSymbol('R')
                 << endl;

            cout << "Pending advising requests: "
                 << advisingQueue.getPendingCount()
                 << endl;

            break;

        case 12:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter a number from 1 to 12."
                 << endl;
            break;
    }
}

    return 0;
}
