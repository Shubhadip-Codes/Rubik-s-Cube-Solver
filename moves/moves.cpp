#include "moves.h"

inline void cycle4(int &a, int &b, int &c, int &d){
    int temp = a;
    a = d;
    d = c;
    c = b;
    b = temp;
}

// Edge indices:
// 0=UF, 1=UR, 2=UB, 3=UL
// 4=DF, 5=DR, 6=DB, 7=DL
// 8=FR, 9=FL, 10=BR, 11=BL

void moveU(Cube &c){
    cycle4(c.edgePos[0], c.edgePos[1], c.edgePos[2], c.edgePos[3]);
    cycle4(c.edgeOri[0], c.edgeOri[1], c.edgeOri[2], c.edgeOri[3]);
    cycle4(c.cornerPos[0], c.cornerPos[1], c.cornerPos[2], c.cornerPos[3]);
    cycle4(c.cornerOri[0], c.cornerOri[1], c.cornerOri[2], c.cornerOri[3]);
    // U corners have no orientation change
}

void moveD(Cube &c){
    cycle4(c.edgePos[4], c.edgePos[5], c.edgePos[6], c.edgePos[7]);
    cycle4(c.edgeOri[4], c.edgeOri[5], c.edgeOri[6], c.edgeOri[7]);
    cycle4(c.cornerPos[4], c.cornerPos[5], c.cornerPos[6], c.cornerPos[7]);
    cycle4(c.cornerOri[4], c.cornerOri[5], c.cornerOri[6], c.cornerOri[7]);
    // D corners have no orientation change
}

void moveR(Cube &c){
    // Edges: UR(1), FR(8), DR(5), BR(10)
    cycle4(c.edgePos[1], c.edgePos[8], c.edgePos[5], c.edgePos[10]);
    cycle4(c.edgeOri[1], c.edgeOri[8], c.edgeOri[5], c.edgeOri[10]);
    // R edges have no orientation change

    // Corners: UFR(0), DFR(4), DRB(5), URB(1)
    cycle4(c.cornerPos[0], c.cornerPos[4], c.cornerPos[5], c.cornerPos[1]);
    cycle4(c.cornerOri[0], c.cornerOri[4], c.cornerOri[5], c.cornerOri[1]);
    c.cornerOri[0] = (c.cornerOri[0] + 2) % 3;
    c.cornerOri[4] = (c.cornerOri[4] + 1) % 3;
    c.cornerOri[5] = (c.cornerOri[5] + 2) % 3;
    c.cornerOri[1] = (c.cornerOri[1] + 1) % 3;
}

void moveL(Cube &c){
    // Edges: UL(3), BL(11), DL(7), FL(9)
    cycle4(c.edgePos[3], c.edgePos[11], c.edgePos[7], c.edgePos[9]);
    cycle4(c.edgeOri[3], c.edgeOri[11], c.edgeOri[7], c.edgeOri[9]);
    // L edges have no orientation change

    // Corners: UBL(2), DBL(6), DLF(7), ULF(3)
    cycle4(c.cornerPos[2], c.cornerPos[6], c.cornerPos[7], c.cornerPos[3]);
    cycle4(c.cornerOri[2], c.cornerOri[6], c.cornerOri[7], c.cornerOri[3]);
    c.cornerOri[2] = (c.cornerOri[2] + 2) % 3;
    c.cornerOri[6] = (c.cornerOri[6] + 1) % 3;
    c.cornerOri[7] = (c.cornerOri[7] + 2) % 3;
    c.cornerOri[3] = (c.cornerOri[3] + 1) % 3;
}

void moveF(Cube &c){
    // Edges: UF(0), FR(8), DF(4), FL(9) — all flip orientation
    cycle4(c.edgePos[0], c.edgePos[8], c.edgePos[4], c.edgePos[9]);
    cycle4(c.edgeOri[0], c.edgeOri[8], c.edgeOri[4], c.edgeOri[9]);
    c.edgeOri[0] ^= 1;
    c.edgeOri[8] ^= 1;
    c.edgeOri[4] ^= 1;
    c.edgeOri[9] ^= 1;

    // Corners: UFR(0), ULF(3), DLF(7), DFR(4)
    cycle4(c.cornerPos[0], c.cornerPos[3], c.cornerPos[7], c.cornerPos[4]);
    cycle4(c.cornerOri[0], c.cornerOri[3], c.cornerOri[7], c.cornerOri[4]);
    c.cornerOri[0] = (c.cornerOri[0] + 1) % 3;
    c.cornerOri[3] = (c.cornerOri[3] + 2) % 3;
    c.cornerOri[7] = (c.cornerOri[7] + 1) % 3;
    c.cornerOri[4] = (c.cornerOri[4] + 2) % 3;
}

void moveB(Cube &c){
    // Edges: UB(2), BL(11), DB(6), BR(10) — all flip orientation
    cycle4(c.edgePos[2], c.edgePos[11], c.edgePos[6], c.edgePos[10]);
    cycle4(c.edgeOri[2], c.edgeOri[11], c.edgeOri[6], c.edgeOri[10]);
    c.edgeOri[2]  ^= 1;
    c.edgeOri[11] ^= 1;
    c.edgeOri[6]  ^= 1;
    c.edgeOri[10] ^= 1;

    // Corners: URB(1), DRB(5), DBL(6), UBL(2)
    cycle4(c.cornerPos[1], c.cornerPos[5], c.cornerPos[6], c.cornerPos[2]);
    cycle4(c.cornerOri[1], c.cornerOri[5], c.cornerOri[6], c.cornerOri[2]);
    c.cornerOri[1] = (c.cornerOri[1] + 1) % 3;
    c.cornerOri[5] = (c.cornerOri[5] + 2) % 3;
    c.cornerOri[6] = (c.cornerOri[6] + 1) % 3;
    c.cornerOri[2] = (c.cornerOri[2] + 2) % 3;
}

void applyMove(Cube &c, Move m){
    switch(m) {
        case U:  moveU(c); break;
        case Ui: moveU(c); moveU(c); moveU(c); break;
        case U2: moveU(c); moveU(c); break;

        case D:  moveD(c); break;
        case Di: moveD(c); moveD(c); moveD(c); break;
        case D2: moveD(c); moveD(c); break;

        case R:  moveR(c); break;
        case Ri: moveR(c); moveR(c); moveR(c); break;
        case R2: moveR(c); moveR(c); break;

        case L:  moveL(c); break;
        case Li: moveL(c); moveL(c); moveL(c); break;
        case L2: moveL(c); moveL(c); break;

        case F:  moveF(c); break;
        case Fi: moveF(c); moveF(c); moveF(c); break;
        case F2: moveF(c); moveF(c); break;

        case B:  moveB(c); break;
        case Bi: moveB(c); moveB(c); moveB(c); break;
        case B2: moveB(c); moveB(c); break;
    }
}