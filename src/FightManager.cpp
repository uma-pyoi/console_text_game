#include "../include/FightManager.h"
#include <iostream>

FightManager::FightManager(Player &player) : player_(player) {}

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
        std::cout << "\nHP: " << player_.GetHp() << '\n';
    }
}


void FightManager::RunEnemyDropItem(Enemy& enemy) {
    std::cout << "The enemy dropped an item!" << '\n';
    std::variant<Weapon, Clothing, Food> item = enemy.GetDropItem();
    utils_.OutputItem(item);
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
    else {
        std::cout << "No luck. no item. " << '\n';
    }
}

void FightManager::RunFight(Enemy& enemy) {
    std::cout << "\nYou can feel the enemy approaching you..." << '\n';
    utils_.OutputDashes();

    int enemy_stats = enemy.GetHp() * hp_mult_ + enemy.GetAp() * ap_mult_;
    int player_stats = player_.GetHp() * hp_mult_ + player_.GetAp() * ap_mult_ + player_.GetDp() * dp_mult_;

    if (player_stats > enemy_stats) {
        RunFightWin(enemy, player_stats);
    }
    else {
        // TODO: implement game-over?
        std::cout << "\nGame over." << '\n';
        utils_.OutputDashes();
    }
}
