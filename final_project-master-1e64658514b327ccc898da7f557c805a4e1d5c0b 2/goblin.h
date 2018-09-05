#ifndef _goblin_H
#define _goblin_H
#include "enemy.h"

class Goblin: public Enemy {
public:
    Goblin();
    char getSymbol() override;
};

#endif
