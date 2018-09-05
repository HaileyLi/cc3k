#ifndef _PH_H_
#define _PH_H_

#include <string>
#include "potion.h"

class PH: public Potion {
public:
    PH();
    int getHp() override;
};

#endif
