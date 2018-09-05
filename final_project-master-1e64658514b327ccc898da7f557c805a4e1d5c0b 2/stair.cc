#include "stair.h"

Stair::Stair(): symbol{'\\'} {}

Stair::getSymbol() {
	return symbol;
}

Stair::getAtk() { return 0;}

Stair::getDef() { return 0;}

Stair::getHp() {return 0;}

Stair::getGold() { return 0;}

Stair::getName() { return "";}

Stair::isTemp() { return false; }

Stair::setItem(Item *item) {}