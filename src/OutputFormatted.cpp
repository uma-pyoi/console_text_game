#include "../include/OutputFormatted.h"
#include <iostream>

void OutputFormatted::OutputGameTitle() {
    std::cout << "**++++--    Sakana    --++++**" << "\n\n";
}

void OutputFormatted::OutputGameEnd() {
    this->OutputGameTitle();
    std::cout << "       See you next time!       " << "\n\n";
    std::cout << "**++++------------------++++**" << '\n';
}

void OutputFormatted::OutputStoryModePrompt() {
    std::cout << "Enter 'n' to continue, 'p' to pause: ";
}

void OutputFormatted::OutputPauseScreen(Player player) {
    std::cout << "\n\n---------   Pause Menu   ---------" << '\n';
    player.OutputPlayer();
    std::cout << "----------------------------------" << '\n';
    std::cout << "1. Continue" << '\n';
    std::cout << "2. Open Inventory" << '\n';
    std::cout << "3. Save game" << '\n';
    std::cout << "4. Load game" << '\n';
    std::cout << "5. Exit game" << '\n';
    std::cout << "----------------------------------" << '\n';
}

void OutputFormatted::OutputInventoryMenu(Inventory inventory) {
    inventory.OutputInventory();
    std::cout << "Choose from the following:" << '\n';
    std::cout << "1. Go back" << '\n';
    std::cout << "2. Choose an item" << '\n';
}
