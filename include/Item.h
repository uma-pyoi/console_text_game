#ifndef CPP_COURSEWORK1_P479574_ITEM_H
#define CPP_COURSEWORK1_P479574_ITEM_H

#include <string>

class Item {
    std::string name_;
    std::string description_;
public:
    Item(std::string name, std::string description);

    std::string GetName();
    std::string GetDescription();
};

#endif //CPP_COURSEWORK1_P479574_ITEM_H
