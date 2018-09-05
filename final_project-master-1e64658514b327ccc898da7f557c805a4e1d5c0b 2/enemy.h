#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

class Enemy: public Character {
    bool action = false;
    bool inRange = false;
public:
    Enemy();
    virtual ~Enemy();

    // for both player and enemy use
    virtual void strike (Character &c) override ; // "this" strikes "c"
    virtual void bestruckBy (Character &c) override; // "c" be struck by "this"
    virtual char getSymbol() override;
    
    // for player use
    virtual int getAtk() override; // get the info of this character's attack value
    virtual int getDef() override; // get the info of this character's defense value
    virtual int getHp() override; // get the info of this character's health point value
    virtual void setGold(int i) override; // plus i golds when pick up a treasure
    virtual int getGold() override;  // // get the info of this character's gold amount
    virtual void usePotion(Item &p) override; // use a potion
    virtual void useTreasure(Item &p) override; // use a treasure
    virtual void takeoff_temp() override; // takeoff all the temporary items

    // for enmey use
    virtual void setInRange(bool in) override; // set the enemy is in range of attck or not
    virtual bool isInRange() override; // determine if this enemy is in range to attack 
    virtual void setAction(bool f) override; // set action be false if this round is over
    virtual bool isAction() override; // set action be false if this round is over
    virtual bool isHostile() override; // determine if this enmey is hostile(will attack you)
};

#endif
