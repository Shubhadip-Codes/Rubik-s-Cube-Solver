#include<bits/stdc++.h>
using namespace std;

string randomScramble(int len){
    vector<string> faces = {"U","R","F","D","L","B"};
    vector<string> suffix = {"","'","2"};

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> fdist(0,5);
    uniform_int_distribution<> sdist(0,2);

    string res = "";
    string last = "";

    for(int i=0;i<len;i++){
        string move;
        while(true){
            string f = faces[fdist(gen)];
            string s = suffix[sdist(gen)];
            move = f + s;

            if(last != "" && last[0] == move[0]) continue;
            break;
        }
        res += move + " ";
        last = move;
    }
    return res;
}

string inverseScramble(string s){
    stringstream ss(s);
    vector<string> moves;
    string m;

    while (ss >> m) moves.push_back(m);

    reverse(moves.begin(), moves.end());

    string res = "";
    for(auto &x : moves){
        if(x.size() == 1) {
            res += x + "' ";
        }
        else if(x.size() == 2 && x[1] == '\'') {
            res += string(1, x[0]) + " ";
        }
        else if(x.size() == 2 && x[1] == '2') {
            res += x + " ";
        }
    }
    return res;
}