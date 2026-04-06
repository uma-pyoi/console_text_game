#ifndef CPP_COURSEWORK1_P479574_INVENTORY_H
#define CPP_COURSEWORK1_P479574_INVENTORY_H

#include <vector>
#include "Food.h"

class Inventory {
    int inventory_limit_{10};

    // todo: add features to store items other than food
    std::vector<Food> food_inventory_ = {
        // Food("Egg", "Delicious egg", 5),
        Food("Apple Pie", "It is looking like it would make you dream.", 25),
        Food("Poop", "Do not eat this!!", -20)
    };

public:
    std::vector<Food> GetFoodInventory();
    void OutputInventory();

    void DeleteFoodItem(int index);
    void AddFoodItem(const Food& food);
    void Clear();
};


#endif //CPP_COURSEWORK1_P479574_INVENTORY_H