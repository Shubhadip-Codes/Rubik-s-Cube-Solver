#ifndef CUBE_H
#define CUBE_H

#include<bits/stdc++.h>
using namespace std;

class Cube{
    public:
    string state;
    array<int,12> edgePos;
    array<int,12> edgeOri;

    array<int,8> cornerPos;
    array<int,8> cornerOri;
    Cube();
    void print();
    void print2D();
    bool isSolved();
    void resetCube();
    void updateFaceletFromCubie();
};

#endif