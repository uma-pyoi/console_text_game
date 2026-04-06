#include "../include/GameManager.h"
#include <iostream>
#include "../include/Enemy.h"
#include <random>

GameManager::GameManager(Player &player, Inventory &inventory) : player_(player), inventory_(inventory),
                                                                 fight_manager_(player, inventory) {
}

void GameManager::BranchingPlot0(int user_choice, std::vector<std::string> &plot_choice1,
                                 std::vector<std::string> &plot_choice2) {
    if (user_choice == 1) {
        RunPlotWoChoice(plot_choice1);
        Food egg("Egg", "A very round egg.", 10);
        Enemy nurse("The Nurse", egg, 100);
        fight_manager_.RunFight(nurse, running_);
    } else {
        RunPlotWoChoice(plot_choice2);
        Clothing hospital_gown("Hospital gown", "A blue hospital gown. Makes you weirdly nostalgic.", 3);
        utils_.ObtainItem(hospital_gown, inventory_, player_);
    }
}

void GameManager::BranchingPlot1(int user_choice, std::vector<std::string> &plot_choice1,
                                 std::vector<std::string> &plot_choice2) {
    if (user_choice == 1) {
        RunPlotWoChoice(plot_choice1);
    } else {
        RunPlotWoChoice(plot_choice2);
        Food blood("Droplets of blood", "Rich in iron. Helpful in desperate times.", 5);
        utils_.ObtainItem(blood, inventory_, player_);
    }
}

void GameManager::BranchingPlot2(int user_choice, std::vector<std::string> &plot_choice1,
                                 std::vector<std::string> &plot_choice2) {
    if (user_choice == 1) {
        RunPlotWoChoice(plot_choice1);
    } else {
        RunPlotWoChoice(plot_choice2);
        word_game_.Play(running_);
    }
}

void GameManager::BranchingPlot3(int user_choice, std::vector<std::string> &plot_choice1,
                                 std::vector<std::string> &plot_choice2) {
    if (user_choice == 1) {
        RunPlotWoChoice(plot_choice1);
        Food amazing_cake("Amazing cake", "A cake that's so amazing it feels out of this world.", 99);
        utils_.ObtainItem(amazing_cake, inventory_, player_);
    } else {
        RunPlotWoChoice(plot_choice2);
        Weapon white_sword("White sword", "A massive sword made out of white metal \nand decorated with red laces", 15);
        utils_.ObtainItem(white_sword, inventory_, player_);
    }
}

void GameManager::BranchingPlot4(int user_choice, std::vector<std::string> &plot_choice1,
                                 std::vector<std::string> &plot_choice2) {
    if (user_choice == 1) {
        RunPlotWoChoice(plot_choice1);
    } else {
        RunPlotWoChoice(plot_choice2);
    }
}

void GameManager::BranchingPlot5(int user_choice, std::vector<std::string> &plot_choice1, std::vector<std::string> &plot_choice2) {
    if (user_choice == 1) {
        RunPlotWoChoice(plot_choice1);
        player_.TakeDamage(5);
    } else {
        RunPlotWoChoice(plot_choice2);
        player_.TakeDamage(15);
    }
}

void GameManager::BranchingActivator(int plot_index, int user_choice, std::vector<std::string> &plot_choice1,
                                     std::vector<std::string> &plot_choice2) {
    switch (plot_index) {
        case 0:
            BranchingPlot0(user_choice, plot_choice1, plot_choice2);
            break;
        case 1:
            BranchingPlot1(user_choice, plot_choice1, plot_choice2);
            break;
        case 2:
            BranchingPlot2(user_choice, plot_choice1, plot_choice2);
            break;
        case 3:
            BranchingPlot3(user_choice, plot_choice1, plot_choice2);
            break;
        case 4:
            BranchingPlot4(user_choice, plot_choice1, plot_choice2);
            break;
        case 5:
            BranchingPlot5(user_choice, plot_choice1, plot_choice2);
            break;
    }
}

// reads next story mode character and allows to pause the game
void GameManager::AskIfPause(int &plot_iterator) {
    char continue_choice = input_validator_.ReadStoryModeChar();
    if (continue_choice == 'p') {
        plot_iterator--;
        this->RunPauseScreen();
    }
}

