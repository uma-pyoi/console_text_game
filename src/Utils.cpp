#include "../include/Utils.h"
#include <iostream>
#include <random>

void Utils::OutputGameTitle() {
    std::cout << "**++++--    Sakana    --++++**" << "\n\n";
}

void Utils::OutputGameEnd() {
    this->OutputGameTitle();
    std::cout << "       See you next time!       " << "\n\n";
    std::cout << "**++++------------------++++**" << '\n';
}

void Utils::OutputGameover() {
    std::cout << "\n    ✿" << "\n    |" << "\n  R.I.P" ;
    std::cout << "\nGame over." << '\n';
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
    std::cout << "> Choose item (0 to go back)" << '\n';
}

void Utils::OutputDashes() {
    std::cout << "----------------------------------" << '\n';
}

void Utils::OutputStat(std::string stat_name, std::string stat_value) {
    std::cout << stat_name << ": " << stat_value << '\n';
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

void Utils::ObtainClothes(std::variant<Weapon, Clothing, Food> item, Player& player) {
    Clothing new_clothing = std::get<Clothing>(item);
    OutputStat("You got clothing", new_clothing.GetName());
    new_clothing.OutputClothing();

    std::cout << "Current clothing: " << '\n';
    player.GetClothing().OutputClothing();

    std::cout << "\nDo you wish to swap your current clothing to the new one?" << '\n';

    bool user_clothes_choice = input_validator_.ReadYesNo();
    if (user_clothes_choice) {
        player.SetClothing(new_clothing);
        OutputStat("new clothing", new_clothing.GetName());
        std::cout << '\n';
    }
}

void Utils::ObtainWeapon(std::variant<Weapon, Clothing, Food> item, Player& player) {
    Weapon new_weapon = std::get<Weapon>(item);
    OutputStat("You got a weapon", new_weapon.GetName());
    new_weapon.OutputWeapon();

    std::cout << "Current weapon: " << '\n';
    player.GetWeapon().OutputWeapon();

    std::cout << "\nDo you wish to swap your current weapon to the new one?" << '\n';

    bool user_weapon_choice = input_validator_.ReadYesNo();
    if (user_weapon_choice) {
        player.SetWeapon(new_weapon);
        OutputStat("new weapon", new_weapon.GetName());
        std::cout << '\n';
    }
}

void Utils::ObtainItem(std::variant<Weapon, Clothing, Food> item, Inventory& inventory, Player& player) {
    if (std::holds_alternative<Weapon>(item)) {
        ObtainWeapon(item, player);
    }
    else if (std::holds_alternative<Clothing>(item)) {
        ObtainClothes(item, player);
    }
    else if (std::holds_alternative<Food>(item)) {
        Food food = std::get<Food>(item);
        OutputStat("You got food", food.GetName());
        inventory.AddFoodItem(food);
    }
    std::cout << '\n';
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

