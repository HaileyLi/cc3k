#include "dragon.h"

Dragon::Dragon(): hp{150}, atk{20}, def{20} {}

static void Dragon::getAngry() {
    D_hostile = true;
}

bool Dragon::isHostile() {
    return D_hostile;
}

char Dragon::getSymbol() { return 'D'; }
