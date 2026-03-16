//
// Created by Assem Yeleussiz on 16/03/2026.
//

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
    // REFERENCE: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution.html
    // Cppreference.com (n.d.)
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(1, 100);
    hp_ = distribution(generator);
    ap_ = distribution(generator);
}

void Enemy::OutputEnemy() {
    std::cout << "name: " << name_ << "\nhp: " << hp_ << "\nap: " << ap_ << '\n';
}
