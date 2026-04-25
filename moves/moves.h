#ifndef MOVES_H
#define MOVES_H

#include "cube/cube.h"
#include<bits/stdc++.h>
using namespace std;

using Perm = vector<pair<int,int>>;
void applyMove(Cube &c, const Perm &perm);
Perm cycle(vector<int>v);
Perm moveU();
Perm moveR();
Perm moveF();
Perm moveD();
Perm moveL();
Perm moveB();
#endif