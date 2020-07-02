#pragma once

#include <vector>

#include "island.hpp"

class Map {
public:
    Map();

    void travel(Island* destination);

    Island* getIsland(const Coordinates& coordinates);
    Island* getCurrentPosition() const { return currentPosition_; }

    friend std::ostream& operator<<(std::ostream& out, const Map& map);

private:
    void generateIslands();
    std::vector<Island> islands_;
    Island* currentPosition_;
};
