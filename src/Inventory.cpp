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

void Inventory::DeleteFoodItem(int index) {
    food_inventory_.erase(food_inventory_.begin() + index);
}

void Inventory::AddFoodItem(const Food& food) {
    food_inventory_.push_back(food);
}

void Inventory::Clear() {
    food_inventory_.clear();
}
