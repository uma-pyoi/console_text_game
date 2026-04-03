#ifndef CPP_COURSEWORK1_P479574_UTILS_H
#define CPP_COURSEWORK1_P479574_UTILS_H

#include "Inventory.h"
#include "Player.h"

class Utils {
public:
    // outputting
    void OutputGameTitle();
    void OutputGameEnd();
    void OutputStoryModePrompt();
    void OutputPauseScreen(Player player);
    void OutputInventoryMenu(Inventory inventory);

    void OutputItem(std::variant<Weapon, Clothing, Food> item);

    // calculations
    int GenerateRandomIntInRange(int min, int max);
    int CalculateDamage(int player_stats, int dmg_limit, Player& player);
};


#endif //CPP_COURSEWORK1_P479574_UTILS_H