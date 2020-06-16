#pragma once

#include "coordinates.hpp"

class Island {
public:
    Coordinates getPosition() { return position_; }

private:
    Coordinates position_;
};
