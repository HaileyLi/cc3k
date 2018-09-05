#include "cell.h"


using namespace std;


Cell::~Cell() {}

int Cell::getRow() {return row;}

int Cell::getCol() {return col;}

Character* Cell::getCharacter() {return ch;}

void Cell::setCharacter(Character *cha){
    this -> ch = cha;
}

void Cell::setItem(Item *ite) {
    this -> it = ite;
}

Item* Cell::getItem(){return it;}

void Cell::setCoords(int row, int col){
    this -> row = row;
    this -> col = col;
}

void Cell::attach(Observer *o){
    observers.push_back(o);
}

SubscriptionType Cell::subType() {
    return SubscriptionType::moveOnly;
}

void Cell::notifyAll(){
    int size = observers.size();
    for (int i = 0; i < size; i++){
        if (observers[i] -> subType() == SubscriptionType::All){
            observers[i] -> notify(*this);
        }
    }
}

void Cell::notifyMoveOnly(){
    int size = observers.size();
    for (int i = 0; i < size; i++){
        if (observers[i] -> subType() == SubscriptionType::moveOnly){
            observers[i] -> notify(*this);
        }
    }
}

void Cell::notify(Cell &c){
    if (this -> getCharacter() != nullptr){
        if (getCharacter() -> getSymbol() == 'D') {}
        else
            this -> getCharacter() -> setInRange(true);  //void changeHostile();
    }
}
