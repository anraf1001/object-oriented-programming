#include "map.hpp"

#include <algorithm>
Island* Map::getIsland(const Coordinates& coordinate) {
    return &*(std::find_if(islands_.begin(), islands_.end(),
                           [&](const auto& el) {
                               return coordinate == el.getPosition();
                           }));
}
