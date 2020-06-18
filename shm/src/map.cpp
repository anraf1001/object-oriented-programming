#include "map.hpp"

#include <algorithm>
#include <random>
#include <set>
#include <utility>

constexpr size_t kIslandAmt = 10;
constexpr size_t kMapWidth = 50;
constexpr size_t kMapHeight = 50;

Map::Map() {
    generateIslands();
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
    /*************************1*****************************/

    std::uniform_int_distribution<> width_gen(0, kMapWidth);
    std::uniform_int_distribution<> height_gen(0, kMapHeight);

    std::set<std::pair<int, int>> unique_islands;
    int x = 0;
    int y = 0;
    while (unique_islands.size() < kIslandAmt) {
        x = width_gen(eng);
        y = height_gen(eng);

        unique_islands.insert({x, y});
    }
    std::transform(unique_islands.begin(), unique_islands.end(),
                   std::back_inserter(islands_),
                   [](const auto& coords) {
                       return Island(coords.first, coords.second);
                   });

    /************************2******************************/
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
