#ifndef _CELL_H_
#define _CELL_H_

#include <iostream>
#include <vector>
#include <string>
#include "character.h"
#include "item.h"
#include "observer.h"
#include "textDisplay.h"


class Cell: public Observer{
    int row;
    int col;
    Character *ch = nullptr;
    Item *it = nullptr;
    std::vector<Observer *> observers;
    char symbol;
public:
    ~Cell();
    int getRow();
    int getCol();
    virtual char getSymbol() = 0;
    void setCharacter(Character *cha);
    void setItem(Item *ite);
    Character* getCharacter();
    Item* getItem();
    void setCoords(int row, int col);
    void attach(Observer *o);
    void notifyAll();
    void notifyMoveOnly();
    SubscriptionType subType() override;
    void notify(Cell &c);
};
#endif
