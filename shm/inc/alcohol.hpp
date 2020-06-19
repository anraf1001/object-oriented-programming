#pragma once

#include "cargo.hpp"

namespace {
constexpr size_t BASE_POWER = 96;
}

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice);
    Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t power);
    ~Alcohol() override = default;

    size_t getPower() const { return power_; }

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getPrice() const override;
    size_t getBasePrice() const override { return basePrice_; }

private:
    const size_t power_;
};
