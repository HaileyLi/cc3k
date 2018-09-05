#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include <iostream>
#include <vector>
#include "observer.h"

class Cell;

class Character;

class TextDisplay: public Observer {
	std::vector<std::vector<char>> theDisplay;  // stores the chars representing the floor
	public:
		TextDisplay(std::string floorData);  // constructor
		~TextDisplay();  // destructor
		void notify(Cell &c) override;  // updates the display for Cell t
		SubscriptionType subType() override;  // returns the Subscription type
		friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);  // output operator
};

#endif
