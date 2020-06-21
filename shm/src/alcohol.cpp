#include "alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice)
    : Alcohol(name, amount, basePrice, kBasePower) {}

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, float power)
    : Cargo(name, amount, basePrice), power_(power) {}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(static_cast<float>(basePrice_) * (power_ / kBasePower));
}

bool Alcohol::operator==(const Cargo& cargoToCheck) const {
    if (typeid(cargoToCheck) != typeid(Alcohol&)) {
        return false;
    }

    auto alcoToCheck = dynamic_cast<const Alcohol*>(&cargoToCheck);
    return name_ == alcoToCheck->getName() &&
           amount_ == alcoToCheck->getAmount() &&
           basePrice_ == alcoToCheck->getBasePrice() &&
           power_ == alcoToCheck->getPower();
}
