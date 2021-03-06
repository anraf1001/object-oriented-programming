#pragma once

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate);
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate, size_t leftTime);
    ~Fruit() override;

    virtual Fruit& operator--();

    size_t getLeftTime() const { return leftTime_; }

    size_t getTimeToSpoil() const { return timeToSpoil_; }

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getPrice() const override;
    size_t getBasePrice() const override { return basePrice_; }
    std::string oneLineDescription() const override;
    bool operator==(const Cargo& cargoToCheck) const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    std::shared_ptr<Cargo> getShared() override { return std::make_shared<Fruit>(Fruit(*this)); }

    //override from Time::Observer
    void nextDay() override;

private:
    const size_t timeToSpoil_;
    size_t leftTime_ = timeToSpoil_;
};
