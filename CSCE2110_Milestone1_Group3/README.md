# CSCE 2110.501 Group Programming Project - Milestone 1

## Project Title
Campus Exploration and Student Resource Management System

## Project Variant
Group 3 - Medical School Campus

## Group Members
- Student 1:
- Student 2:
- Student 3:
- Student 4:

## Description
This Milestone 1 submission includes the beginning version of the campus exploration and student management system for the Group 3 Medical School Campus variant.

Implemented features:
- Campus map loading from an input file
- Campus map display
- Student linked list
- Student insertion
- Student search by ID
- Student display
- Basic menu system
- Multi-file project structure

## Map Symbols
- P = Parking Lot
- R = Road
- B = Building
- C = Classroom
- L = Library
- X = Blocked Area

## Files Included
- main.cpp
- CampusMap.h
- CampusMap.cpp
- StudentList.h
- StudentList.cpp
- FileManager.h
- FileManager.cpp
- campus_map.txt
- students.txt
- README.md

## Compilation Instructions
Use the following command in the terminal:

```bash
g++ *.cpp -o project
```

## Execution Instructions
After compiling, run the program:

```bash
./project
```

On Windows, use:

```bash
project.exe
```

## Input Files
The program asks the user to enter filenames during execution.

Map filename:

```text
campus_map.txt
```

Student filename:

```text
students.txt
```

## Campus Map File Format
The first line contains the number of rows and columns.

```text
6 8
P R B B R R C L
R R R R R B R R
C C R R R R R R
R R B R L R C R
R R R R R R R R
P X R B C R L R
```

## Student File Format
Each student record contains:

```text
studentID name major gpa
```

Current sample records:

```text
3001 Ethan BIO 3.84
3002 Mia MED 3.92
3003 Lucas CHEM 3.21
3004 Harper BIO 3.58
3005 Evelyn MED 3.73
3006 Logan CHEM 3.05
```

## Known Bugs or Limitations
- Student names currently support one word only.
- Student removal is not implemented yet.
- Sorting is not implemented yet.
- Advising queue is not implemented yet.
- Campus location exploration is not implemented yet.
- Campus statistics are not implemented yet.

These features are planned for later milestones.
