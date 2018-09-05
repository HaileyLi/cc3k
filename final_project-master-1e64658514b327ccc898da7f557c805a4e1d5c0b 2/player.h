#ifndef _PLAYER_H_
#define _PLAYER_H_

class Item;

class Player: public Character {
	int gold = 0;
    Item *item;
public:
    Player();
    virtual ~Player();
    
    // for both player and enemy use
    virtual void strike (Character &c); // "this" strikes "c"
    virtual void bestruckBy (Character &c); // "c" be struck by "this"
    
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
    virtual void setAction(); // set action be false if this round is over
    virtual bool isHostile(); // determine if this emeny is hostile(will attack you)
};
#endif
