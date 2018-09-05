#include "floor.h"
#include <string>
#include <vector>

using namespace std;

void gen(){
    
}

Floor::Floor(){
    
}

Floor::~Floor(){
    
}




void Floor::init(Character &p, string floorData, bool randomGen){
    td = new TextDisplay(floorData);
    if (randomGen == false) {
        int n = 0;
        for (int i = 0; i < 25; i++){
            for (int j = 0; j < 79; j++){
                if (floorData[n] == ' '){
                    theFloor[i].push_back(nullptr);
                }
                else if (floorData[n] == '|'){
                    theFloor[i].push_back(new VWall());
                }
                else if (floorData[n] == '-'){
                    theFloor[i].push_back(new HWall());
                }
                else if (floorData[n] == '.'){
                    theFloor[i].push_back(new Tile());
                }
                else if (floorData[n] == '+'){
                    theFloor[i].push_back(new Doorway());
                }
                else if (floorData[n] == '#'){
                    theFloor[i].push_back(new Passage());
                }
                else if (floorData[n] == 'V'){
                    theFloor[i].push_back(new Tile("Vampire"));
                }
                else if (floorData[n] == 'W'){
                    theFloor[i].push_back(new Tile("Werewolf"));
                }
                else if (floorData[n] == 'N'){
                    theFloor[i].push_back(new Tile("Goblin"));
                }
                else if (floorData[n] == 'M'){
                    theFloor[i].push_back(new Tile("Merchant"));
                }
                else if (floorData[n] == 'D'){
                    theFloor[i].push_back(new Tile("Dragon"));
                }
                else if (floorData[n] == 'X'){
                    theFloor[i].push_back(new Tile("Phoenix"));
                }
                else if (floorData[n] == 'T'){
                    theFloor[i].push_back(new Tile("Troll"));
                }
                else if (floorData[n] == '0'){
                    theFloor[i].push_back(new Tile("restoreHealth"));
                }
                else if (floorData[n] == '1'){
                    theFloor[i].push_back(new Tile("boostAtk"));
                }
                else if (floorData[n] == '2'){
                    theFloor[i].push_back(new Tile("boostDef"));
                }
                else if (floorData[n] == '3'){
                    theFloor[i].push_back(new Tile("poisonHealth"));
                }
                else if (floorData[n] == '4'){
                    theFloor[i].push_back(new Tile("woundAtk"));
                }
                else if (floorData[n] == '5'){
                    theFloor[i].push_back(new Tile("woundDef"));
                }
                else if (floorData[n] == '@'){
                    theFloor[i].push_back(new Tile());
                    theFloor[i][j] -> setCharacter(&p);
                    playerRow = i;
                    playerCol = j;
                }
                else if (floorData[n] == '\\'){
                    theFloor[i].push_back(new Tile("Stair"));
                    stairRow = i;
                    stairCol = j;
                }
                else if (floorData[n] == '6'){
                    theFloor[i].push_back(new Tile("Normal"));
                }
                else if (floorData[n] == '7'){
                    theFloor[i].push_back(new Tile("smallHorde"));
                }
                else if (floorData[n] == '8'){
                    theFloor[i].push_back(new Tile("merchantHorde"));
                }
                else if (floorData[n] == '9'){
                    theFloor[i].push_back(new Tile("dragonHorde"));
                }
                theFloor[i][j] -> setCoords(i, j);
                theFloor[i][j] -> attach(td);
                n++;
            }
        }
    }
    else {  //if randonGen == true
        int n = 0;
        for (int i = 0; i < 25; i++){
            for (int j = 0; j < 79; j++){
                if (floorData[n] == ' '){
                    theFloor[i].push_back(nullptr);
                }
                else if (floorData[n] == '|'){
                    theFloor[i].push_back(new HWall());
                }
		else if (floorData[n] == '-'){
		    theFloor[i].push_back(new VWall());
		}
                else if (floorData[n] == '.'){
                    theFloor[i].push_back(new Tile());
                }
                else if (floorData[n] == '+'){
                    theFloor[i].push_back(new Doorway());
                }
                else if (floorData[n] == '#'){
                    theFloor[i].push_back(new Passage());
                }
                n++;
            }
        }
        //start random gen
        gen();
    }
    //start attach all the cells to 8 adjacent cells
    for (int i = 0; i < 25; i++){
        for (int j = 0; j < 79; j++){
            if (theFloor[i][j] -> getSymbol() == '.'||theFloor[i][j] -> getSymbol() == '+'){
                for (int m = -1; m < 1; m++){
                    for (int n = -1; n < 1; n++){
                        theFloor[i][j] -> attach(theFloor[i+m][j+n]);
                    }
                }
            }
        }
    }
}

