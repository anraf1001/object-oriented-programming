#pragma once

#include <vector>

#include "island.hpp"

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& coordinates);

private:
    std::vector<Island> islands_;
    Island* currentPosition_;
};
