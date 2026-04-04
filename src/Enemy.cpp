#include "../include/Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy(std::string name, std::variant<Weapon, Clothing, Food> drop_item, int drop_rate) : name_(name), drop_item_(drop_item), drop_rate_(drop_rate) {
    GenerateHpAp();
}

int Enemy::GetHp() {
    return hp_;
}

int Enemy::GetAp() {
    return ap_;
}

std::string Enemy::GetName() {
    return name_;
}

int Enemy::GetScorePoints() {
    return (ap_ + hp_) * score_points_mult_;
}

void Enemy::GenerateHpAp() {
    hp_ = utils_.GenerateRandomIntInRange(1, 100);
    ap_ = utils_.GenerateRandomIntInRange(1, ap_limit_);
}

void Enemy::OutputEnemy() {
    std::cout << name_ << " | HP: " << hp_ << " | AP: " << ap_ << '\n';
}

bool Enemy::IsDropItemSuccessful() {
    bool success{false};
    int random_num = utils_.GenerateRandomIntInRange(0, 100);
    if (random_num <= drop_rate_) {
        success = true;
    }
    return success;
}

std::variant<Weapon, Clothing, Food> Enemy::GetDropItem() {
    return this->drop_item_;
}
