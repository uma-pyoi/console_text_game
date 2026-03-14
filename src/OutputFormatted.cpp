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

void OutputFormatted::OutputPlayerStats(Player player) {
    std::cout << player.GetName() << " | " << "HP: " << player.GetHp() << " | AP: " << player.GetAp() << " | DP: " << player.GetDp() << '\n';

    // REFERENCE: https://www.learncpp.com/cpp-tutorial/stdoptional/
    // Alex (2025)
    std::optional<Weapon> weapon = player.GetWeapon();
    std::string weapon_name = weapon ? weapon->GetName() : default_empty_equipment_string;
    std::cout << "Weapon: " << weapon_name << '\n';

    std::optional<Clothing> clothing = player.GetClothing();
    std::string clothing_name = clothing ? clothing->GetName() : default_empty_equipment_string;
    std::cout << "Clothing: " << clothing_name << '\n';
}

void OutputFormatted::OutputPauseScreen(Player player) {
    std::cout << "\n\n---------   Pause Menu   ---------" << '\n';
    this->OutputPlayerStats(player);
    std::cout << "----------------------------------" << '\n';
    std::cout << "1. Continue" << '\n';
    std::cout << "2. Open Inventory" << '\n';
    std::cout << "3. Save game" << '\n';
    std::cout << "4. Load game" << '\n';
    std::cout << "5. Exit game" << '\n';
    std::cout << "----------------------------------" << '\n';
}

void OutputFormatted::OutputInventory(Inventory inventory) {
    std::vector<Food> food_inventory = inventory.GetFoodInventory();
    std::cout << "\n\n***********   Inventory   ***********\n";
    for (int i = 0; i < food_inventory.size(); i++) {
        std::cout << i + 1 << ". " << food_inventory[i].GetName() << '\n';
    }
    std::cout << "*************************************" << '\n';
}

void OutputFormatted::OutputInventoryMenu(Inventory inventory) {
    OutputInventory(inventory);
    std::cout << "Choose from the following:" << '\n';
    std::cout << "1. Go back" << '\n';
    std::cout << "2. Choose an item" << '\n';
}
