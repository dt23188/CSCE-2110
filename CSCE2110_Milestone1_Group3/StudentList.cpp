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
    } else {
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

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
