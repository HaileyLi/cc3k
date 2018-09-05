#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include "item.h"

class Decorator: public Item {
protected:
    Item *item;
public:
    Decorator();
    virtual ~Decorator();
};


#endif