void GameManager::RunPlotWoChoice(std::vector<std::string> &plot) {
    for (int i = 0; i < plot.size(); i++) {
        if (running_) {
            std::cout << plot[i];
            if (i != (plot.size() - 1)) {
                this->AskIfPause(i);
            } else {
                std::cout << "\n\n";
            }
        }
    }
}

// method to run story mode
int GameManager::RunPlotWChoice(std::vector<std::string> &plot) {
    int user_choice{-1}; // -1 means program is exited
    for (int i = 0; i < plot.size(); i++) {
        if (running_) {
            std::cout << plot[i];
            // executes if scene is still going
            if (i != (plot.size() - 1)) {
                this->AskIfPause(i);
            } else {
                // executes if end of scene, starts a fight
                user_choice = input_validator_.ReadPosIntInRange(1, 2);
            }
        }
    }
    std::cout << "\n\n";
    return user_choice;
}

void GameManager::RunStory() {
    utils_.OutputGameTitle();

    // int i = 0;
    int i = 5;
    do {
        std::string plot_num = std::to_string(i);
        std::vector<std::string> plot_text = json_handler_.ReadPlotText(plot_num);
        std::vector<std::string> plot_choice_1 = json_handler_.ReadPlotChoice(plot_num, json_handler_.GetChoice1Name());
        std::vector<std::string> plot_choice_2 = json_handler_.ReadPlotChoice(plot_num, json_handler_.GetChoice2Name());
        int user_choice = RunPlotWChoice(plot_text);
        if (user_choice != -1) {
            BranchingActivator(i, user_choice, plot_choice_1, plot_choice_2);
        }
        i++;
    } while (i <= json_handler_.GetLastPlotNum() && running_);
}

void GameManager::RunPauseScreen() {
    bool run_pause_screen{true};
    do {
        utils_.OutputPauseScreen(this->player_);
        int choice = input_validator_.ReadPosIntInRange(1, 5);
        if (choice == 1) {
            run_pause_screen = false;
        } else if (choice == 2) {
            this->RunInventory();
        } else if (choice == 3) {
            // TODO: implement save game
            std::cout << "Saving game...";
        } else if (choice == 4) {
            // TODO: implement load game
            std::cout << "Loading game...";
        } else if (choice == 5) {
            std::cout << "Are you sure you want to exit the game?" << '\n';
            std::cout << "Any unsaved progress will be lost." << '\n';
            bool confirmed = input_validator_.ReadYesNo();
            if (confirmed) {
                utils_.OutputGameEnd();
                running_ = false;
            }
        }
    } while (run_pause_screen && running_);
}

void GameManager::RunItem(int user_num, std::vector<Food> inventory) {
    int item_index = user_num - 1;
    Food item = inventory[item_index];
    utils_.OutputItemMenu(item);
    int item_choice = input_validator_.ReadPosIntInRange(1, 3);

    if (item_choice == 1) {
        std::cout << item.GetDescription() << '\n';
    } else if (item_choice == 2) {
        ItemEat(item, item_index);
    } else if (item_choice == 3) {
        inventory_.DeleteFoodItem(item_index);
        std::cout << "You threw away " << item.GetName() << "." << '\n';
    }
}

void GameManager::ItemEat(Food item, int item_index) {
    player_.Eat(item.GetHp());
    std::cout << "You ate " << item.GetName() << "! Yummy!" << '\n';
    utils_.OutputStat("HP", std::to_string(player_.GetHp()));
    inventory_.DeleteFoodItem(item_index);
}

void GameManager::RunInventory() {
    bool run_inventory{true};
    do {
        if (inventory_.GetFoodInventory().empty()) {
            std::cout << "Your inventory is empty!" << '\n';
            run_inventory = false;
        } else {
            utils_.OutputInventoryMenu(inventory_);

            std::vector<Food> inventory = inventory_.GetFoodInventory();
            int user_num = input_validator_.ReadPosIntInRange(0, inventory.size());
            if (user_num == 0) {
                run_inventory = false;
            } else {
                RunItem(user_num, inventory);
            }
        }
    } while (run_inventory);
}
