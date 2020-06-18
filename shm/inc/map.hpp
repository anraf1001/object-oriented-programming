#pragma once

#include <vector>

#include "coordinates.hpp"
#include "island.hpp"

class Map {
public:
    Island* getIsland(const Coordinates& coordinate);
    
private:
    std::vector<Island> islands_;
    Island* currentPosition_;
};
