#include "../include/Weapon.h"

Weapon::Weapon(std::string name, std::string description, int ap) : Item(name, description), ap_(ap) {}
