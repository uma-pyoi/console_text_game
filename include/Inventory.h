#ifndef CPP_COURSEWORK1_P479574_INVENTORY_H
#define CPP_COURSEWORK1_P479574_INVENTORY_H

#include <vector>
#include "Food.h"

class Inventory {
    int inventory_limit_{10};

    // todo: add features to store items other than food
    std::vector<Food> food_inventory_;

public:
    std::vector<Food> GetFoodInventory();
};


#endif //CPP_COURSEWORK1_P479574_INVENTORY_H