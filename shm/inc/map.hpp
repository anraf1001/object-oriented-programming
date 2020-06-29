#pragma once

#include <vector>

#include "island.hpp"

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& coordinates);
    Island* getCurrentPosition() const { return currentPosition_; }

private:
    void generateIslands();
    std::vector<Island> islands_;
    Island* currentPosition_;
};
