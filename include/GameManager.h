#ifndef CPP_COURSEWORK1_P479574_GAMEMANAGER_H
#define CPP_COURSEWORK1_P479574_GAMEMANAGER_H

#include "Enemy.h"
#include "Player.h"
#include "InputValidator.h"
#include "Utils.h"
#include "PlotManager.h"

class GameManager {
    Utils utils_;
    InputValidator input_validator_;
    PlotManager plot_manager_;

    Player player_;
    Inventory inventory_;

    bool running_{true};

    // stat multipliers to determine outcome of fights
    int hp_mult_ = 1;
    int ap_mult_ = 3;
    int dp_mult_ = 2;

    // there is a 50% chance to get HP damage at the end of a fight
    int take_dmg_chance_ = 100;

    // limit of damage taken after a fight (in percentage) relative to the player's combined stats
    int dmg_limit_ = 30;

public:
    GameManager(Player player);

    // run game methods
    void RunStory();
    void RunScene(int& plot_iterator);

    void RunPauseScreen();
    void RunInventory();

    void RunFight(Enemy& enemy);
    void RunFightWin(Enemy& enemy, int player_stats);
    void RunFightDamage(int player_stats);
    void RunEnemyDropItem(Enemy& enemy);

    // enemy types
    // Enemy[10] enemies = {};
};


#endif //CPP_COURSEWORK1_P479574_GAMEMANAGER_H