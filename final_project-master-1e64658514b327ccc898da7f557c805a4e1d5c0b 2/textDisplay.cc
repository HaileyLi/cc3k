#include <iostream>
#include "textDisplay.h"
#include "cell.h"
#include "character.h"

using namespace std;

TextDisplay::TextDisplay(string floorData) {
	int pos = 0;
	for (int currRow = 0; currRow < 79; ++currRow) {
		vector<char> row;
		for (int currCol = 0; currCol < 25; ++currCol) {
			row.emplace_back(floorData[pos]);
			++pos;
		}
		theDisplay.emplace_back(row);
	}
}

TextDisplay::~TextDisplay() {}

void TextDisplay::notify(Cell &c) {
	int row = c.getRow();  // int Cell::getRow();
	int col = c.getCol();  // int Cell::getCol();
	if ((theDisplay[row][col] == '.') ||
		(theDisplay[row][col] == '+') ||
		(theDisplay[row][col] == '#')) {
		if (t.getCharacter()) {
			theDisplay[row][col] = c.getCharacter()->getSymbol();  // Character &Cell::getCharacter();
		} else {
			theDisplay[row][col] = c.getItem()->getSymbol();
	} else {
		theDisplay[row][col] = c.getSymbol();  // char Cell::getSymbol();
	}
}

SubscriptionType TextDisplay::subType() {
	return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (int currRow = 0; currRow < 25; ++currRow) {
		for (int currCol = 0; currCol < 79; ++currCol) {
			out << td.theDisplay[currRow][currCol];
		}
		out << endl;
	}
	return out;
}