bool Floor::cleared(){
    if (theFloor[playerRow][playerCol] -> getItem() -> getSymbol() == '\\') return true;
    return false;
}

Item* Floor::usePotion(std::string direction){
    int i, j;
    if (direction == "no"){
        i = -1;
        j = 0;
    }
    else if (direction == "so"){
        i = 1;
        j = 0;
    }
    else if (direction == "we"){
        i = 0;
        j = -1;
    }
    else if (direction == "ea"){
        i = 0;
        j = 1;
    }
    else if (direction == "ne"){
        i = -1;
        j = 1;
    }
    else if (direction == "nw"){
        i = -1;
        j = -1;
    }
    else if (direction == "se"){
        i = 1;
        j = 1;
    }
    else {
        i = 1;
        j = -1;
    }
    if (theFloor[playerRow+i][playerCol+j] -> getItem() != nullptr){
        if (theFloor[playerRow+i][playerCol+j] -> getItem() -> getSymbol() == 'P'){
            theFloor[playerRow][playerCol] -> getCharacter() -> usePotion(*(theFloor[playerRow+i][playerCol+j] -> getItem()));
            Item* temp = theFloor[playerRow+i][playerCol+j] -> getItem();
            theFloor[playerRow+i][playerCol+j] -> setItem(nullptr);
            theFloor[playerRow+i][playerCol+j] -> notifyAll();
            return temp;
        }
	else {
	    return nullptr;
	}
    }
    else
        return nullptr;
}

Combat* Floor::strike(string direction){
    int i, j;
    if (direction == "no"){
        i = -1;
        j = 0;
    }
    else if (direction == "so"){
        i = 1;
        j = 0;
    }
    else if (direction == "we"){
        i = 0;
        j = -1;
    }
    else if (direction == "ea"){
        i = 0;
        j = 1;
    }
    else if (direction == "ne"){
        i = -1;
        j = 1;
    }
    else if (direction == "nw"){
        i = -1;
        j = -1;
    }
    else if (direction == "se"){
        i = 1;
        j = 1;
    }
    else {
        i = 1;
        j = -1;
    }
    if (theFloor[playerRow+1][playerCol+j] -> getCharacter()!= nullptr){
        return new Combat(theFloor[playerRow][playerCol] -> getCharacter(), theFloor[playerRow+i][playerCol+j]->getCharacter());
    }
    else {
        return nullptr;
    }
}

bool Floor::move(std::string direction){
    int i, j;
    if (direction == "no"){
        i = -1;
        j = 0;
    }
    else if (direction == "so"){
        i = 1;
        j = 0;
    }
    else if (direction == "we"){
        i = 0;
        j = -1;
    }
    else if (direction == "ea"){
        i = 0;
        j = 1;
    }
    else if (direction == "ne"){
        i = -1;
        j = 1;
    }
    else if (direction == "nw"){
        i = -1;
        j = -1;
    }
    else if (direction == "se"){
        i = 1;
        j = 1;
    }
    else {
        i = 1;
        j = -1;
    }
    if (theFloor[playerRow+i][playerCol+j] -> getSymbol() == '.'||theFloor[playerRow+i][playerCol+j] -> getSymbol() == '+'||theFloor[playerRow+i][playerCol+j] -> getSymbol() == '#'){
        if (theFloor[playerRow+i][playerCol+j] -> getCharacter() == nullptr){
            if (theFloor[playerRow+i][playerCol+j] -> getItem() == nullptr || theFloor[playerRow+i][playerCol+j] -> getItem() -> getSymbol() == '\\'|| theFloor[playerRow+i][playerCol+j] -> getItem() -> getSymbol() == 'G'){
                if (theFloor[playerRow+i][playerCol+j] -> getItem() -> getSymbol() == 'G'){
                    theFloor[playerRow][playerCol] -> getCharacter() -> useTreasure(*(theFloor[playerRow+i][playerCol+j] -> getItem()));
                    theFloor[playerRow+i][playerCol+j] -> setItem(nullptr);
                }
                theFloor[playerRow+i][playerCol+j] -> setCharacter(theFloor[playerRow][playerCol] -> getCharacter());
                theFloor[playerRow][playerCol] -> setCharacter(nullptr);
                theFloor[playerRow][playerCol] -> notifyAll();
                playerRow += i;
                playerCol += j;
                theFloor[playerRow][playerCol] -> notifyAll();
                theFloor[playerRow][playerCol] -> notifyMoveOnly();
            }
        }
    }
    return false;
}

