#ifndef _TREASURE_H
#define _TREASURE_H
#include "decorator.h"

class Treasure: public Decorator{
	int gold;
public:
    Treasure();
    virtual int getAtk() override;
    virtual int getDef() override;
    virtual int getHp() override;
    virtual int getGold() override;
    virtual int getName() override;
    virtual Bool isTemp() override;
    virtual void setItem(Item *item) override;
    char getSymbol() override;
};

#endif
