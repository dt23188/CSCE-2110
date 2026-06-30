# CSCE 2110.501 Group Project - Final Submission

## Project Title

Campus Exploration and Student Resource Management System

## Project Variant

Group 3 - Medical School Campus

## Group Members

* Devin Tiernan
* Evan Matthews
* Julian Gonzalez Delgado
* Kamryn Jones

## Description

This program simulates a small medical school campus system.

The user can load and explore a campus map, manage student records, process advising requests, and view campus statistics.

The project is written in C++ and uses multiple source and header files.

## Features

### Campus Map

* Loads the campus map from a file
* Displays the map
* Allows the user to enter row and column coordinates
* Identifies the type of location
* Checks whether the location is blocked
* Displays neighboring locations
* Counts buildings, classrooms, libraries, and roads

### Student Management

* Stores students in a linked list
* Loads student records from a file
* Adds students
* Removes students
* Searches for students by ID
* Displays all students
* Rejects duplicate student IDs

### Sorting and Searching

* Uses linear search to find students by ID
* Uses bubble sort to sort students by ID
* Does not use built-in sorting functions

### Advising Queue

* Adds advising requests
* Processes requests in first-in, first-out order
* Displays pending requests
* Handles an empty queue

### Statistics

The program displays:

* Total number of students
* Average GPA
* Total number of buildings
* Total number of classrooms
* Total number of libraries
* Total number of roads
* Number of pending advising requests

## Map Symbols

* `P` - Parking Lot
* `R` - Road
* `B` - Building
* `C` - Classroom
* `L` - Library
* `X` - Blocked Area

## Files Included

* `main.cpp`
* `CampusMap.h`
* `CampusMap.cpp`
* `StudentList.h`
* `StudentList.cpp`
* `QueueSystem.h`
* `QueueSystem.cpp`
* `FileManager.h`
* `FileManager.cpp`
* `campus_map.txt`
* `students.txt`
* `README.md`

## Compilation

Open a terminal in the folder containing the project files.

Windows:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o project.exe
```

Linux or macOS:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o project
```

## Running the Program

Windows:

```powershell
.\project.exe
```

Linux or macOS:

```bash
./project
```

The program will ask for the map filename and student filename.

Use:

```text
campus_map.txt
students.txt
```

## Campus Map File Format

The first line contains the number of rows and columns.

Example:

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

Example:

```text
3001 Ethan BIO 3.84
3002 Mia MED 3.92
3003 Lucas CHEM 3.21
3004 Harper BIO 3.58
3005 Evelyn MED 3.73
3006 Logan CHEM 3.05
```

## Data Structures

* Linked list for student records
* Queue for advising requests
* 2D vector for the campus map

## Testing

The program was tested with:

* Invalid filenames
* Invalid menu input
* Duplicate student IDs
* Invalid student searches
* Invalid GPA values
* Invalid map coordinates
* Blocked locations
* Empty student lists
* Empty advising queues
* Multiple advising requests

## Known Limitations

* Student names and majors are currently read as one word.
* Changes made during the program are not saved back to the input files.
* Advising requests are only stored while the program is running.
