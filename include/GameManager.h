#ifndef CPP_COURSEWORK1_P479574_GAMEMANAGER_H
#define CPP_COURSEWORK1_P479574_GAMEMANAGER_H

#include "Player.h"
#include "Printer.h"
#include "InputValidator.h"

class GameManager {
    Printer printer_;
    InputValidator input_validator_;

    Player player_;


    std::string plot_0_[10];
};


#endif //CPP_COURSEWORK1_P479574_GAMEMANAGER_H