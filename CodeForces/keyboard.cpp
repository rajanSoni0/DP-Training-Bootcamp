#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

void solveR(unordered_map<char, char> &mapR, string &message) {
    for(char &ch : message) {
        ch = mapR[ch];
    }
}
void solveL(unordered_map<char, char> &mapL, string &message) {
    for(char &ch : message) {
        ch = mapL[ch];
    }
}

void buildL(unordered_map<char, char> &mapL, string &s) {
    for(int i = s.size() - 2; i >= 0; i--) {
        mapL[s[i]] = s[i + 1];
    }
}
void buildR(unordered_map<char, char> &mapR, string &s) {
    for(int i = 1; i < s.size(); i++) {
        mapR[s[i]] = s[i - 1];
    }
}
int main() {
    char dir;
    cin >> dir;
    string message;
    cin >> message;
    unordered_map<char, char> mapR;
    string moleR1 = "qwertyuiop";
    string moleR2 = "asdfghjkl;";
    string moleR3 = "zxcvbnm,./";
    mapR['q'] = 'q', mapR['a'] = 'a', mapR['z'] = 'z';
    buildR(mapR, moleR1);
    buildR(mapR, moleR2);
    buildR(mapR, moleR3);
    unordered_map<char, char> mapL;
    mapL['p'] = 'p', mapL[';'] = ';', mapL['/'] = '/';
    buildL(mapL, moleR1);
    buildL(mapL, moleR2);
    buildL(mapL, moleR3);

    if(dir == 'R') solveR(mapR, message);
    else solveR(mapL, message);

    cout << message << endl;
    return 0;
}