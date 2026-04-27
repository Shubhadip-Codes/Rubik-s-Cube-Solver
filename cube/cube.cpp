#include "cube.h"

Cube::Cube(){
    state = 
        "UUUUUUUUU"
        "RRRRRRRRR"
        "FFFFFFFFF"
        "DDDDDDDDD"
        "LLLLLLLLL"
        "BBBBBBBBB";

    resetCube();
}

void Cube::updateFaceletFromCubie() {
    state = string(54, ' ');

    const int edgeFacelets[12][2] = {
        {7, 19},  // UF: U(7), F(19)
        {5, 10},  // UR: U(5), R(10)
        {1, 46},  // UB: U(1), B(46)
        {3, 37},  // UL: U(3), L(37)
        {28, 25}, // DF: D(28), F(25)
        {32, 16}, // DR: D(32), R(16)
        {34, 52}, // DB: D(34), B(52)
        {30, 43}, // DL: D(30), L(43)
        {23, 12}, // FR: F(23), R(12)
        {21, 41}, // FL: F(21), L(41)
        {50, 14}, // BR: B(50), R(14)
        {48, 39}  // BL: B(48), L(39)
    };

    const string edgeColor[12] = {
        "UF","UR","UB","UL", "DF","DR","DB","DL", "FR","FL","BR","BL"
    };

    for (int i = 0; i < 12; i++) {
        int piece = edgePos[i];
        int ori = edgeOri[i];
        if (ori == 0) {
            state[edgeFacelets[i][0]] = edgeColor[piece][0];
            state[edgeFacelets[i][1]] = edgeColor[piece][1];
        } else {
            state[edgeFacelets[i][0]] = edgeColor[piece][1];
            state[edgeFacelets[i][1]] = edgeColor[piece][0];
        }
    }

    const int cornerFacelets[8][3] = {
        {8, 20, 9},   // UFR: U(8), F(20), R(9)
        {2, 11, 45},  // URB: U(2), R(11), B(45)
        {0, 47, 36},  // UBL: U(0), B(47), L(36)
        {6, 38, 18},  // ULF: U(6), L(38), F(18)
        {29, 26, 15}, // DFR: D(29), F(26), R(15)
        {35, 17, 51}, // DRB: D(35), R(17), B(51)
        {33, 53, 42}, // DBL: D(33), B(53), L(42)
        {27, 44, 24}  // DLF: D(27), L(44), F(24)
    };

    const string cornerColor[8] = {
        "UFR","URB","UBL","ULF", "DFR","DRB","DBL","DLF"
    };

    for (int i = 0; i < 8; i++) {
        int piece = cornerPos[i];
        int ori = cornerOri[i];
        for (int j = 0; j < 3; j++) {
            // This cycles the colors based on orientation
            state[cornerFacelets[i][j]] = cornerColor[piece][(j + ori) % 3];
        }
    }

    state[4]  = 'U'; state[13] = 'R'; state[22] = 'F';
    state[31] = 'D'; state[40] = 'L'; state[49] = 'B';
}
void Cube::print(){
    cout<<"Cube State\n";
    cout<<state<<endl;
}

void Cube::print2D(){
    auto get = [&](int i){
        return state[i];
    };

    cout<<"       \n";
    for(int i=0;i<9;i++){
        cout<<get(i)<<" ";
        if((i+1)%3 == 0){
            cout<<"\n";
        }
    }
    cout<<"\n";
    for(int row = 0;row<3;row++){
        for(int i=36+row*3;i<36+row*3+3;i++){
            cout<<get(i)<<" ";
        }
        for(int i=18+row*3;i<18+row*3+3;i++){
            cout<<get(i)<<" ";
        }
        for(int i=9+row*3;i<9+row*3+3;i++){
            cout<<get(i)<<" ";
        }
        for(int i=45+row*3;i<45+row*3+3;i++){
            cout<<get(i)<<" ";
        }
        cout<<"\n";
    }

    cout<<"       \n";
    for(int i=27;i<36;i++){
        cout<<get(i)<<" ";
        if((i+1)%3 == 0){
            cout<<"\n";
        }
    }
}
bool Cube :: isSolved(){
    for(int i=0;i<12;i++){
        if(edgePos[i] != i || edgeOri[i] != 0) return false;
    }
    for(int i=0;i<8;i++){
        if(cornerPos[i] != i || cornerOri[i] != 0) return false;
    }
    return true;
}

void Cube :: resetCube(){
    for(int i=0;i<12;i++){
        edgePos[i] = i;
        edgeOri[i] = 0;
    }
    for(int i=0;i<8;i++){
        cornerPos[i] = i;
        cornerOri[i] = 0;
    }
}


