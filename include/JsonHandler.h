#ifndef CPP_COURSEWORK1_P479574_JSONHANDLER_H
#define CPP_COURSEWORK1_P479574_JSONHANDLER_H

#include <string>
#include <vector>
#include "../libs/nlohmann/json.hpp"
using json = nlohmann::json;

class JsonHandler {
private:
    const std::string PLOT_FILENAME_ = "plot.json";

public:
    json ReadJson(std::string filename);
    std::vector<std::string> ReadPlotText(std::string plot_name);
    std::vector<std::string> ReadPlotChoice(std::string plot_name, std::string choice_name);
};


#endif //CPP_COURSEWORK1_P479574_JSONHANDLER_H