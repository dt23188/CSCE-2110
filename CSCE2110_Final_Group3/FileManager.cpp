#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

FileManager::FileManager() {
    head = nullptr;
    tail = nullptr;
}

FileManager::~FileManager() {
    clear();
}

void FileManager::clear() {
    FileNode* current = head;

    while (current != nullptr) {
        FileNode* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
}

void FileManager::addLine(const string& line) {
    FileNode* newNode = new FileNode(line);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

bool FileManager::loadFile(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error: Could not open file: " << filename << endl;
        return false;
    }

    clear();

    string line;
    while (getline(inputFile, line)) {
        addLine(line);
    }

    inputFile.close();
    return true;
}

bool FileManager::saveFile(const string& filename) const {
    ofstream outputFile(filename);

    if (!outputFile) {
        cout << "Error: Could not save file: " << filename << endl;
        return false;
    }

    FileNode* current = head;

    while (current != nullptr) {
        outputFile << current->data << endl;
        current = current->next;
    }

    outputFile.close();
    return true;
}

void FileManager::displayLines() const {
    FileNode* current = head;

    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

// Load student records from a file into the provided StudentList.
// Expected format per line: <id> <name> <major> <gpa>
bool FileManager::loadStudents(const string& filename, StudentList& list) {
    ifstream input(filename);

    if (!input) {
        cout << "Error: Could not open student file: " << filename << endl;
        return false;
    }

    // Clear existing students in the list
    Node* currentNode = list.head;
    while (currentNode != nullptr) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    list.head = nullptr;

    string line;
    while (getline(input, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        Student s;

        if (!(iss >> s.id >> s.name >> s.major >> s.gpa)) {
            cout << "Warning: Malformed student record in file: " << line << endl;
            continue;
        }

        list.addStudent(s);
    }

    input.close();
    return true;
}

// Save student records from the provided StudentList to a file.
bool FileManager::saveStudents(const string& filename, const StudentList& list) const {
    ofstream output(filename);

    if (!output) {
        cout << "Error: Could not save student file: " << filename << endl;
        return false;
    }

    Node* current = list.head;
    while (current != nullptr) {
        output << current->data.id << " "
               << current->data.name << " "
               << current->data.major << " "
               << current->data.gpa << endl;
        current = current->next;
    }

    output.close();
    return true;
}
