#ifndef CPP_COURSEWORK1_P479574_FOOD_H
#define CPP_COURSEWORK1_P479574_FOOD_H

#include "Item.h"

class Food : public Item {
    int hp_{0};
public:
    Food(std::string name, std::string description, int hp);
};

#endif //CPP_COURSEWORK1_P479574_FOOD_H
