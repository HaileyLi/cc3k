#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Item;

class Character {
protected:
    int hp;
    int atk;
    int def;
    int dmgcoe = 100;
public:
    virtual ~Character() = default;

    // for both player and enemy use
    virtual bool isDead() = 0; // determine if this character is dead
    virtual void strike (Character &c) = 0; // "this" strikes "c"
    virtual void bestruckBy (Character &c) = 0; // "c" be struck by "this"
    virtual void setHp(int i) = 0; // plus i golds when pick up a health potion or get struck
    virtual char getSymbol() = 0; //get the symbol of this character
    
    // for player use
    virtual int getAtk() = 0; // get the info of this character's attack value
    virtual int getDef() = 0; // get the info of this character's defense value
    virtual int getHp() = 0; // get the info of this character's health point value
    virtual void setGold(int i) = 0; // plus i golds when pick up a treasure
    virtual int getGold() = 0;  // // get the info of this character's gold amount
    virtual void usePotion(Item &p) = 0; // use a potion
    virtual void useTreasure(Item &p) = 0; // use a treasure
    virtual void takeoff_temp() = 0; // takeoff all the temporary items

    // for enmey use
    virtual void setInRange(bool in) = 0; // set the enemy is in range of attck or not
    virtual bool isInRange() = 0; // determine if this enemy is in range to attack 
    virtual void setAction(bool f) = 0; // set action be false if this round is over
    virtual bool isAction() = 0; // set action be false if this round is over
    virtual bool isHostile() = 0; // determine if this enmey is hostile(will attack you)
};


#endif
