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
}

void Player::TakeDamage(int dmg) {
    hp_ = hp_ - dmg;
}

