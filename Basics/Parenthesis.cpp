#include<iostream>
#include<vector>
using namespace std;
vector<string> ans;
    void fn(int open, int close, string str, int n) {
    if(open > n) return;
    if(open < close) return;
    if(open + close == 2 * n) {
        ans.push_back(str);
        return;
    }
    fn(open + 1, close, str + "(", n);
    fn(open, close + 1, str + ")", n);
}

int main() {
    string str = "";
    fn(0, 0, str, 4);
    for(string str : ans){
        cout << str << endl;
    }
}