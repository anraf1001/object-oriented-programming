#include "item.hpp"
#include "globaltime.hpp"

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {
        GlobalTime::getGlobalTime()->addObserver(this);
    }

size_t Item::getPrice() const {
    return basePrice_ * priceMultipliers_.at(rarity_);
}

void Item::nextDay(){
    return;
}

Item::~Item(){
    GlobalTime::getGlobalTime()->removeObserver(this);
}