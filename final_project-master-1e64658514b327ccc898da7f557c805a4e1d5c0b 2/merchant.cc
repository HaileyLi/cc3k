#include "merchant.h"

Merchant::Merchant(): hp{30}, atk{70}, def{5} {}

static void Merchant::getAngry() {
    M_hostile = true;
}

bool Merchant::isHostile() {
    return M_hostile;
}

char Merchant::getSymbol() { return 'M'; }
