#ifndef _Dragon_H
#define _Dragon_H
#include "enemy.h"

class Dragon: public Enemy {
    bool D_hostile = false;
public:
    Dragon();
    virtual bool isHostile();
    void getAngry();
    char getSymbol() override;
};

#endif
