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

void Game::printOptions(){
    std::cout << "\n" << "1) Travel\n" << "2) Sell\n" << "3) Buy\n"
        << "4) Check cargo\n" << "5) Exit\n\n" << "Choice option: ";
}
