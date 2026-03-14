#include "../include/GameManager.h"
#include <iostream>

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
                int user_choice = input_validator_.ReadPosIntInRange(1, 2);
                std::cout << "user_choice: " << user_choice << '\n';
            }
        }
        else {

        }
    }
    std::cout << "end of game";
}

bool GameManager::RunPauseScreen() {
    bool continue_pause_screen{true};
    bool continue_game{true};
    do {
        output_formatted_.OutputPauseScreen(this->player_);
        int choice = input_validator_.ReadPosIntInRange(1, 5);
        if (choice == 1) {
            continue_pause_screen = false;
        }
        else if (choice == 2) {
            output_formatted_.OutputInventoryMenu(inventory_);
            int inventory_choice = input_validator_.ReadPosIntInRange(1, 2);
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
            continue_game = false;
        }
    }
    while (continue_pause_screen && continue_game);
    return continue_game;
}
