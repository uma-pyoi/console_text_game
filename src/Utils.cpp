#include "../include/Utils.h"
#include <iostream>
#include <random>

void Utils::OutputGameTitle() {
    SetColor(93);
    std::cout << "**++++--    Sakana    --++++**" << "\n\n";
    ResetColor();
}

void Utils::OutputGameEnd() {
    this->OutputGameTitle();
    SetColor(93);
    std::cout << "       See you next time!       " << "\n\n";
    std::cout << "**++++------------------++++**" << '\n';
    ResetColor();
}

void Utils::OutputStoryModePrompt() {
    // SetColor(93);
    // std::cout << "Enter 'n' to continue, 'p' to pause: " << '\n';
    // ResetColor();
    SetColor(93);
    std::cout << "**++++--    Sakana    --++++**" << "\n\n";
    ResetColor();
}

void Utils::OutputPauseScreen(Player player) {
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

void Utils::OutputInventoryMenu(Inventory inventory) {
    inventory.OutputInventory();
    std::cout << "Choose from the following:" << '\n';
    std::cout << "1. Go back" << '\n';
    std::cout << "2. Choose an item" << '\n';
}

void Utils::OutputDashes() {
    std::cout << "----------------------------------" << '\n';
}

void Utils::OutputItem(std::variant<Weapon, Clothing, Food> item) {
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

int Utils::GenerateRandomIntInRange(int min, int max) {
    // REFERENCE: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution.html
    // Cppreference.com (n.d.)
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(generator);
}

int Utils::CalculateDamage(int player_stats, int dmg_limit, Player& player) {
    int random_dmg_percent = GenerateRandomIntInRange(0, 100);
    int player_stats_w_limit = player_stats * dmg_limit / 100; // dmg_limit_% of player stats
    return random_dmg_percent * player_stats_w_limit / 100 - player.GetDp(); // calculated dmg
}

void Utils::SetColor(int text_color) {
    std::cout << "\033[" << text_color << "m";
}

void Utils::ResetColor() {
    std::cout << "\033[0m";
}

