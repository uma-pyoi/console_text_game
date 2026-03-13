#include "../include/GameManager.h"
#include <iostream>

GameManager::GameManager(Player player) : player_(player) {}

void GameManager::RunStory() {
    for (std::string plotline : plot_0) {
        std::cout << plotline;
        char story_choice = input_validator_.ReadStoryModeChar();
        std::cout << "story_choice: " << story_choice << '\n';
        if (story_choice == 'p') {
            std::cout << "pause!!!!" << '\n';
        }
        else if (story_choice == 'n') {
            std::cout << "continue!!!!" << '\n';
        }
    }
    input_validator_.ReadPosIntInRange(1, 3);
}
