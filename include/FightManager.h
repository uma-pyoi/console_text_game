#ifndef CPP_COURSEWORK1_P479574_FIGHTMANAGER_H
#define CPP_COURSEWORK1_P479574_FIGHTMANAGER_H
#include "Enemy.h"


class FightManager {
    Utils utils_;
    Player& player_;

    // stat multipliers to determine outcome of fights
    int hp_mult_ = 1;
    int ap_mult_ = 3;
    int dp_mult_ = 2;

    // chance to get HP damage at the end of a fight
    int take_dmg_chance_ = 100;

    // limit of damage taken after a fight (in percentage) relative to the player's combined stats
    int dmg_limit_ = 30;

public:
    FightManager(Player& player);

    void RunFight(Enemy& enemy);
    void RunFightWin(Enemy& enemy, int player_stats);
    void RunScoreEarn(Enemy& enemy);
    void RunFightDamage(int player_stats);
    void RunEnemyDropItem(Enemy& enemy);
};


#endif //CPP_COURSEWORK1_P479574_FIGHTMANAGER_H