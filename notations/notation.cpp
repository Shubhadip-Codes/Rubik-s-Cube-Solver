#include "notation.h"

map<char,Perm>baseMoves = {
    {'U',moveU()},
    {'R',moveR()},
    {'F',moveF()},
    {'D',moveD()},
    {'L',moveL()},
    {'B',moveB()},
};

void applyMoveNotation(Cube &c, string m){
    char face = m[0];
    Perm &p = baseMoves[face];

    if(m.size() == 1){
        applyMove(c,p);
    }
    
    else if(m[1] == '\''){
        for(int i=0;i<3;i++)applyMove(c,p);
    }

    else if(m[1] == '2'){
        for(int i=0;i<2;i++)applyMove(c,p);
    }
}

void applySequence(Cube &c, string s){
    stringstream ss(s);
    string move;
    while(ss >> move)applyMoveNotation(c,move);
}