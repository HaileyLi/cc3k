#include "decorator.h"

using namespace std;

Decorator::Decorator(): item{nullptr} {}

Decorator::~Decorator() {
	delete item;
}
