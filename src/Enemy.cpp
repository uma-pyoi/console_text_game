#include "../include/Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy(std::string name, Clothing clothing, int drop_rate) : name_(name), drop_clothing_(clothing), drop_rate_(drop_rate) {
    this->GenerateHpAp();
}

Enemy::Enemy(std::string name, Food food, int drop_rate) : name_(name), drop_food_(food), drop_rate_(drop_rate) {
    this->GenerateHpAp();
}

Enemy::Enemy(std::string name, Weapon weapon, int drop_rate) : name_(name), drop_weapon_(weapon), drop_rate_(drop_rate) {
    this->GenerateHpAp();
}
void Enemy::GenerateHpAp() {
    hp_ = this->calculator_.GenerateRandomIntInRange(1, 100);
    ap_ = this->calculator_.GenerateRandomIntInRange(1, 100);
}

void Enemy::OutputEnemy() {
    std::cout << "name: " << name_ << "\nhp: " << hp_ << "\nap: " << ap_ << '\n';
}
