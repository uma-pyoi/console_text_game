#ifndef CPP_COURSEWORK1_P479574_GAMEMANAGER_H
#define CPP_COURSEWORK1_P479574_GAMEMANAGER_H

#include "Calculator.h"
#include "Enemy.h"
#include "Player.h"
#include "InputValidator.h"
#include "OutputFormatted.h"

class GameManager {
    OutputFormatted output_formatted_;
    InputValidator input_validator_;

    Player player_;
    Inventory inventory_;

public:
    GameManager(Player player);

    // run game methods
    void RunStory();
    bool RunPauseScreen();
    void RunInventory();
    void RunFight();

    // other methods
    int GenerateRandomIntInRange(int min, int max);

    // enemy types
    // Enemy[10] enemies = {};
};


#endif //CPP_COURSEWORK1_P479574_GAMEMANAGER_H