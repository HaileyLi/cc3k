#ifndef _POTION_H
#define _POTION_H

#include <string>
#include "decorator.h"

class Potion: public Decorator{
protected:
    int hp;
    int atk;
    int def;
    bool temp;
    std::string name;
    // enum class Kind {PH, WA, WD, RH, BA, BD};
    // Kind kind;
public:
    Potion(int hp, int atk, int def, bool temp, std::string name);
    virtual int getAtk() override;
    virtual int getDef() override;
    virtual int getHp() override;
    virtual int getGold() override;
    virtual std::string getName() override;
    virtual bool isTemp() override;
    virtual void setItem(Item *i) override;
    virtual char getSymbol() override;
    // virtual Kind getKind();
};

#endif
