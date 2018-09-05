#ifndef _PASSAGE_H_
#define _PASSAGE_H_
#include <iostream>
#include "cell.h"

class Passage: public Cell{
public:
    Passage();
    ~Passage();
    char getSymbol();
};

#endif
