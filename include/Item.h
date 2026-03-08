#pragma once

#include <string>

class Item {
    std::string name_;
    std::string description_;
public:
    Item(std::string name, std::string description);

    std::string getName();
    std::string getDescription();
};