void Floor::moveEnemies(){
    srand(time(0));
    for (int i = 0; i< 25; i++){
        for (int j = 0; j < 79; j++){
            if (theFloor[i][j] -> getSymbol() == '.') {
                if (theFloor[i][j] -> getCharacter() != nullptr && !(i == playerRow && j == playerCol)){    //when make sure this is an enemy
                    if (theFloor[i][j] -> getCharacter() -> isAction() == false){   //when make sure this enemy has not actioned
                        if (theFloor[i][j] -> getCharacter() -> isHostile() && theFloor[i][j] -> getCharacter() -> isInRange()){  //if fight
                            Combat combat(theFloor[playerRow][playerCol]->getCharacter(), theFloor[i][j]->getCharacter());
                            combat.fight();
                            cout << combat;
                            if (theFloor[playerRow][playerCol] -> getCharacter() -> isDead()){
                                return;
                            }
                            theFloor[i][j] -> getCharacter() -> setAction(true);    //set enemy when has acted
                        }
                        else{   //if move
                            if (theFloor[i][j] -> getCharacter() -> getSymbol() == 'D'){    //if dragon dont move
                                continue;
                            }
                            else {  //other monsters move
                                int deltai, deltaj;
                                while (true){
                                    deltai = rand()%3 - 1;
                                    deltaj = rand()%3 - 1;
                                    if (deltai == 0 && deltaj == 0){
                                        continue;
                                    }
                                    if (theFloor[i+deltai][j+deltaj] -> getSymbol() == '.' && theFloor[i+deltai][j+deltaj] -> getCharacter() == nullptr && theFloor[i+deltai][j+deltaj] -> getItem() == nullptr){ //if can move
                                        break;
                                    }
                                    else
                                        continue;
                                }
                                theFloor[i+deltai][j+deltaj] -> setCharacter(theFloor[i][j] -> getCharacter());
                                theFloor[i][j] -> setCharacter(nullptr);
                                theFloor[i+deltai][j+deltaj] -> getCharacter() -> setAction(true);  //set enemy when has acted
                                theFloor[i][j] -> notifyAll();
                                theFloor[i+deltai][j+deltaj] -> notifyAll();
                                
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i< 25; i++){
        for(int j = 0; j < 79; j++){
            if (theFloor[i][j] -> getSymbol() == '.') {
                if (theFloor[i][j] -> getCharacter() != nullptr && !(i == playerRow && j == playerCol)){
                    theFloor[i][j] -> getCharacter() -> setAction(false);
                    theFloor[i][j] -> getCharacter() -> setInRange(false);
                    
                }
            }
        }
    }
}

Item** Floor::detectPotion(){
    Item** potionList;
    int n = 0;
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (i != 0 && j != 0){
                if (theFloor[playerRow+i][playerCol+j] -> getSymbol() == '.'){
                    if (theFloor[playerRow+i][playerCol+j] -> getItem() -> getSymbol() == 'P'){
                        potionList[n] = theFloor[playerRow+i][playerCol+j] -> getItem();
                        n++;
                    }
                }
            }
        }
    }
    if (n == 0){
        return nullptr;
    }
    return potionList;
}

ostream &operator<<(ostream &out, const Floor &fl) {
        out << *(fl -> td);
        return out;
}
