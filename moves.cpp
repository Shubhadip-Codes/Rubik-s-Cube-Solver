#include "moves.h"

void applyMove(Cube &c, const Perm &perm){
    string temp = c.state;
    for(auto &p : perm){
        c.state[p.second] = temp[p.first];
    }
}

Perm cycle(vector<int>v){
    Perm p;
    int n = v.size();
    for(int i=0;i<n;i++){
        p.push_back({v[i],v[(i+1)%n]});
    }
    return p;
}

Perm moveU(){
    Perm p;
    auto c1 = cycle({0,2,8,6});//corners
    auto c2 = cycle({1,5,7,3});//edges
    //strips
    auto c3 = cycle({18,36,45,9});
    auto c4 = cycle({19,37,46,10});
    auto c5 = cycle({20,38,47,11});

    p.insert(p.end(),c1.begin(),c1.end());
    p.insert(p.end(),c2.begin(),c2.end());
    p.insert(p.end(),c3.begin(),c3.end());
    p.insert(p.end(),c4.begin(),c4.end());
    p.insert(p.end(),c5.begin(),c5.end());

    return p;
}

Perm moveR(){
    Perm p;
    auto c1 = cycle({9,11,17,15});//corners
    auto c2 = cycle({10,14,16,12});//edges
    //strips
    auto c3 = cycle({2,47,29,20});
    auto c4 = cycle({5,50,32,23});
    auto c5 = cycle({8,53,35,26});

    p.insert(p.end(),c1.begin(),c1.end());
    p.insert(p.end(),c2.begin(),c2.end());
    p.insert(p.end(),c3.begin(),c3.end());
    p.insert(p.end(),c4.begin(),c4.end());
    p.insert(p.end(),c5.begin(),c5.end());
    return p;
}
Perm moveF(){
    Perm p;
    auto c1 = cycle({18,20,26,24});//corners
    auto c2 = cycle({19,23,25,21});//edges
    //strips
    auto c3 = cycle({6,9,27,38});
    auto c4 = cycle({7,12,28,41});
    auto c5 = cycle({8,15,29,44});

    p.insert(p.end(),c1.begin(),c1.end());
    p.insert(p.end(),c2.begin(),c2.end());
    p.insert(p.end(),c3.begin(),c3.end());
    p.insert(p.end(),c4.begin(),c4.end());
    p.insert(p.end(),c5.begin(),c5.end());

    return p;
}
Perm moveD(){
    Perm p;
    auto c1 = cycle({29,27,33,35});//corners
    auto c2 = cycle({28,30,34,32});//edges
    //strips
    auto c3 = cycle({24,15,51,42});
    auto c4 = cycle({25,16,52,43});
    auto c5 = cycle({26,17,53,44});
    p.insert(p.end(),c1.begin(),c1.end());
    p.insert(p.end(),c2.begin(),c2.end());
    p.insert(p.end(),c3.begin(),c3.end());
    p.insert(p.end(),c4.begin(),c4.end());
    p.insert(p.end(),c5.begin(),c5.end());

    return p;
}
Perm moveL(){
    Perm p;
    auto c1 = cycle({38,36,42,44});//corners
    auto c2 = cycle({37,39,43,41});//edges
    //strips
    auto c3 = cycle({18,27,45,0});
    auto c4 = cycle({21,30,48,3});
    auto c5 = cycle({24,33,51,6});

    p.insert(p.end(),c1.begin(),c1.end());
    p.insert(p.end(),c2.begin(),c2.end());
    p.insert(p.end(),c3.begin(),c3.end());
    p.insert(p.end(),c4.begin(),c4.end());
    p.insert(p.end(),c5.begin(),c5.end());

    return p;
}
Perm moveB(){
    Perm p;
    auto c1 = cycle({47,45,51,53});//corners
    auto c2 = cycle({46,48,52,50});//edges
    //strips
    auto c3 = cycle({0,36,33,11});
    auto c4 = cycle({1,39,34,14});
    auto c5 = cycle({2,42,35,17});

    p.insert(p.end(),c1.begin(),c1.end());
    p.insert(p.end(),c2.begin(),c2.end());
    p.insert(p.end(),c3.begin(),c3.end());
    p.insert(p.end(),c4.begin(),c4.end());
    p.insert(p.end(),c5.begin(),c5.end());

    return p;
}
