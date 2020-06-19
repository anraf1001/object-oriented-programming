#pragma once

#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity { common = 1,
                        rare = 2,
                        epic = 4,
                        legendary = 8 };

    Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity);

    ~Item() override = default;

    Rarity getRarity() const { return rarity_; }

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getPrice() const override;
    size_t getBasePrice() const override { return basePrice_; }

private:
    Rarity rarity_;
};
