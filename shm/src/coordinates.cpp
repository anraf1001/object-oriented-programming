#include "inc/coordinates.hpp"

bool Coordinates::operator==(const Coordinates& coordToCheck) {
    return positionX_ == coordToCheck.positionX_ &&
           positionY_ == coordToCheck.positionY_;
}
