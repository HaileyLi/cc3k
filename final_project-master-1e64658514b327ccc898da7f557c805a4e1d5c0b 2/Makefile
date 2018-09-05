CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = cc3k
OBJECTS = main.o game.o textDisplay.o boostatk.o boostdef.o cell.o character.o combat.o decorator.o doorway.o enemy.o floor.o goblin.o human.o hWall.o item.o merchant.o merchanthorde.o normal.o observer.o orc.o passage.o phoenix.o player.o playerinfo.o poisonhp.o potion.o restorehp.o smallhorde.o stair.o tile.o treasure.o troll.o vampire.o vWall.o werewolf.o woundatk.o wounddef.o dragon.o dragonhoard.o dwarf.o elf.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
