#include "StudentList.h"
#include <iostream>

using namespace std;

StudentList::StudentList() {
    head = nullptr;
}

StudentList::~StudentList() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

bool StudentList::addStudent(Student student) {
    if (searchStudent(student.id) != nullptr) {
        cout << "Error: A student with this ID already exists." << endl;
        return false;
    }

    Node* newNode = new Node;
    newNode->data = student;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    return true;
}

bool StudentList::removeStudent(int id) {
    if (head == nullptr) {
        return false;
    }

    if (head->data.id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;

    while (current->next != nullptr &&
        current->next->data.id != id) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    return true;
}

Student* StudentList::searchStudent(int id) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data.id == id) {
            return &current->data;
        }

        current = current->next;
    }

    return nullptr;
}

void StudentList::displayStudents() const {
    if (head == nullptr) {
        cout << "No students in the list." << endl;
        return;
    }

    Node* current = head;

    cout << endl;
    cout << "Student Records:" << endl;

    while (current != nullptr) {
        cout << "ID: " << current->data.id << endl;
        cout << "Name: " << current->data.name << endl;
        cout << "Major: " << current->data.major << endl;
        cout << "GPA: " << current->data.gpa << endl;
        cout << "------------------------" << endl;

        current = current->next;
    }
}

void StudentList::sortByID() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool swapped;

    do {
        swapped = false;
        Node* current = head;

        while (current->next != nullptr) {
            if (current->data.id > current->next->data.id) {
                Student temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = true;
            }

            current = current->next;
        }
    } while (swapped);
}

int StudentList::getStudentCount() const {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

double StudentList::getAverageGPA() const {
    if (head == nullptr) {
        return 0.0;
    }

    double totalGPA = 0.0;
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        totalGPA += current->data.gpa;
        count++;
        current = current->next;
    }

    return totalGPA / count;
}
