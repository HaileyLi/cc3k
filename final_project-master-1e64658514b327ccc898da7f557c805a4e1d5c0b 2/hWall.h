#ifndef _HWALL_H_
#define _HWALL_H_
#include <iostream>
#include "cell.h"

class HWall: public Cell{
public:
    HWall();
    ~HWall();
    char getSymbol();
};


#endif
