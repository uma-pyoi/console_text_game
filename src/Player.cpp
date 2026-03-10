#include "../include/Player.h"

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