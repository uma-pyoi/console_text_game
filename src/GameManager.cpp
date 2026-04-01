#include "../include/GameManager.h"
#include <iostream>
#include "../include/Enemy.h"
#include <random>

GameManager::GameManager(Player player) : player_(player) {}

void GameManager::RunScene(int& plot_iterator) {
    char continue_choice = input_validator_.ReadStoryModeChar();
    if (continue_choice == 'p') {
        plot_iterator--;
        this->RunPauseScreen();
    }
}

// method to run story mode
void GameManager::RunStory() {
    for (int i = 0; i < std::size(plot_manager_.plot_0); i++) {
        if (running_) {
            std::cout << plot_manager_.plot_0[i];

            // executes if scene is still going
            if (i != (std::size(plot_manager_.plot_0) - 1)) {
                this->RunScene(i);
            }
            else { // executes if end of scene, starts a fight
                int plot_choice = input_validator_.ReadPosIntInRange(1, 2);
                std::cout << "user_choice: " << plot_choice << '\n';
                if (plot_choice == 1) {
                    this->RunFight();
                }
            }
        }
    }
    std::cout << "end of game";
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

void GameManager::RunFight() {
    std::cout << "AAaa!! bad choice! u get attacked by an enemy now" << '\n';
    Food onigiri("Onigiri", "A japanese treat", 10);
    Enemy rice_shower("Rice Shower", onigiri, 100);
    rice_shower.OutputEnemy();
    player_.OutputPlayer();

    int enemy_stats = rice_shower.GetHp() * hp_mult_ + rice_shower.GetAp() * ap_mult_;
    int player_stats = player_.GetHp() * hp_mult_ + player_.GetAp() * ap_mult_ + player_.GetDp() * dp_mult_;

    std::cout << "enemy_stats: " << enemy_stats << '\n';
    std::cout << "player_stats: " << player_stats << '\n';

    if (player_stats > enemy_stats) {
        std::cout << "YOU SURVIVED!!" << '\n';
        if (bool success = rice_shower.IsDropItemSuccessful()) {
            std::cout << "Congrats! you get ur item! " << success << '\n';
            std::variant<Weapon, Clothing, Food> item = rice_shower.GetDropItem();
            utils_.OutputItem(item);
        }
        else {
            std::cout << "No luck. no item. " << success << '\n';
        }
    }
    else {
        std::cout << "Game over." << '\n';
    }
}
