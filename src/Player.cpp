#include "../include/Player.h"
#include <iostream>

Player::Player(std::string name) : name_(name) {}

std::string Player::GetName() {
    return name_;
}

int Player::GetScore() {
    return score_;
}

void Player::SetScore(int score) {
    this->score_ = score;
}

int Player::GetHp() {
    return hp_;
}

void Player::SetHp(int hp) {
    this->hp_ = hp;
}

int Player::GetAp() {
    return weapon_.GetAp();
}

int Player::GetDp() {
    return clothing_.GetDp();
}

Clothing Player::GetClothing() {
    return clothing_;
}

void Player::SetClothing(Clothing clothing) {
    clothing_ = clothing;
}

Weapon Player::GetWeapon() {
    return weapon_;
}

void Player::SetWeapon(Weapon weapon) {
    weapon_ = weapon;
}

void Player::OutputPlayer() {
    std::cout << name_ << " | " << "HP: " << hp_ << " | AP: " << weapon_.GetAp() << " | DP: " << clothing_.GetDp() << '\n';

    std::cout << "Weapon: " << weapon_.GetName() << '\n';
    std::cout << "Clothing: " << clothing_ .GetName() << '\n';
    std::cout << "Score: " << score_ << '\n';
}

void Player::TakeDamage(int dmg) {
    std::cout << "You took " << dmg << " damage!" << '\n';
    int new_hp = hp_ - dmg;
    if (new_hp < 0) {
        hp_ = 0;
    }
    else {
        hp_ = new_hp;
    }
}

void Player::AddScorePoints(int score_points) {
    score_ += score_points;
}

void Player::Eat(int food_hp) {
    int new_hp = hp_ + food_hp;
    if (new_hp > hp_limit_) {
        hp_ = hp_limit_;
    }
    else if (new_hp < 0) {
        hp_ = hp_bad_food_limit;
    }
    else {
        hp_ = new_hp;
    }
}
