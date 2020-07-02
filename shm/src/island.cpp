#include "island.hpp"

Island::Island(int positionX, int positionY)
    : position_(positionX, positionY) {}

Island::Island(const Island& island)
    : position_(island.getPosition()), store_(island.getStore()) {}
