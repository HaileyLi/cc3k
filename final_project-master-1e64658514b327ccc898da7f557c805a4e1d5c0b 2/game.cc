#include <stdio.h>
#include "game.h"
#include "combat.h"

using namespace std;

Game::Game() {}

Game::~Game() {
	delete p;
}

void Game::init(string fileName, string race) {
	string floorData[5];
	ifstream file;
	file.open(fileName);
	
	bool randomGen;
	if (fileName == "defaultLayout.txt") {
		randomGen = true;
	} else {
		randomGen = false;
	}
	
	if (!newGame) {
		resetGame();
	}
	
	if (race == "h") {
		p = new Human{};
	} else if (race == "e") {
		p = new Human{};
	} else if (race == "d") {
		p = new Human{};
	} else if (race == "o") {
		p = new Human{};
	}
	
	for (int i = 0; i < 5; ++i) {
		Floor newFloor{};
		theGame.emplace_back(newFloor);
		for (int j = 0; j < 25; ++j) {
			char *currRow;
			file.getline(currRow, 79);
			floorData[i] += currRow;
		}
		theGame[i].init(*p, floorData[i], randomGen);  // void Floor::init(Player &p, string floorData, bool randomGen);
	}
	newGame = false;
}

void Game::resetGame() {
	for (int i = 0; i < 5; ++i) {
		theGame.pop_back();
	}
	currFloor = 0;
	won = false;
}

void Game::updateWon() {
	if (theGame[4].cleared()) {  // bool Floor::cleared(); did the Player reach the stairs?
		won = true;
	}
}

bool Game::playerDead() const {
	return p->isDead();
}

void Game::playGame(string fileName) {
	cout << "Welcome to cc3k, please enter a race or quit:" << endl;
	string cmd;
	cin >> cmd;
	if (cmd == "q") {
		return;
	} else {
		init(fileName, cmd);
		cout << *this;
		cout << "Player character has spawned." << endl;
	}
	while (true) {
		if (won || playerDead()) {
			cout << p->getScore() << endl;
			return;
		}
		cin >> cmd;
		if (cmd == "u") {
			cin >> cmd;
			Item *usedPotion = theGame[currFloor].usePotion(cmd);  
			if (usedPotion) {  
				cout << *this;
				cout << "PC uses " << typeid(*usedPotion).name() << "." << endl;
			} else {
				cout << "Invalid action." << endl;
				continue;
			}
		} else if (cmd == "a") {
			cin >> cmd;
			Combat *thisCombat = theGame[currFloor].strike(cmd); // Combat *Floor::strike(string direction);
			if (thisCombat) {  
				thisCombat->fight();
				cout << *this;
				cout << *thisCombat << endl;
				delete thisCombat;
			} else {
				cout << "Invalid action." << endl;
				continue;
			}
		} else if (cmd == "r") {
			playGame();
			return;
		} else if (cmd == "q") {
			return;
		} else {
			if (theGame[currFloor].move(cmd)) {  // bool Floor::move(string direcion);
				cout << *this;
				cout << "PC moves " << cmd;
				Item **detected = theGame[currFloor].detectPotion();  
				if (detected) {  
					cout << " and sees ";
					int numPotions = sizeof(detected);
					for (int i = 0; i < numPotions; ++i) {
						cout << typeid(*detected[i]).name();
						if (i != (numPotions - 1)) {
							cout << ", ";
						}
					}
				}
				cout << "." << endl;
				updateWon();
			} else {
				cout << "Invalid action." << endl;
				continue;
			}
		}
		theGame[currFloor].moveEnemies();  // void Floor::moveEnemies();
		if (theGame[currFloor].cleared()) {
			p->takeoff_temp();  // void Player::removePotions();
			++currFloor;
		}
	}
}

ostream &operator<<(ostream &out, const Game &g) {
	out << g.theGame[g.currFloor];  // prints the Floor
	out << "Race: " << typeid(g.p).name() << " Gold: " << g.p->getGold();
	out << "                                                   ";
	out << "Floor " << g.currFloor + 1 << endl;
	out << "HP: " << g.p->getHp() << endl;
	out << "Atk: " << g.p->getAtk() << endl;
	out << "Def: " << g.p->getDef() << endl;
	out << "Action: ";
	return out;
}
