#include "../include/Clothing.h"
#include <iostream>

Clothing::Clothing(std::string name, std::string description, int dp) : Item(name, description), dp_(dp) {}

int Clothing::GetDp() {
    return dp_;
}

void Clothing::OutputClothing() {
    std::cout << "> " << GetName() << " | DP: " << dp_ << '\n';
    std::cout << GetDescription() << "\n\n";
}
