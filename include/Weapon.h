#ifndef CPP_COURSEWORK1_P479574_WEAPON_H
#define CPP_COURSEWORK1_P479574_WEAPON_H

#include "Item.h"

class Weapon : public Item {
    int ap_{0};
public:
    Weapon(std::string name, std::string description, int ap);

    int GetAp();
};

#endif // CPP_COURSEWORK1_P479574_WEAPON_H