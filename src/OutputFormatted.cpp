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

void OutputFormatted::OutputItem(std::variant<Weapon, Clothing, Food> item) {
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
