#include "fruit.hpp"

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate)
    : Fruit(name, amount, basePrice, expiryDate, expiryDate) {}

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate, size_t leftTime)
    : Cargo(name, amount, basePrice), timeToSpoil_(expiryDate), leftTime_(leftTime) {}

Fruit& Fruit::operator--() {
    if (leftTime_ > 0) {
        leftTime_--;
    }
    return *this;
}

size_t Fruit::getPrice() const {
    return static_cast<size_t>((static_cast<float>(leftTime_) / static_cast<float>(timeToSpoil_)) * static_cast<float>(basePrice_));
}

bool Fruit::operator==(const Cargo& cargoToCheck) const {
    if (typeid(cargoToCheck) != typeid(Fruit&)) {
        return false;
    }

    auto fruitToCheck = dynamic_cast<const Fruit*>(&cargoToCheck);
    return name_ == fruitToCheck->getName() &&
           amount_ == fruitToCheck->getAmount() &&
           basePrice_ == fruitToCheck->getBasePrice() &&
           leftTime_ == fruitToCheck->getLeftTime() &&
           timeToSpoil_ == fruitToCheck->getTimeToSpoil();
}
