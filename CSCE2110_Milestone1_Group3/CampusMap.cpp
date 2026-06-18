#include "CampusMap.h" //Includes the CampusMap class definition
#include <fstream> //Allows file input/output
#include <iostream> //Allows input/output using cout

using namespace std;
// Constructor for CampusMap
CampusMap::CampusMap() {
    rows = 0; //Initializes number of rows to 0
    cols = 0; //Initializes number of columns to 0
}
// Loads the campus map from a file
bool CampusMap::loadMap(const string& filename) {
    ifstream inputFile(filename); //Opens the file using the given filename
    //Checks if the file could not be opened
    if (!inputFile) {
        cout << "Error: Could not open map file." << endl;
        return false; //Returns false because loading failed
    }

    inputFile >> rows >> cols; //Reads the number of rows and columns from the file
    //Checks if the map size is invalid
    if (rows <= 0 || cols <= 0) {
        cout << "Error: Invalid map size." << endl;
        return false; //Returns false because the size is not valid
    }

    campus.clear(); //Clears any existing map data
    campus.resize(rows, vector<char>(cols)); //Resizes the campus map based on rows and columns
    //Reads each character from the file into the campus map
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inputFile >> campus[i][j]; //Stores the map character at the current row and column
        }
    }

    inputFile.close(); //Closes the file
    return true; //Returns true because the map loaded successfully
}
//Displays the campus map
void CampusMap::displayMap() const {
    if (campus.empty()) { //Checks if no map has been loaded
        cout << "No campus map loaded." << endl;
        return; //Stops the function if there is no map to display
    }

    cout << endl;
    cout << "Campus Map:" << endl; //Prints the map title
    // Loops through each row of the campus map
    for (int i = 0; i < rows; i++) { // Loops through each column of the campus map
        for (int j = 0; j < cols; j++) {
            cout << campus[i][j] << " "; //Prints each map character with a space
        }
        cout << endl; //Moves to the next line after each row
    }

    cout << endl;
}
