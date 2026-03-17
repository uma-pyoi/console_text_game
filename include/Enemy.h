#ifndef CPP_COURSEWORK1_P479574_ENEMY_H
#define CPP_COURSEWORK1_P479574_ENEMY_H

#include <string>

#include "Calculator.h"
#include "Clothing.h"
#include "Food.h"
#include "Weapon.h"

class Enemy {
    std::string name_;
    int hp_;
    int ap_;
    int drop_rate_;
    Calculator calculator_;

    // item dropped upon defeating the enemy
    std::variant<Weapon, Clothing, Food> drop_item_;
public:
    Enemy(std::string name, std::variant<Weapon, Clothing, Food>, int drop_rate);

    void GenerateHpAp();
    void OutputEnemy();
    bool IsDropItemSuccessful();
    std::variant<Weapon, Clothing, Food> GetDropItem();
};


#endif //CPP_COURSEWORK1_P479574_ENEMY_H