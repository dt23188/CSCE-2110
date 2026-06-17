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
};

#endif
