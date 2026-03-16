#include "../include/Inventory.h"
#include <iostream>

std::vector<Food> Inventory::GetFoodInventory() {
    return food_inventory_;
}

void Inventory::OutputInventory() {
    std::cout << "\n\n***********   Inventory   ***********\n";
    for (int i = 0; i < food_inventory_.size(); i++) {
        std::cout << i + 1 << ". " << food_inventory_[i].GetName() << '\n';
    }
    std::cout << "*************************************" << '\n';
}
