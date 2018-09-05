#ifndef _phoenix_H
#define _phoenix_H
#include "enemy.h"

class Phoenix: public Enemy {
public:
    Phoenix();
    char getSymbol() override;
};

#endif