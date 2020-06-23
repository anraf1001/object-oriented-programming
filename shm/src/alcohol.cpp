#include "alcohol.hpp"

#include "globaltime.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice)
    : Alcohol(name, amount, basePrice, kBasePower) {
    GlobalTime::getGlobalTime()->addObserver(this);
}

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, float power)
    : Cargo(name, amount, basePrice), power_(power) {}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(static_cast<float>(basePrice_) * (power_ / kBasePower));
}

void Alcohol::nextDay() {
    return;
}

Alcohol::~Alcohol() {
    GlobalTime::getGlobalTime()->removeObserver(this);
}
