#ifndef _Werewolf_H_
#define _Werewolf_H_
#include "enemy.h"

class Werewolf: public Enemy {
public:
    Werewolf();
    char getSymbol() override;
};

#endif
