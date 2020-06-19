#include "alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice)
    : Alcohol(name, amount, basePrice, kBasePower) {}

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t power)
    : Cargo(name, amount, basePrice), power_(power) {}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>((float)basePrice_ * (power_ / kBasePower));
}
