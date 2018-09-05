#include "potion.h"

using namespace std;

Potion::Potion(int hp, int atk, int def, bool temp, std::string name): item{null}, hp{hp}, atk{atk}, def{def}, temp{temp}, name{name} {}

Potion::~Potion() {}

int Potion::getHp() {
    return hp + item->getHp();
}

int Potion::getAtk() {
    return atk + item->getAtk();
}

int Potion::getDef() {
    return def + item->getDef();
}

int Potion::getGold() { return 0; }

int Potion::isTemp() { return temp; }

string Potion::getName() { return name; }

void setItem(Item *i) {
	item = i;
}

char getSymbol(){
    return 'P';
}
//Kind Potion::getKind() {
//	return kind;
//}
