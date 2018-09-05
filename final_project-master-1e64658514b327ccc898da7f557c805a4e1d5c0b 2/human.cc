#include "human.h"
#include <string>

Human::Human(): hp{140}, atk{20}, def{20}, gold{}, dmgcoe{}, item{new Playerinfo(hp, atk, def, gold)} {}
