#ifndef CPP_COURSEWORK1_P479574_CLOTHING_H
#define CPP_COURSEWORK1_P479574_CLOTHING_H

#include "Item.h"

class Clothing : public Item {
    int dp_{0};
public:
    Clothing(std::string name, std::string description, int dp);

    int GetDp();
    void OutputClothing();
};


#endif //CPP_COURSEWORK1_P479574_CLOTHING_H
