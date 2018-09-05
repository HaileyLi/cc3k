#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>
#include "floor.h"
#include "player.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"

class Game {
	Player *p;  // the Player
	std::vector<Floor> theGame;  // the Floors
	int currFloor = 0;  // the current Floor
	bool won = false;  // is this Game in winning state?
	bool newGame = true; // is this Game object newly created?
	void init(std::string fileName, std::string race); // initializes the Game, clears the old one if necessary
	void resetGame(); // resets the Game state
	void updateWon(); // checks the winning status
	bool playerDead() const; // is the Player defeated?
	
	public:
		Game();  // default constructor
		~Game();  // destructor
		void playGame(std::string fileName = "defaultLayout.txt");  // begins the Game
		friend std::ostream &operator<<(std::ostream &out, const Game &g);  // output operator
};

#endif
