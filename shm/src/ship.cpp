#include "ship.hpp"

#include <iostream>
#include <numeric>

Ship& Ship::operator-=(size_t num) {
    crew_ -= num;
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    crew_ += num;
    return *this;
}

Cargo* Ship::getCargo(size_t index) {
    if (index < cargo_.size()) {
        return &cargo_[index];
    }
    return nullptr;
}

size_t Ship::getAvailableSpace() const {
    size_t reservedSpace = std::accumulate(cargo_.begin(),
                                           cargo_.end(),
                                           0, [](size_t space, const Cargo& cargo) {
                                               return space += cargo.getAmount();
                                           });

    size_t availableSpace = capacity_ - reservedSpace;

    return availableSpace;
}
