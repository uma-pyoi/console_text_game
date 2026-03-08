#include <iostream>
#include <string>
#include "../include/Item.h"
#include "../include/Food.h"


int main() {
    Item i{"Item", "cool item."};
    Food egg{"Egg", "A delicious egg. Wait and maybe it will hatch?", 5};
    std::cout << i.getName() << "item desc: " << i.getDescription() << '\n';
    std::cout << egg.getName() << "egg desc: " << egg.getDescription() << '\n';

    return 0;
}