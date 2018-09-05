#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <iostream>
#include "cell.h"
#include "textDisplay.h"
#include "character.h"
#include "combat.h"
#include "tile.h"
#include "passage.h"
#include "doorway.h"
#include "hWall.h"
#include "vWall.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "potion.h"
#include "enemy.h"
#include "item.h"
class Player;

class Floor {
    std::vector<std::vector<Cell *>> theFloor;
    TextDisplay *td;
    int playerRow;
    int playerCol;
    int stairRow;
    int stairCol;
    void gen();
public:
    Floor();
    ~Floor();
    void init(Character &p, std::string floorData, bool randomGen);
    bool cleared();
    Item* usePotion(std::string direction);
    Combat* strike(std::string direction);
    bool move(std::string direction);
    void moveEnemies();
    Item** detectPotion();
    friend std::ostream &operator<<(std::ostream &out, const Floor &fl);
};

#endif
