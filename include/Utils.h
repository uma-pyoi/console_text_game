#ifndef CPP_COURSEWORK1_P479574_UTILS_H
#define CPP_COURSEWORK1_P479574_UTILS_H

#include "InputValidator.h"
#include "Inventory.h"
#include "Player.h"

class Utils {
private:
    InputValidator input_validator_;

public:
    // outputting game
    void OutputGameTitle();
    void OutputGameEnd();
    void OutputGameover();

    // outputting pause screen
    void OutputPauseScreen(Player player);
    // outputting inventory
    void OutputInventoryMenu(Inventory inventory);
    void OutputItemMenu(Food item);

    void ObtainClothes(std::variant<Weapon, Clothing, Food> item, Player& player);
    void ObtainWeapon(std::variant<Weapon, Clothing, Food> item, Player& player);
    void ObtainItem(std::variant<Weapon, Clothing, Food> item, Inventory& inventory, Player& player);

    // pretty formatting
    void OutputDashes();
    void OutputStat(std::string stat_name, std::string stat_value);
    std::string GetSignedNumString(int num);

    // calculations
    int GenerateRandomIntInRange(int min, int max);
    int CalculateDamage(int player_stats, int dmg_limit, Player& player);
};


#endif //CPP_COURSEWORK1_P479574_UTILS_H