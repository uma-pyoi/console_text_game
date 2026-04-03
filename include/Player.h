#ifndef CPP_COURSEWORK1_P479574_PLAYER_H
#define CPP_COURSEWORK1_P479574_PLAYER_H

#include <string>
#include "Clothing.h"
#include "Weapon.h"
#include <vector>
#include <optional>

class Player {
    std::string name_;
    int score_ = 0;
    int hp_ = 100;
    int ap_ = 5;
    int dp_ = 0;
    std::string default_empty_equipment_string_{"None"};

    // REFERENCE: https://en.cppreference.com/w/cpp/utility/optional.html
    // Cppreference (n.d.)
    std::optional<Clothing> clothing_;
    std::optional<Weapon> weapon_;

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

    void OutputPlayer();
    void TakeDamage(int dmg);
    void AddScorePoints(int score_points);
};

#endif // CPP_COURSEWORK1_P479574_PLAYER_H


