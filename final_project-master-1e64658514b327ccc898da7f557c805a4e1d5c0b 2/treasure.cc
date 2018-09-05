#include "treasure.h"

using namespace std;

Treasure::Treasure() {}

int Treasure:: getGold() {
	return gold;
}

Treasure::Treasure() {}

int Treasure::getHp() {
    return 0; 
}

int Treasure::getAtk() {
    return 0;
}

int Treasure::getDef() {
    return 0;
}

bool Treasure::isTemp() {
	return false;
}

string Treasure::getName() {
	return name;
}

void Treasure::setItem(Item *item) {}

char Treasure::getSymbol(){
    return 'G';
}
