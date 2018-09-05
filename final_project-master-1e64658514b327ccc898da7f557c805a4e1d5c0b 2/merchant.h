#ifndef _MERCHANT_H
#define _MERCHANT_H
#include "enemy.h"

class Merchant: public Enemy {
    static bool M_hostile = false;
public:
    Merchant();
    virtual bool isHostile();
    static void getAngry();
    char getSymbol() override;
};

#endif
