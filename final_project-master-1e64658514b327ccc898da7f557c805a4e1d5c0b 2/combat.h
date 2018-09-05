#ifndef _COMBAT_H_
#define _COMBAT_H_
#include <iostream>
#include <stdlib.h> 

class Character;

class Combat {
	Character *attacker;  // the attacking Character
	int attackerHP;  // the attacking Character's initial HP
	Character *defender;  // the defending Character
	int defenderHP;  // the defending Character's initial HP
	public:
		Combat(Character *attacker, Character *defender);  // constructor
		~Combat();  // destructor
		void fight();  // starts combat between two Characters
		friend std::ostream &operator<<(std::ostream &out, Combat &c);  // prints the combat information
};


#endif
