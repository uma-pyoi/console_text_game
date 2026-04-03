#ifndef CPP_COURSEWORK1_P479574_JSONHANDLER_H
#define CPP_COURSEWORK1_P479574_JSONHANDLER_H

#include <string>
#include <vector>

class JsonHandler {
private:
    const std::string PLOT_FILENAME_ = "plot.json";

public:
    std::vector<std::string> ReadPlotText(std::string plot_name);
};


#endif //CPP_COURSEWORK1_P479574_JSONHANDLER_H