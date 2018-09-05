#ifndef __p_info_H__
#define __p_info_H__
#include <iostream>
#include <string>
#include "item.h"

class Playerinfo: public Item {
    int hp;
    int atk;
    int def;
    int gold;
 public:
    Playerinfo(int hp, int atk, int def, int gold);
    virtual int getAtk() override;
    virtual int getDef() override;
    virtual int getHp() override;
    virtual int getGold() override;
};

#endif