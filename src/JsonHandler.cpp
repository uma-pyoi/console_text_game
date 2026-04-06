#include "../include/JsonHandler.h"
#include <fstream>
#include "../libs/nlohmann/json.hpp"
#include <iostream>
using json = nlohmann::json;

int JsonHandler::GetPlotNum() {
    return PLOT_NUM_;
}

std::string JsonHandler::GetChoice1Name() {
    return CHOICE_1_NAME_;
}

std::string JsonHandler::GetChoice2Name() {
    return CHOICE_2_NAME_;
}

json JsonHandler::ReadJson(std::string filename) {
    // REFERENCE: https://github.com/nlohmann/json?tab=readme-ov-file#cmake
    // Niels Lohmann (2025)
    std::ifstream file(filename);
    json data = json::parse(file);
    return data;
}

std::vector<std::string> JsonHandler::ReadPlotText(std::string plot_name) {
    json data = ReadJson(PLOT_FILENAME_);
    std::vector<std::string> plot_text = data[plot_name]["text_array"].get<std::vector<std::string> >();
    return plot_text;
}

std::vector<std::string> JsonHandler::ReadPlotChoice(std::string plot_name, std::string choice_name) {
    json data = ReadJson(PLOT_FILENAME_);
    std::vector<std::string> plot_choice = data[plot_name]["branches"][choice_name].get<std::vector<std::string> >();
    return plot_choice;
}

void JsonHandler::SaveGame(Player &player, Inventory &inventory, int plot_i, int text_array_i, int branch_i) {
    std::ofstream write_file(SAVE_FILENAME_);
    json save;
    save["player"] = {{"name", player.GetName()}, {"score", player.GetScore()}, {"hp", player.GetHp()}, {"ap", player.GetAp()}, {"dp", player.GetDp()}};

    Weapon weapon = player.GetWeapon();
    save["player"]["weapon"] = {{"name", weapon.GetName()}, {"description", weapon.GetDescription()}, {"ap", weapon.GetAp()}};

    Clothing clothing = player.GetClothing();
    save["player"]["clothing"] = {{"name", clothing.GetName()}, {"description", clothing.GetDescription()}, {"dp", clothing.GetDp()}};

    write_file << save.dump(4);
    write_file.close();

    json data = ReadJson(SAVE_FILENAME_);
    std::cout << data;
}
