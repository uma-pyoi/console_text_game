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

void Utils::OutputGameover() {
    SetColor(91);
    std::cout << "\n    ✿" << "\n    |" << "\n  R.I.P" ;
    std::cout << "\nGame over." << '\n';
    ResetColor();
}

void Utils::OutputStoryModePrompt() {
    SetColor(prompt_color_);
    std::cout << "\n\nEnter 'n' to continue, 'p' to pause: ";
    ResetColor();
}

void Utils::OutputNumInRangePrompt(int min, int max) {
    SetColor(prompt_color_);
    std::cout << "\n\n" << "Enter a number (" << min << "-" << max << "): ";
    ResetColor();
}

void Utils::OutputYesNoPrompt() {
    SetColor(prompt_color_);
    std::cout << "\n\nEnter Y/N: ";
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
    SetColor(prompt_color_);
    std::cout << "Choose item (0 to go back):" << '\n';
    ResetColor();
}

void Utils::OutputDashes() {
    std::cout << "----------------------------------" << '\n';
}

void Utils::OutputStat(std::string stat_name, std::string stat_value) {
    SetColor(stats_color_);
    std::cout << "\n" << stat_name << ": " << stat_value << '\n';
    ResetColor();
}

std::string Utils::GetSignedNumString(int num) {
    std::string signed_num;
    if (num > 0) {
        signed_num = "+" + std::to_string(num);
    }
    else {
        signed_num = std::to_string(num);
    }
    return signed_num;
}

void Utils::OutputItemMenu(Food item) {
    std::cout << "> " << item.GetName() << " (" << GetSignedNumString(item.GetHp()) << " HP)" << '\n';
    std::cout << "1. View description" << '\n';
    std::cout << "2. Eat" << '\n';
    std::cout << "3. Throw away" << '\n';
}

void Utils::ObtainItem(std::variant<Weapon, Clothing, Food> item, Inventory& inventory, Player& player) {
    // REFERENCE: https://www.geeksforgeeks.org/cpp/std-variant-in-cpp-17/
    // Geeksforgeeks (2023)
    if (std::holds_alternative<Weapon>(item)) {
        OutputStat("You got a weapon", std::get<Weapon>(item).GetName());
    }
    else if (std::holds_alternative<Clothing>(item)) {
        Clothing new_clothing = std::get<Clothing>(item);
        std::string new_clothing_dp = GetSignedNumString(new_clothing.GetDp());

        OutputStat("You got clothing", new_clothing.GetName());
        new_clothing.OutputClothing();

        std::cout << "Do you wish to swap your current clothing to it?" << '\n';


        std::string curr_clothing_dp = GetSignedNumString(player.GetClothing().GetDp());
        std::cout << "Current clothing: " << player.GetClothing().GetName() << '\n';

    }
    else if (std::holds_alternative<Food>(item)) {
        Food food = std::get<Food>(item);
        OutputStat("You got food", food.GetName());
        inventory.AddFoodItem(food);
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

