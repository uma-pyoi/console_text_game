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
