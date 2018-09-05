#include "playerinfo.h"

Playerinfo::Player_info(int hp, int atk, int def, int gold): hp{hp}, atk{atk}, 
def{def} {}

int Playerinfo::getGold() { return gold; }

int Playerinfo::getHp() { return hp; }

int Playerinfo::getDef() { return def; }

int Playerinfo::getAtk() { return atk; }