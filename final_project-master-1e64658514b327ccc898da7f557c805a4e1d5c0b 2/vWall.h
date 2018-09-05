#ifndef _VWALL_H_
#define _VWALL_H_
#include <iostream>
#include "cell.h"

class VWall: public Cell{
public:
    VWall();
    ~VWall();
    char getSymbol();
};


#endif
