#include "cube.h"
#include "moves.h"
int main(){
    Cube c;
    
    cout<<"Solved Cube\n";
    c.print2D();
    auto b = moveB();
    applyMove(c,b);
    c.print2D();
    
}