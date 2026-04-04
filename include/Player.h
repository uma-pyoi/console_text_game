#ifndef CPP_COURSEWORK1_P479574_PLAYER_H
#define CPP_COURSEWORK1_P479574_PLAYER_H

#include <string>
#include "Clothing.h"
#include "Weapon.h"
#include <vector>
#include <optional>

class Player {
    int hp_limit_ = 100;
    // limit of the smallest HP player can get to by eating bad food
    int hp_bad_food_limit = 1;

    std::string name_;
    int score_ = 0;
    int hp_ = 100;
    int ap_ = 0;
    int dp_ = 0;
    std::string default_empty_equipment_string_{"None"};

    Clothing clothing_ = Clothing("Naked body", "You aren't wearing anything. For some reason the hospital didn't provide you with clothes.", 0);
    Weapon weapon_ = Weapon("Bare hands", "Your hands. Let's hope you are good at fighting", 5);

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

    Clothing GetClothing();
    Weapon GetWeapon();

    void OutputPlayer();
    void TakeDamage(int dmg);
    void AddScorePoints(int score_points);
    void Eat(int food_hp);
};

#endif // CPP_COURSEWORK1_P479574_PLAYER_H


