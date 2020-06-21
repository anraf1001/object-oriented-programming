#include "map.hpp"

#include <algorithm>
#include <random>
#include <set>
#include <utility>

constexpr size_t kIslandAmt = 10;
constexpr size_t kMapWidth = 50;
constexpr size_t kMapHeight = 50;

Map::Map() {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distribX(0, kMapWidth - 1);
    std::uniform_int_distribution<> distribY(0, kMapHeight - 1);

    islands_.resize(kIslandAmt);
    std::generate(islands_.begin(), islands_.end(), [&]() { return Island(distribX(eng), distribY(eng)); });
}

Island* Map::getIsland(const Coordinates& coordinates) {
    auto island = std::find_if(islands_.begin(), islands_.end(),
                               [&](const auto& island) {
                                   return coordinates == island.getPosition();
                               });
    return island != std::end(islands_) ? &*island : nullptr;
}
