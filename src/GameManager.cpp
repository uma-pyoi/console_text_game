#include "../include/GameManager.h"
#include <iostream>
#include "../include/Enemy.h"
#include <random>

GameManager::GameManager(Player player) : player_(player) {}

void GameManager::RunStory() {
    bool running{true};
    for (int i = 0; i < std::size(plot_0); i++) {
        if (running) {
            std::cout << plot_0[i];

            if (i != (std::size(plot_0) - 1)) { // executes if scene is still going
                char continue_choice = input_validator_.ReadStoryModeChar();
                if (continue_choice == 'p') {
                    running = this->RunPauseScreen();
                }
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

bool GameManager::RunPauseScreen() {
    bool run_pause_screen{true};
    bool run_game{true};
    do {
        output_formatted_.OutputPauseScreen(this->player_);
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
            output_formatted_.OutputGameEnd();
            run_game = false;
        }
    }
    while (run_pause_screen && run_game);
    return run_game;
}

void GameManager::RunInventory() {
    if (inventory_.GetFoodInventory().size() == 0) {
        std::cout << "Your inventory is empty!" << '\n';
    }
    else {
        bool run_inventory{true};
        do {
            output_formatted_.OutputInventoryMenu(inventory_);
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

int GameManager::GenerateRandomIntInRange(int min, int max) {
    // REFERENCE: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution.html
    // Cppreference.com (n.d.)
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(generator);
}

void GameManager::RunFight() {
    std::cout << "AAaa!! bad choice! u get attacked by an enemy now" << '\n';
    Food onigiri("Onigiri", "A japanese treat", 10);
    Enemy rice_shower("Rice Shower", onigiri, 100);
    rice_shower.OutputEnemy();

    std::cout << "Let's pretend you defeated the enemy..." << '\n';
    bool success = rice_shower.IsDropItemSuccessful();
    if (success) {
        std::cout << "Congrats! you get ur item! " << success << '\n';
        std::variant<Weapon, Clothing, Food> item = rice_shower.GetDropItem();
        output_formatted_.OutputItem(item);
    }
    else {
        std::cout << "No luck. no item. " << success << '\n';
    }
}
