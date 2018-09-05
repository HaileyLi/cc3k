#include <iostream>
#include "combat.h"
#include "character.h"

using namespace std;

Combat::Combat(Character *attacker, Character *defender): 
attacker{attacker}, attackerHP{attacker->getHp()}, defender{defender}, defenderHP{defender->getHp()} {}

Combat::~Combat() {
	if (defender->isDead()) delete defender;
}

void Combat::fight() {
	defender->bestruckBy(*attacker);
	if (defender->isDead()) {
		attacker->setGold(1);
		return;
	}
	int attackChance = rand() % 100;
	if (attackChance >= 50) {
		attacker->bestruckBy(*defender);
	}
}

ostream &operator<<(ostream &out, Combat &c) {
	out << "PC deals " << c.defenderHP - c.defender->getHp() << " damage to ";
	out << c.defender->getSymbol() << ". (" << c.defender->getHp() << " HP). ";
	if (c.defender->getHp() == 0) {
		out << c.defender->getSymbol() << " is defeated. PC gets 1 gold." << endl;
	} else {
		out << c.defender->getSymbol() << " deals " << c.attackerHP - c.attacker->getHp();
		out << " damage to PC." << endl;
	}
	return out;	
}
