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
    try {
        // REFERENCE: https://github.com/nlohmann/json?tab=readme-ov-file#cmake
        // Niels Lohmann (2025)
        std::ifstream file(filename);
        json data = json::parse(file);
        return data;
    }
    catch (const std::exception &e) {
        std::cerr << "An error happened when reading from file." << '\n';
    }
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
    save["player"] = {{"name", player.GetName()}, {"score", player.GetScore()}, {"hp", player.GetHp()}};

    Weapon weapon = player.GetWeapon();
    save["player"]["weapon"] = {{"name", weapon.GetName()}, {"description", weapon.GetDescription()}, {"ap", weapon.GetAp()}};

    Clothing clothing = player.GetClothing();
    save["player"]["clothing"] = {{"name", clothing.GetName()}, {"description", clothing.GetDescription()}, {"dp", clothing.GetDp()}};

    std::vector<Food> foods = inventory.GetFoodInventory();
    for (int i = 0; i < foods.size(); i++) {
        save["food_inventory"][i] = {{"name", foods[i].GetName()}, {"description", foods[i].GetDescription()}, {"hp", foods[i].GetHp()}};
    }

    save["indexes"] = {{"plot_i", plot_i}, {"text_array_i", text_array_i}, {"branch_i", branch_i}};

    try {
        write_file << save.dump(4);
    }
    catch (const std::exception &e) {
        std::cerr << "An error happened when writing to file." << '\n';
    }
    write_file.close();
}

Clothing JsonHandler::LoadClothing(json data) {
    std::string clothing_name = data["player"]["clothing"]["name"];
    std::string clothing_description = data["player"]["clothing"]["description"];
    int clothing_dp = data["player"]["clothing"]["dp"].get<int>();
    Clothing loaded_clothing(clothing_name, clothing_description, clothing_dp);
}

Weapon JsonHandler::LoadWeapon(json data) {
    std::string weapon_name = data["player"]["weapon"]["name"];
    std::string weapon_description = data["player"]["weapon"]["description"];
    int weapon_ap = data["player"]["weapon"]["ap"].get<int>();
    Weapon loaded_weapon(weapon_name, weapon_description, weapon_ap);
    return loaded_weapon;
}

void JsonHandler::LoadPlayer(json data, Player& player) {
    player.SetHp(data["player"]["hp"]);
    player.SetScore(data["player"]["score"]);

    Weapon loaded_weapon = LoadWeapon(data);
    Clothing loaded_clothing = LoadClothing(data);

    player.SetWeapon(loaded_weapon);
    player.SetClothing(loaded_clothing);
}

void JsonHandler::LoadInventory(json data, Inventory &inventory) {
    int inventory_size = data["food_inventory"].size();
    inventory.Clear();
    for (int i = 0; i < inventory_size; i++) {
        std::string name = data["food_inventory"][i]["name"];
        std::string description = data["food_inventory"][i]["description"];
        int hp = data["food_inventory"][i]["hp"];

        Food food(name, description, hp);
        inventory.AddFoodItem(food);
    }
}

void JsonHandler::LoadGame(Player &player, Inventory &inventory) {
    json data = ReadJson(SAVE_FILENAME_);
    LoadPlayer(data, player);
    LoadInventory(data, inventory);
}
