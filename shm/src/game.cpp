#include "game.hpp"

#include "cargo.hpp"
#include "island.hpp"
#include "store.hpp"
#include "globaltime.hpp"


bool Game::checkWinCondition() const {
    return player_->getMoney() >= finalGoal_;
}

bool Game::checkLooseCondition() const {
    return player_->getMoney() == SIZE_MAX;
}
