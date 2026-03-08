#include "../include/Item.h"
#include <string>

Item::Item(std::string name, std::string description) : name_(name), description_(description) {}

std::string Item::getName() {
    return name_;
}

std::string Item::getDescription() {
    return description_;
}
