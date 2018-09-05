#ifndef _STAIR_H
#define _STAIR_H
#include "item.h"

class Stair: public Item{
public:
    Stair();
    virtual char gerSymbol() override; // get the symbol of this item
    virtual int getAtk() override; // get the attack value of this item
    virtual int getDef() override; // get the defense value of this item
    virtual int getHp() override; // get the Hp value of this item
    virtual int getGold() override; // get the gold value of this item
    virtual bool isTemp() override; // get if this item is temporary
    virtual void getName() override; // get the name of this item
    virtual void setItem(Item *item) override; // add a decorator item
};

#endif