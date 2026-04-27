#include "cube/cube.h"
#include "moves/moves.h"
#include "notations/notation.h"
#include "utils/scramble.h"
int main(){
    Cube c;
    
    cout<<"Solved Cube\n";
    c.updateFaceletFromCubie();
    c.print2D();
      
          applySequence(c,"B2 L' B' U L2 B2 R D F L' D2 F2 B D' B' R B F D2 B");
          applySequence(c,"B' D2 F' B' R' B D B' F2 D2 L F' D' R' B2 L2 U' B L B2");
    c.print2D();
    for(int i=0;i<1000;i++){
        Cube c;
        string s = randomScramble();
        string inv = inverseScramble(s);
        // cout<<s<<endl;
        // cout<<inv<<endl;
         applySequence(c,s);
         applySequence(c,inv);

         if(!c.isSolved()){
                cout<<"BROKEN at :" << s <<" "<<i<<endl;
                c.print2D();
            }
         break;
    }
   
}