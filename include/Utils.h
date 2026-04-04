#ifndef CPP_COURSEWORK1_P479574_UTILS_H
#define CPP_COURSEWORK1_P479574_UTILS_H

#include "Inventory.h"
#include "Player.h"

class Utils {
private:
    int prompt_color_ = 90;
    int stats_color_ = 95;

public:
    // outputting game
    void OutputGameTitle();
    void OutputGameEnd();

    // outputting prompts
    void OutputStoryModePrompt();
    void OutputNumInRangePrompt(int min, int max);

    // outputting pause screen
    void OutputPauseScreen(Player player);
    // outputting inventory
    void OutputInventoryMenu(Inventory inventory);
    void OutputItemMenu(Food item);

    void ObtainItem(std::variant<Weapon, Clothing, Food> item, Inventory& inventory);

    // pretty formatting
    void OutputDashes();
    void OutputMagenta(std::string str); // stats will be magenta
    std::string GetSignedNumString(int num);

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