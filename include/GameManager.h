#ifndef CPP_COURSEWORK1_P479574_GAMEMANAGER_H
#define CPP_COURSEWORK1_P479574_GAMEMANAGER_H

#include "Enemy.h"
#include "FightManager.h"
#include "Player.h"
#include "InputValidator.h"
#include "Utils.h"
#include "PlotManager.h"

class GameManager {
    // utils
    Utils utils_;
    InputValidator input_validator_;

    // managers
    PlotManager plot_manager_;
    FightManager fight_manager_;

    // entities
    Player player_;
    Inventory inventory_;

    bool running_{true};

public:
    GameManager(Player player);

    // starts the game
    void RunStory();
    // helper story mode functions
    void RunPlotWChoice(std::vector<std::string>& plot, std::vector<std::string>& plot_choice1, std::vector<std::string>& plot_choice2);
    void RunPlotWoChoice(std::vector<std::string>& plot);
    void AskIfPause(int& plot_iterator);

    void RunPauseScreen();
    void RunInventory();
};


#endif //CPP_COURSEWORK1_P479574_GAMEMANAGER_H