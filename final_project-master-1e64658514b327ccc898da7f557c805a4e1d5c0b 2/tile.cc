#include "tile.h"
#include <string>
#include "character.h"
#include "potion.h"
#include "item.h"
#include "treasure.h"
#include "vampire.h"
#include "werefolf.h"
#include "goblin.h"
#include "merchant.h"
#include "troll.h"
#include "phoenix.h"
#include "dragon.h"
#include "stair.h"
#include "restorehp.h"
#include "boostatk.h"
#include "boostdef.h"
#include "poisonhp.h"
#include "woundatk.h"
#include "wounddef.h"
#include "normal.h"
#include "smallhorde.h"
#include "merchanthorde.h"
#include "dragonhorde.h"
using namespace std;



Tile::Tile() {}

Tile::Tile(string a){
    if (a == "Vampire")
        setCharacter(new Vampire());
    else if (a == "Werewolf")
        setCharacter(new Werewolf());
    else if (a == "Goblin")
        setCharacter(new Goblin());
    else if (a == "Merchant")
        setCharacter(new Merchant());
    else if (a == "Troll")
        setCharacter(new Troll());
    else if (a == "Phoenix")
        setCharacter(new Phoenix());
    else if (a == "Dragon")
        setCharacter(new Dragon());
    else if (a == "Player")
        setCharacter(new Werewolf());
    else if (a == "Stair")
        setItem(new Stair());
    else if (a == "restoreHealth")
        setItem(new RH());
    else if (a == "boostAtk")
        setItem(new BA());
    else if (a == "boostDef")
        setItem(new BD());
    else if (a == "poisonHealth")
        setItem(new PH());
    else if (a == "woundAtk")
        setItem(new WA());
    else if (a == "woundDef")
        setItem(new WD());
    else if (a == "Normal")
        setItem(new Normal());
    else if (a == "smallHorde")
        setItem(new Smallhorde());
    else if (a == "merchantHorde")
        setItem(new Merchanthorde());
    else if (a == "dragonHorde")
        setItem(new Dragonhorde());
}


char Tile::getSymbol(){
    return '.';
}
