#include "CampusMap.h"
#include <fstream>
#include <iostream>

using namespace std;

CampusMap::CampusMap() {
    rows = 0;
    cols = 0;
}

bool CampusMap::loadMap(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error: Could not open map file." << endl;
        return false;
    }

    inputFile >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Error: Invalid map size." << endl;
        return false;
    }

    campus.clear();
    campus.resize(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inputFile >> campus[i][j];
        }
    }

    inputFile.close();
    return true;
}

void CampusMap::displayMap() const {
    if (campus.empty()) {
        cout << "No campus map loaded." << endl;
        return;
    }

    cout << endl;
    cout << "Campus Map:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << campus[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}
