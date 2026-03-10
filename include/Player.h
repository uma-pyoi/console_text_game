#ifndef CPP_COURSEWORK1_P479574_PLAYER_H
#define CPP_COURSEWORK1_P479574_PLAYER_H

#include <string>
#include "Clothing.h"
#include "Weapon.h"
#include "Food.h"
#include <vector>
#include <optional>
#include "Inventory.h"

class Player {
    std::string name_;
    int score_ = 0;
    int hp_ = 0;
    int ap_ = 0;
    int dp_ = 0;

    // REFERENCE: https://en.cppreference.com/w/cpp/utility/optional.html
    // Cppreference (n.d.)
    std::optional<Clothing> clothing_;
    std::optional<Weapon> weapon_;

    Inventory inventory_;

public:
    Player(std::string name);

    std::string GetName();
    int GetScore();
    void SetScore(int score);
    int GetHp();
    void SetHp(int hp);
    int GetAp();
    void SetAp(int ap);
    int GetDp();
    void SetDp(int dp);

    std::optional<Clothing> GetClothing();
    std::optional<Weapon> GetWeapon();
};

#endif // CPP_COURSEWORK1_P479574_PLAYER_H


