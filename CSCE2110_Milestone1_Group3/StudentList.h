#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>

struct Student {
    int id;
    std::string name;
    std::string major;
    float gpa;
};

struct Node {
    Student data;
    Node* next;
};

class StudentList {
private:
    Node* head;

public:
    StudentList();
    ~StudentList();

    bool addStudent(Student student);
    Student* searchStudent(int id);
    void displayStudents() const;
};

#endif
