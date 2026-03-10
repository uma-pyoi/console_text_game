#include "../include/GameManager.h"
#include <iostream>

GameManager::GameManager(Player player) : player_(player) {}

void GameManager::RunStory() {
    for (std::string plotline : plot_0) {
        std::cout << plotline << '\n';
    }
}
