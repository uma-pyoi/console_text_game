#include "../include/Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy(std::string name, std::variant<Weapon, Clothing, Food> drop_item, int drop_rate) : name_(name), drop_item_(drop_item), drop_rate_(drop_rate) {
    this->GenerateHpAp();
}

void Enemy::GenerateHpAp() {
    hp_ = this->calculator_.GenerateRandomIntInRange(1, 100);
    ap_ = this->calculator_.GenerateRandomIntInRange(1, 100);
}

void Enemy::OutputEnemy() {
    std::cout << "name: " << name_ << "\nhp: " << hp_ << "\nap: " << ap_ << '\n';
}

bool Enemy::IsDropItemSuccessful() {
    bool success{false};
    int random_num = calculator_.GenerateRandomIntInRange(1, 100);
    if (random_num <= drop_rate_) {
        success = true;
    }
    return success;
}

std::variant<Weapon, Clothing, Food> Enemy::GetDropItem() {
    return this->drop_item_;
}
