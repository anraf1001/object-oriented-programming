#pragma once

#include <memory>
#include <vector>

#include "cargo.hpp"

class Ship {
public:
    Ship();

    Ship(int capacity, int maxCrew, int speed, const std::string& name, unsigned int id);

    Ship(int maxCrew, int speed, unsigned int id);

    void setName(const std::string& name) { name_ = name; }

    size_t getCapacity() const { return capacity_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    int getId() const { return id_; }

    std::shared_ptr<Cargo> getCargo(size_t index);
    size_t getAvailableSpace() const;

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    void load(const std::shared_ptr<Cargo>& cargo);
    void unload(const Cargo* const& cargo);

private:
    std::vector<std::shared_ptr<Cargo>> cargo_;
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const int id_;
};
