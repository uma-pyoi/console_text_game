#ifndef CPP_COURSEWORK1_P479574_JSONHANDLER_H
#define CPP_COURSEWORK1_P479574_JSONHANDLER_H

#include <string>
#include <vector>
#include "Inventory.h"
#include "Player.h"
#include "../libs/nlohmann/json.hpp"

using json = nlohmann::json;

class JsonHandler {
private:
    // plot constants
    const std::string PLOT_FILENAME_ = "plot.json";
    const int PLOT_NUM_ = 29;
    const std::string CHOICE_1_NAME_ = "choice_1";
    const std::string CHOICE_2_NAME_ = "choice_2";

    // save constants
    const std::string SAVE_FILENAME_ = "save.json";

public:
    int GetPlotNum();
    std::string GetChoice1Name();
    std::string GetChoice2Name();

    // utils
    json ReadJson(std::string filename);

    // plot related
    std::vector<std::string> ReadPlotText(std::string plot_name);
    std::vector<std::string> ReadPlotChoice(std::string plot_name, std::string choice_name);

    // saving
    void SaveGame(Player& player, Inventory& inventory, int plot_i, int text_array_i, int branch_i);
    void SavePlayer(json save, Player& player);
    void SaveInventory(json save, Inventory& inventory);
    // loading
    void LoadGame(Player& player, Inventory& inventory);
    Weapon LoadWeapon(json data);
    Clothing LoadClothing(json data);
    void LoadPlayer(json data, Player& player);
    void LoadInventory(json data, Inventory& inventory);
};


#endif //CPP_COURSEWORK1_P479574_JSONHANDLER_H