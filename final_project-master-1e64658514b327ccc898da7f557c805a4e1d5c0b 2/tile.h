#ifndef _TILE_H_
#define _TILE_H_
#include <string>
#include <iostream>
#include "cell.h"

class Tile: public Cell{
public:
    Tile();
    Tile(std::string a);
    ~Tile();
    char getSymbol();
};

#endif
