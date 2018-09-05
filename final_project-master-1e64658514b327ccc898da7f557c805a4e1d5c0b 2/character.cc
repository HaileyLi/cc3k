#include "character.h"

void Character::setHp(int i) {
    hp += i;
}

bool Character::isDead() {
    return (hp > 0);
}
