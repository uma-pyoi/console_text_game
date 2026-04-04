#ifndef CPP_COURSEWORK1_P479574_JSONHANDLER_H
#define CPP_COURSEWORK1_P479574_JSONHANDLER_H

#include <string>
#include <vector>
#include "../libs/nlohmann/json.hpp"
using json = nlohmann::json;

class JsonHandler {
private:
    // constants
    const std::string PLOT_FILENAME_ = "plot.json";
    const int LAST_PLOT_NUM_ = 1;
    const std::string CHOICE_1_NAME_ = "choice_1";
    const std::string CHOICE_2_NAME_ = "choice_2";

public:
    int GetLastPlotNum();
    std::string GetChoice1Name();
    std::string GetChoice2Name();

    json ReadJson(std::string filename);
    std::vector<std::string> ReadPlotText(std::string plot_name);
    std::vector<std::string> ReadPlotChoice(std::string plot_name, std::string choice_name);
};


#endif //CPP_COURSEWORK1_P479574_JSONHANDLER_H