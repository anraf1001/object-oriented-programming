#include "item.hpp"

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {}

size_t Item::getPrice() const {
    return basePrice_ * static_cast<size_t>(rarity_);
}
