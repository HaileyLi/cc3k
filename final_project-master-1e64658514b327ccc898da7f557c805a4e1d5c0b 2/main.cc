#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {
	Game g;
	if (argc == 2) {
		g.playGame(argv[1]);
	} else {
		g.playGame();
	}
}
