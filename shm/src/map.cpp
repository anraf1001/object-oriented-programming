#include "map.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <utility>

constexpr size_t kIslandAmt = 10;
constexpr size_t kMapWidth = 50;
constexpr size_t kMapHeight = 50;

Map::Map() {
    generateIslands();
    currentPosition_ = &islands_.front();
}

void Map::travel(Island* destination) {
    currentPosition_ = destination;
}

Island* Map::getIsland(const Coordinates& coordinates) {
    auto island = std::find_if(islands_.begin(), islands_.end(),
                               [&](const auto& island) {
                                   return coordinates == island.getPosition();
                               });
    return island != std::end(islands_) ? &*island : nullptr;
}

void Map::generateIslands() {
    std::random_device rd;
    std::mt19937 eng(rd());
    islands_.reserve(kIslandAmt);

    std::vector<unsigned int> positionsX(kMapWidth);
    std::vector<unsigned int> positionsY(kMapHeight);

    std::iota(positionsX.begin(), positionsX.end(), 0);
    std::iota(positionsY.begin(), positionsY.end(), 0);

    std::shuffle(positionsX.begin(), positionsX.end(), eng);
    std::shuffle(positionsY.begin(), positionsY.end(), eng);

    std::transform(positionsX.begin(), positionsX.end(),
                   positionsY.begin(),
                   std::back_inserter(islands_),
                   [](auto x, auto y) {
                       return Island(x, y);
                   });
}

std::ostream& operator<<(std::ostream& out, const Map& map) {
    out << "Islands that you can choose:\n";
    out << "-----------------------------\n";
    std::for_each(map.islands_.begin(), map.islands_.end(),
                  [&, counter{1}](const auto& island) mutable {
                      if (island.getPosition() != map.currentPosition_->getPosition()) {
                          out << counter++ << ") Coordinates: ";
                          out << island.getPosition();
                          out << " Distance: "
                              << Coordinates::distance(map.currentPosition_->getPosition(), island.getPosition()) << '\n';
                      }
                  });
    out << "-----------------------------\n";
    return out;
}
