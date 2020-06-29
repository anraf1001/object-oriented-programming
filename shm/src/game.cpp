#include "game.hpp"

#include "cargo.hpp"
#include "globaltime.hpp"
#include "island.hpp"
#include "store.hpp"

const std::string line(80,'=');

Game::Game(size_t money, size_t days, size_t finalGoal)
    : money_(money), days_(days), finalGoal_(finalGoal) {
}

void Game::startGame(){
    std::cout << "Welcome in SHM, you have: " << days_
        << " days, to gain: " << money_ << " HAVE FUN!\n\n";
    
    while(days_ > time_->getElapsedTime()){
        if(checkWinCondition()){
            printWinScreen();
            return;
        }else if(checkLooseCondition()){
            break;
        }
        std::cout << line << "\n";
        printMenu();
        printOptions();
        size_t option;
        std::cin.clear();
        std::cin >> option
        if(option == 0){
            break;
        }
        makeAction(statis_cast<Action>(option));
        system("cls");
    }
    printLooseScreen();
}

bool Game::checkWinCondition() const {
    return player_->getMoney() >= finalGoal_;
}

bool Game::checkLooseCondition() const {
    return player_->getMoney() == SIZE_MAX;
}

void Game::printMenu() {
    std::cout << "Your money: " << player_->getMoney()
              << " Day: " << time_->getElapsedTime()
              << " Days to end: " << days_ - time_->getElapsedTime()
              << " Position: "
              << map_->getIsland->getPosition() << "\n";
}

void Game::printOptions() {
    std::cout << "\n"
              << "1) Travel\n"
              << "2) Sell\n"
              << "3) Buy\n"
              << "4) Check cargo\n"
              << "5) Exit\n\n"
              << "Choice option: ";
}

void Game::printWinScreen() {
    system("cls");
    std::cout << "CONGRATULATION!!! YOU WIN, You earn: " << player_->getMoney()
              << " money in: " << time_->getElapsedTime() << " days";
}

void Game::printLooseScreen() {
    system("cls");
    std::cout << "GAME OVER! You earn: " << player_->getMoney()
              << " money in: " << time_->getElapsedTime() << " days";
}

void Game::makeAction(Action action) {
    switch (action) {
    case Action::Travel:
        travel();
        break;
    case Action::Sell:
        sell();
        break;
    case Action::Buy:
        buy();
        break;
    case Action::checkCargo:
        printCargo();
    default:
        std::cout << "Wrong action!\n";
        break;
    }
}
