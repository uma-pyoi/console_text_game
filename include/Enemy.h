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

    // items dropped upon defeating the enemy
    std::optional<Weapon> drop_weapon_;
    std::optional<Clothing> drop_clothing_;
    std::optional<Food> drop_food_;

public:
    // different constructors depending on what the enemy drops
    Enemy(std::string name, Weapon weapon, int drop_rate);
    Enemy(std::string name, Clothing clothing, int drop_rate);
    Enemy(std::string name, Food food, int drop_rate);

    void GenerateHpAp();
    void OutputEnemy();
};


#endif //CPP_COURSEWORK1_P479574_ENEMY_H