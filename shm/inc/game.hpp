#pragma once
#include <iostream>

#include "map.hpp"
#include "player.hpp"
#include "time.hpp"

class Game {
public:
    enum class Action {
        Travel = 1,
        Sell = 2,
        Buy = 3
    };

    Game(size_t money, size_t days, size_t finalGoal);
    void startGame();

private:
    bool checkWinCondition() const;
    bool checkLooseCondition() const;
    void printMenu();
    void printOptions();
    void printWinScreen();
    void printLooseScreen();
    void makeAction(Action action);
    void travel();
    void buy();
    void sell();
    void printCargo();

    size_t money_;
    size_t days_;
    size_t finalGoal_;
    size_t currentDay_;
    Map* map_;
    Time* time_;
    Player* player_;
};
