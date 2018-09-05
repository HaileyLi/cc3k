#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>

class Item {
public:
    virtual int getAtk() = 0; // get the attack value of this item
    virtual int getDef() = 0; // get the defense value of this item
    virtual int getHp() = 0; // get the Hp value of this item
    virtual int getGold() = 0; // get the gold value of this item
    virtual bool isTemp() = 0; // get if this item is temporary
    virtual std::string getName() = 0; // get the name of this item
    virtual void setItem(Item *item) = 0; // add a decorator item 
    virtual char getSymbol() = 0; // get the symbol of this item    
    virtual ~Item() = default;
};


#endif
