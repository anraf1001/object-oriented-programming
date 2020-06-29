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

void Game::printMenu(){
    std::cout << "Your money: " << player_->getMoney()
        << " Day: " << time_->getElapsedTime()
        << " Days to end: " << days_ - time_->getElapsedTime()
        << " Position: "
        << map_->getIsland->getPosition() << "\n";
}
