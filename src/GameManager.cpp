#include "../include/GameManager.h"
#include <iostream>
#include "../include/Enemy.h"

GameManager::GameManager(Player player) : player_(player) {}

void GameManager::RunStory() {
    bool running{true};
    for (int i = 0; i < std::size(plot_0); i++) {
        if (running) {
            std::cout << plot_0[i];

            if (i != (std::size(plot_0) - 1)) {
                char continue_choice = input_validator_.ReadStoryModeChar();
                if (continue_choice == 'p') {
                    running = this->RunPauseScreen();
                }
            }
            else {
                int plot_choice = input_validator_.ReadPosIntInRange(1, 2);
                std::cout << "user_choice: " << plot_choice << '\n';
                if (plot_choice == 1) {
                    std::cout << "AAaa!! bad choice! u get attacked by an enemy now" << '\n';
                    // Food onigiri("Onigiri", "A japanese treat", 10);
                    // Weapon black_dagger("Black Dagger", "The infamous dagger of the Black Assassin", 15);
                    Clothing hospital_gown("Hospital Gown", "A gown you found yourself in upon waking up", 1);
                    Enemy rice_shower("Rice Shower", hospital_gown, 100);
                    rice_shower.OutputEnemy();

                    std::cout << "Let's pretend you defeated the enemy..." << '\n';
                    bool success = rice_shower.IsDropItemSuccessful();
                    if (success) {
                        std::cout << "Congrats! you get ur item! " << success << '\n';
                        std::variant<Weapon, Clothing, Food> item = rice_shower.GetDropItem();

                        // REFERENCE: https://www.geeksforgeeks.org/cpp/std-variant-in-cpp-17/
                        // Geeksforgeeks (2023)
                        if (std::holds_alternative<Weapon>(item)) {
                            std::cout << "You got a weapon! " << std::get<Weapon>(item).GetName() << '\n';
                        }
                        else if (std::holds_alternative<Clothing>(item)) {
                            std::cout << "You got armour! " << std::get<Clothing>(item).GetName() << '\n';
                        }
                        else if (std::holds_alternative<Food>(item)) {
                            std::cout << "You got food! " << std::get<Food>(item).GetName() << '\n';
                        }
                    }
                    else {
                        std::cout << "No luck. no item. " << success << '\n';
                    }



                }
            }
        }
        else {

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
