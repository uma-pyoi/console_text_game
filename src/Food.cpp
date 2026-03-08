#include "../include/Food.h"

Food::Food(std::string name, std::string description, int hp) : Item{name, description}, hp_(hp) {}