#ifndef CPP_COURSEWORK1_P479574_UTILS_H
#define CPP_COURSEWORK1_P479574_UTILS_H

#include "Inventory.h"
#include "Player.h"

class Utils {
private:
    int prompt_color_ = 90;
    int stats_color_ = 95;

public:
    // outputting
    void OutputGameTitle();
    void OutputGameEnd();
    void OutputStoryModePrompt();
    void OutputNumInRangePrompt(int min, int max);
    void OutputPauseScreen(Player player);
    void OutputInventoryMenu(Inventory inventory);
    void OutputDashes();
    void OutputStat(std::string stat_name, int stat_value);

    void OutputItem(std::variant<Weapon, Clothing, Food> item);

    // calculations
    int GenerateRandomIntInRange(int min, int max);
    int CalculateDamage(int player_stats, int dmg_limit, Player& player);

    // color
    // REFERENCE: https://www.geeksforgeeks.org/cpp/how-to-change-console-color-in-cpp/
    // Geeksforgeeks (2024)
    void SetColor(int textColor);
    void ResetColor();
};


#endif //CPP_COURSEWORK1_P479574_UTILS_H