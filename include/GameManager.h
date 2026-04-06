#ifndef CPP_COURSEWORK1_P479574_GAMEMANAGER_H
#define CPP_COURSEWORK1_P479574_GAMEMANAGER_H

#include "Enemy.h"
#include "FightManager.h"
#include "Player.h"
#include "InputValidator.h"
#include "JsonHandler.h"
#include "Utils.h"
#include "PlotManager.h"
#include "WordGame.h"

class GameManager {
    // utils
    Utils utils_;
    InputValidator input_validator_;
    JsonHandler json_handler_;

    // managers
    PlotManager plot_manager_;
    FightManager fight_manager_;
    WordGame word_game_;

    // entities
    Player &player_;
    Inventory &inventory_;

    bool running_{true};

public:
    GameManager(Player &player, Inventory &inventory_);

    // starts the game
    void RunStory();

    // branching functions
    void BranchingActivator(int plot_index, int user_choice, std::vector<std::string> &plot_choice1,
                            std::vector<std::string> &plot_choice2);
    void BranchingPlot0(int user_choice, std::vector<std::string> &plot_choice1,
                        std::vector<std::string> &plot_choice2);
    void BranchingPlot1(int user_choice, std::vector<std::string> &plot_choice1,
                        std::vector<std::string> &plot_choice2);
    void BranchingPlot2(int user_choice, std::vector<std::string> &plot_choice1,
                        std::vector<std::string> &plot_choice2);
    void BranchingPlot3(int user_choice, std::vector<std::string> &plot_choice1,
                        std::vector<std::string> &plot_choice2);
    void BranchingPlot4(int user_choice, std::vector<std::string> &plot_choice1,
                        std::vector<std::string> &plot_choice2);
    void BranchingPlot5(int user_choice, std::vector<std::string> &plot_choice1,
                        std::vector<std::string> &plot_choice2);

    // helper story mode functions
    int RunPlotWChoice(std::vector<std::string> &plot);
    void RunPlotWoChoice(std::vector<std::string> &plot);
    void AskIfPause(int &plot_iterator);

    // pause screen related
    void RunPauseScreen();
    void RunItem(int user_num, std::vector<Food> inventory);
    void ItemEat(Food item, int item_index);
    void RunInventory();
};


#endif //CPP_COURSEWORK1_P479574_GAMEMANAGER_H
