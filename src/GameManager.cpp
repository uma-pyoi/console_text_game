#include "../include/GameManager.h"
#include <iostream>
#include "../include/Enemy.h"
#include <random>

GameManager::GameManager(Player player) : player_(player), fight_manager_(player) {}

// reads next story mode character and allows to pause the game
void GameManager::AskIfPause(int& plot_iterator) {
    char continue_choice = input_validator_.ReadStoryModeChar();
    if (continue_choice == 'p') {
        plot_iterator--;
        this->RunPauseScreen();
    }
}

void GameManager::RunPlotWoChoice(std::vector<std::string>& plot) {
    for (int i = 0; i < plot.size(); i++) {
        std::cout << plot[i];
        if (i != (plot.size() - 1)) {
            this->AskIfPause(i);
        }
    }
}

// method to run story mode
void GameManager::RunPlotWChoice(std::vector<std::string>& plot, std::vector<std::string>& plot_choice1, std::vector<std::string>& plot_choice2) {
    for (int i = 0; i < plot.size(); i++) {
        if (running_) {
            std::cout << plot[i];

            // executes if scene is still going
            if (i != (plot.size() - 1)) {
                this->AskIfPause(i);
            }
            else { // executes if end of scene, starts a fight
                int plot_choice = input_validator_.ReadPosIntInRange(1, 2);

                if (plot_choice == 1) {
                    RunPlotWoChoice(plot_choice1);
                    Food egg("Egg", "A very round egg.", 10);
                    Enemy nurse("The Nurse", egg, 100);
                    fight_manager_.RunFight(nurse);
                }
                else {
                    RunPlotWoChoice(plot_choice2);
                }
            }
        }
    }
    std::cout << "\n\n";
}

void GameManager::RunStory() {
    utils_.OutputGameTitle();

    int last_plot_num = 1;
    for (int i = 0; i <= last_plot_num; i++) {
        std::string plot_num = std::to_string(i);
        std::vector<std::string> plot_text = json_handler_.ReadPlotText(plot_num);
        std::vector<std::string> plot_choice_1 = json_handler_.ReadPlotChoice(plot_num, "choice_1");
        std::vector<std::string> plot_choice_2 = json_handler_.ReadPlotChoice(plot_num, "choice_2");
        RunPlotWChoice(plot_text, plot_choice_1, plot_choice_2);
    }

}

void GameManager::RunPauseScreen() {
    bool run_pause_screen{true};
    do {
        utils_.OutputPauseScreen(this->player_);
        int choice = input_validator_.ReadPosIntInRange(1, 5);
        if (choice == 1) {
            run_pause_screen = false;
        }
        else if (choice == 2) {
            this->RunInventory();
        }
        else if (choice == 3) {
            // TODO: implement save game
            std::cout << "Saving game...";
        }
        else if (choice == 4) {
            // TODO: implement load game
            std::cout << "Loading game...";
        }
        else if (choice == 5) {
            utils_.OutputGameEnd();
            running_ = false;
        }
    }
    while (run_pause_screen && running_);
}

void GameManager::RunInventory() {
    if (inventory_.GetFoodInventory().size() == 0) {
        std::cout << "Your inventory is empty!" << '\n';
    }
    else {
        bool run_inventory{true};
        do {
            utils_.OutputInventoryMenu(inventory_);
            int choice = input_validator_.ReadPosIntInRange(1, 2);
            if (choice == 1) {
                run_inventory = false;
            }
            else if (choice == 2) {
                std::cout << "Choose the item number." << '\n';
                int item_num = input_validator_.ReadPosIntInRange(1, inventory_.GetFoodInventory().size());
                std::cout << "item num is: " << item_num;
            }
        }
        while (run_inventory);
    }
}

