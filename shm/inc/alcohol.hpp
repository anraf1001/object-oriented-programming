#pragma once

#include "cargo.hpp"

namespace {
constexpr auto kBasePower = 96.f;
}

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice);
    Alcohol(const std::string& name, size_t amount, size_t basePrice, float power);
    ~Alcohol() override;

    float getPower() const { return power_; }

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getPrice() const override;
    size_t getBasePrice() const override { return basePrice_; }
    std::string oneLineDescription() const override;
    bool operator==(const Cargo& cargoToCheck) const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    std::shared_ptr<Cargo> getShared() override { return std::make_shared<Alcohol>(Alcohol(*this)); }

    //Override from Time::Observer
    void nextDay() override;

private:
    const float power_;
};
