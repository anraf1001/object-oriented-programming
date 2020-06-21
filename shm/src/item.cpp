#include "item.hpp"

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {}

size_t Item::getPrice() const {
    return basePrice_ * priceMultipliers_.at(rarity_);
}

bool Item::operator==(const Cargo& cargoToCheck) const {
    if (typeid(cargoToCheck) != typeid(Item&)) {
        return false;
    }

    auto itemToCheck = static_cast<const Item*>(&cargoToCheck);
    return name_ == itemToCheck->getName() &&
           amount_ == itemToCheck->getAmount() &&
           basePrice_ == itemToCheck->getBasePrice() &&
           rarity_ == itemToCheck->getRarity();
}
