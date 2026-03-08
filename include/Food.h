#pragma once

#include "Item.h"

class Food : public Item {
    int hp_{0};
public:
    Food(std::string name, std::string description, int hp);
};

