#include "restorehp.h"
#include <string>

using namespace std;

RH(): item{nullptr}, hp{5}, atk{0}, def{0}, name{"RH"}, temp{false} {}

int RH::getHp() {
	return hp;
}

