#ifndef _DOORWAY_H_
#define _DOORWAY_H_

#include <iostream>
#include "cell.h"

class Doorway: public Cell{
public:
    Doorway();
    ~Doorway();
    char getSymbol();
};

#endif
