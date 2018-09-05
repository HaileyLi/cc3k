#include "enemy.h"
#include "item.h"
#include "floor.h"
#include <cmath>

using namespace std;

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::strike(Character &e) {
    int dmg = ceil((dmgcoe / (dmgcoe + e.getDef())) * getAtk());
    e.setHp(-dmg);
    action = true;
}

void Enemy::bestruckBy(Character &e) {
    e.strike(*this);
}

void Enemy::setGold(int i) {}

int Enemy::getGold() {
    return 0;
}

int Enemy::getHp() {
    return hp;
}

int Enemy::getAtk() {
    return atk;
}

int Enemy::getDef() {
    return def;
}

void Enemy::usePotion(Item &p) {}

void Enemy::useTreasure(Item &p) {}

void Enemy::takeoff_temp() {}

bool Enemy::isHostile() {
    return true;
}

void Enemy::setInRange(bool in) {
    inRange = in;
}

char Enemy::getSymbol() { return 'e';}

bool Enemy::isInRange() {
    return inRange;
}

void Enemy::setAction(bool f) {
    action = f;
}

bool Enemy::isAction() {
    return action;
}
