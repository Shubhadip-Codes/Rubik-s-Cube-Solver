#include "notation.h"
#include <sstream>
#include <stdexcept>

using namespace std;

Move parseMove(const string &m) {
    if(m == "U") return U;
    if(m == "U'") return Ui;
    if(m == "U2") return U2;

    if(m == "D") return D;
    if(m == "D'") return Di;
    if(m == "D2") return D2;

    if(m == "L") return L;
    if(m == "L'") return Li;
    if(m == "L2") return L2;

    if(m == "R") return R;
    if(m == "R'") return Ri;
    if(m == "R2") return R2;

    if(m == "F") return F;
    if(m == "F'") return Fi;
    if(m == "F2") return F2;

    if(m == "B") return B;
    if(m == "B'") return Bi;
    if(m == "B2") return B2;

    throw runtime_error("Invalid move: " + m);
}

void applyMoveNotation(Cube &c, const string &m) {
    Move mv = parseMove(m);
    applyMove(c, mv);
}

void applySequence(Cube &c, const string &s) {
    stringstream ss(s);
    string move;

    while(ss >> move) {
        applyMoveNotation(c, move);
    }
}