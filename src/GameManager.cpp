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
                    for (int i = 0; i < std::size(plot_manager_.plot_01); i++) {
                        std::cout << plot_manager_.plot_01[i];
                    }
                    Food egg("Egg", "A very round egg.", 10);
                    Enemy nurse("The Nurse", egg, 100);
                    this->RunFight(nurse);
                }
                else {
                    for (int i = 0; i < std::size(plot_manager_.plot_02); i++) {
                        std::cout << plot_manager_.plot_02[i];
                    }
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

void GameManager::RunFightDamage(int player_stats) {
    int dmg = utils_.CalculateDamage(player_stats, dmg_limit_, player_);
    std::cout << "----------------------------------" << '\n';
    std::cout << "During the battle, ";
    if (dmg <= 0) {
        std::cout << "the enemy tried to attack you, \nbut you were too tough for them." << '\n';
    }
    else {
        std::cout << "the enemy dealt its final attack!!!" << '\n';
        std::cout << "You took " << dmg << " damage!" << '\n';
        player_.TakeDamage(dmg);
        std::cout << "\nHP: " << player_.GetHp() << '\n';
    }
}


void GameManager::RunEnemyDropItem(Enemy& enemy) {
    std::cout << "The enemy dropped an item!" << '\n';
    std::variant<Weapon, Clothing, Food> item = enemy.GetDropItem();
    utils_.OutputItem(item);
}

void GameManager::RunFightWin(Enemy& enemy, int player_stats) {
    std::cout << "You defeated " << enemy.GetName() << "!" << '\n';

    bool is_dmg_taken = utils_.GenerateRandomIntInRange(0, 100) <= take_dmg_chance_;
    if (is_dmg_taken) {
        RunFightDamage(player_stats);
    }

    if (enemy.IsDropItemSuccessful()) {
        RunEnemyDropItem(enemy);
    }
    else {
        std::cout << "No luck. no item. " << '\n';
    }
}

void GameManager::RunFight(Enemy& enemy) {
    std::cout << "\nYou can feel the enemy approaching you..." << '\n';

    int enemy_stats = enemy.GetHp() * hp_mult_ + enemy.GetAp() * ap_mult_;
    int player_stats = player_.GetHp() * hp_mult_ + player_.GetAp() * ap_mult_ + player_.GetDp() * dp_mult_;

    if (player_stats > enemy_stats) {
        RunFightWin(enemy, player_stats);
    }
    else {
        // TODO: implement game-over?
        std::cout << "Game over." << '\n';
    }
}
