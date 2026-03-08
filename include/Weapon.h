#pragma once

#include "Item.h"

class Weapon : public Item {
    int ap_{0};
public:
    Weapon(std::string name, std::string description, int ap);
};