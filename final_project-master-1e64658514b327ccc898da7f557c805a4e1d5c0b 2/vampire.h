#ifndef _Vampire_H_
#define _Vampire_H_
#include "enemy.h"

class Vampire: public Enemy {
public:
    Vampire();
    char getSymbol() override;
};

#endif
