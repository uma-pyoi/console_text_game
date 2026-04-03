#ifndef CPP_COURSEWORK1_P479574_ENEMY_H
#define CPP_COURSEWORK1_P479574_ENEMY_H

#include <string>
#include "Clothing.h"
#include "Food.h"
#include "Weapon.h"
#include "Utils.h"

class Enemy {
    std::string name_;
    int hp_;
    int ap_;
    int drop_rate_;

    int ap_limit = 10;

    Utils utils_;

    // item dropped upon defeating the enemy
    std::variant<Weapon, Clothing, Food> drop_item_;
public:
    Enemy(std::string name, std::variant<Weapon, Clothing, Food> drop_item, int drop_rate);

    int GetHp();
    int GetAp();
    std::string GetName();

    void GenerateHpAp();
    void OutputEnemy();
    bool IsDropItemSuccessful();
    std::variant<Weapon, Clothing, Food> GetDropItem();
};


#endif //CPP_COURSEWORK1_P479574_ENEMY_H