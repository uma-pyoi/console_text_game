#include "../include/Item.h"
#include <string>

Item::Item(std::string name, std::string description) : name_(name), description_(description) {}

std::string Item::GetName() {
    return name_;
}

std::string Item::GetDescription() {
    return description_;
}
