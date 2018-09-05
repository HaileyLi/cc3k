#ifndef _troll_H
#define _troll_H

class Troll: public Enemy {
public:
    Troll();
    char getSymbol() override;
};

#endif