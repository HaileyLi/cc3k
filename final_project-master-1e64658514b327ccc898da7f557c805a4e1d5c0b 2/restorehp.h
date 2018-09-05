#ifndef _RH_H_
#define _RH_H_

#include <string>
#include "potion.h"

class RH: public Potion {
public:
    RH();
    int getHp() override;
};

#endif
