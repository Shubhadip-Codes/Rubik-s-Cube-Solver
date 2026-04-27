#ifndef MOVES_H
#define MOVES_H

#include "../cube/cube.h"


enum Move {
    U, Ui, U2,
    D, Di, D2,
    L, Li, L2,
    R, Ri, R2,
    F, Fi, F2,
    B, Bi, B2
};

void applyMove(Cube &c, Move m);

#endif