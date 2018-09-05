#include "player.h"

using namespace std;

Player::Player() {}

Player::~Player() {
    delete item;
}

void Player::strike(Character &e) {
    int dmg = ceiling((dmgcoe / (dmgcoe + e.getDef())) * getAtk());
    e.setHp(-dmg);
}

void Player::bestruckBy(Character &e) {
    e.strike(*this);
}

void Player::setHp(int i) {
    hp += i;
}

void Player::setGold(int i) {
    gold += i;
}

int Player::getGold() {
    return gold;
}

int Player::getHp() {
    return hp;
}

int Player::getAtk() {
    int retval = item->getAtk();
    return retval;
}

int Player::getDef() {
    int retval = item->getDef();
    return retval;
}

void Player::usePotion(Item &p) {
    string kind = p.getName();
    if (kind == "RH" || kind == "PH") {
        setHp(p.getHp());
        delete &p;
    } else {
        p.setItem(item);
        item = p;
    }
}

void Player::useTreasure(Item &p) {
    int i = p.getGold();
    setGold(i);
    delete &p;
}

void Player::takeoff_temp() {
    delete item;
    item = new Playerinfo{hp, atk, def, gold};
}

void Player::setAction() {}
