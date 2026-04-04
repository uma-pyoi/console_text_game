#include "../include/JsonHandler.h"
#include <fstream>
#include "../libs/nlohmann/json.hpp"
using json = nlohmann::json;

int JsonHandler::GetLastPlotNum() {
    return LAST_PLOT_NUM_;
}

std::string JsonHandler::GetChoice1Name() {
    return CHOICE_1_NAME_;
}

std::string JsonHandler::GetChoice2Name() {
    return CHOICE_2_NAME_;
}

json JsonHandler::ReadJson(std::string filename) {
    std::ifstream plot_json_2(filename);
    json data = json::parse(plot_json_2);
    return data;
}

std::vector<std::string> JsonHandler::ReadPlotText(std::string plot_name) {
    json data = ReadJson(PLOT_FILENAME_);
    std::vector<std::string> plot_text = data[plot_name]["text_array"].get<std::vector<std::string>>();
    return plot_text;
}

std::vector<std::string> JsonHandler::ReadPlotChoice(std::string plot_name, std::string choice_name) {
    json data = ReadJson(PLOT_FILENAME_);
    std::vector<std::string> plot_choice = data[plot_name]["branches"][choice_name].get<std::vector<std::string>>();
    return plot_choice;
}
