#pragma once

#include "Item.h"

class Clothing : public Item {
    int dp_{0};
public:
    Clothing(std::string name, std::string description, int dp);
};

