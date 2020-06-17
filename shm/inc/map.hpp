#pragma once

#include <vector>

#include "island.hpp"

class Map {
private:
    std::vector<Island> island_;
    Island* currentPosition_;
};
