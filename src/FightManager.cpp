#include "../include/FightManager.h"
#include <iostream>

FightManager::FightManager(Player& player, Inventory& inventory) : player_(player), inventory_(inventory) {}

void FightManager::RunFightDamage(int player_stats) {
    int dmg = utils_.CalculateDamage(player_stats, dmg_limit_, player_);
    utils_.OutputDashes();
    std::cout << "During the battle, ";
    if (dmg <= 0) {
        std::cout << "the enemy tried to attack you, \nbut you were too tough for them." << '\n';
    }
    else {
        std::cout << "the enemy dealt its final attack!!!" << '\n';
        std::cout << "You took " << dmg << " damage!" << '\n';
        player_.TakeDamage(dmg);
        utils_.OutputStat("HP", std::to_string(player_.GetHp()));
    }
}

void FightManager::RunScoreEarn(Enemy& enemy) {
    utils_.OutputDashes();
    int score_points = enemy.GetScorePoints();
    std::cout << "You earned " << score_points << " score points!" << '\n';
    player_.AddScorePoints(score_points);
    utils_.OutputStat("score", std::to_string(player_.GetScore()));
    utils_.OutputDashes();
}

void FightManager::RunEnemyDropItem(Enemy& enemy) {
    utils_.OutputDashes();
    std::cout << "The enemy dropped an item!" << '\n';
    std::variant<Weapon, Clothing, Food> item = enemy.GetDropItem();
    utils_.ObtainItem(item, inventory_, player_);
}

void FightManager::RunFightWin(Enemy& enemy, int player_stats) {
    std::cout << "You defeated " << enemy.GetName() << "!" << '\n';

    bool is_dmg_taken = utils_.GenerateRandomIntInRange(0, 100) <= take_dmg_chance_;
    if (is_dmg_taken) {
        RunFightDamage(player_stats);
    }

    if (enemy.IsDropItemSuccessful()) {
        RunEnemyDropItem(enemy);
    }

    RunScoreEarn(enemy);
}

void FightManager::RunFight(Enemy& enemy, bool& running) {
    std::cout << "\nYou can feel the enemy approaching you..." << '\n';
    enemy.OutputEnemy();
    utils_.OutputDashes();

    int enemy_stats = enemy.GetHp() * hp_mult_ + enemy.GetAp() * ap_mult_;
    int player_stats = player_.GetHp() * hp_mult_ + player_.GetAp() * ap_mult_ + player_.GetDp() * dp_mult_;

    if (player_stats > enemy_stats) {
        RunFightWin(enemy, player_stats);
    }
    else {
        // TODO: implement game-over?
        std::cout << "The enemy was too tough for you to handle." << '\n';
        utils_.OutputGameover();
        utils_.OutputDashes();
        running = false;
    }
}
