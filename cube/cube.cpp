#include "cube.h"

Cube::Cube(){
    state = 
        "UUUUUUUUU"
        "RRRRRRRRR"
        "FFFFFFFFF"
        "DDDDDDDDD"
        "LLLLLLLLL"
        "BBBBBBBBB";

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
    return state == 
        "UUUUUUUUU"
        "RRRRRRRRR"
        "FFFFFFFFF"
        "DDDDDDDDD"
        "LLLLLLLLL"
        "BBBBBBBBB";
}


