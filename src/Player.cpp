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
    return ap_;
}

void Player::SetAp(int ap) {
    this->ap_ = ap;
}

int Player::GetDp() {
    return dp_;
}

void Player::SetDp(int dp) {
    this->dp_ = dp;
}

std::optional<Clothing> Player::GetClothing() {
    return clothing_;
}

std::optional<Weapon> Player::GetWeapon() {
    return weapon_;
}

void Player::OutputPlayer() {
    std::cout << name_ << " | " << "HP: " << hp_ << " | AP: " << ap_ << " | DP: " << dp_ << '\n';

    // REFERENCE: https://www.learncpp.com/cpp-tutorial/stdoptional/
    // Alex (2025);
    std::string weapon_name = weapon_ ? weapon_->GetName() : default_empty_equipment_string_;
    std::cout << "Weapon: " << weapon_name << '\n';

    std::string clothing_name = clothing_ ? clothing_->GetName() : default_empty_equipment_string_;
    std::cout << "Clothing: " << clothing_name << '\n';

    std::cout << "Score: " << score_ << '\n';
}

void Player::TakeDamage(int dmg) {
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
        hp_ = 0;
    }
    else {
        hp_ = new_hp;
    }
}
