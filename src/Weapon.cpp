#include "../include/Weapon.h"
#include <iostream>

Weapon::Weapon(std::string name, std::string description, int ap) : Item(name, description), ap_(ap) {}

int Weapon::GetAp() {
    return ap_;
}

void Weapon::OutputWeapon() {
    std::cout << "> " << GetName() << " | AP: " << ap_ << '\n';
    std::cout << GetDescription() << "\n";
}
