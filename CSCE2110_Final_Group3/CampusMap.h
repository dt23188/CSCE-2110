#ifndef CAMPUSMAP_H
#define CAMPUSMAP_H

#include <string>
#include <vector>

class CampusMap {
private:
    std::vector<std::vector<char>> campus;
    int rows;
    int cols;

public:
    CampusMap();

    bool loadMap(const std::string& filename);
    void displayMap() const;
    bool isValidCoordinate(int row, int col) const;
    char getLocationSymbol(int row, int col) const;
    std::string getLocationType(int row, int col) const;
    bool isBlocked(int row, int col) const;
    void displayNeighbors(int row, int col) const;
    int countSymbol(char symbol) const;
};

#endif
