#include "poisonhp.h"
#include <string>

using namespace std;

PH(): item{nullptr}, hp{-5}, atk{0}, def{0}, name{"PH"}, temp{false} {}

int PH::getHp() {
	return hp;
}
