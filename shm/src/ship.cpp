#include "ship.hpp"

#include <iostream>
#include <numeric>

Ship::Ship()
    : id_(-1) {}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, unsigned int id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id) {}

Ship::Ship(int maxCrew, int speed, unsigned int id)
    : Ship(0, maxCrew, speed, "", id) {}

Ship& Ship::operator-=(size_t num) {
    if (crew_ > 0) {
        crew_ -= num;
    } else {
        std::cerr << "There is no crew\n";
    }
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    if (crew_ < maxCrew_) {
        crew_ += num;
    } else {
        std::cerr << "You can't have more crew\n";
    }
    return *this;
}

Cargo* Ship::getCargo(size_t index) {
    if (index >= cargo_.size()) {
        std::cerr << "Invalid index\n";
        return nullptr;
    }
    return &cargo_[index];
}

size_t Ship::getAvailableSpace() const {
    size_t reservedSpace = std::accumulate(cargo_.begin(),
                                           cargo_.end(),
                                           0, [](size_t space, const Cargo& cargo) {
                                               return space += cargo.getAmount();
                                           });
    return capacity_ - reservedSpace;
}
