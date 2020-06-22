#include "player.hpp"

#include <iostream>

Player::Player(Ship& ship, size_t money, size_t availableSpace)
    : ship_(std::make_unique<Ship>(ship)), money_(money), availableSpace_(availableSpace) {}

void Player::changeMoney(size_t amount) {
    if (amount < (-1) * money_) {
        std::cerr << "Can't subtract more money than player has (" << amount << " from " << money_ << ')';
        return;
    }
    money_ += amount;
}
