#include "../include/JsonHandler.h"
#include <fstream>
#include "../libs/nlohmann/json.hpp"
using json = nlohmann::json;

std::vector<std::string> JsonHandler::ReadPlotText(std::string plot_name) {
    std::ifstream plot_json_2(PLOT_FILENAME_);
    json data = json::parse(plot_json_2);

    std::vector<std::string> text_vector = data[plot_name]["text_array"].get<std::vector<std::string>>();
    return text_vector;
}
