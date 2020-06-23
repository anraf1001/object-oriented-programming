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
    //Override from Observer
    void nextDay() override;

protected:
    // override from Cloneable<Cargo>
    Cargo* cloneToRawPointer() override { return new Alcohol(*this); }

private:
    const float power_;
};
