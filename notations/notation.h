#ifndef NOTATION_H
#define NOTATION_H

#include "../cube/cube.h"
#include "../moves/moves.h"

#include <string>
using namespace std;

void applyMoveNotation(Cube &c, const string &m);
void applySequence(Cube &c, const string &s);

#endif