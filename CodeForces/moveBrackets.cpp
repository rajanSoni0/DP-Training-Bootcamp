#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
using namespace std;

int solve(int n, string &s) {
    stack<char> st;
    for(char &ch : s) {
        if(st.empty() || st.top() == ch) {
            st.push(ch);
        }
        else if(!st.empty() && st.top() == ')' and ch == '(') {
            st.push(ch);
        }
        else{
            st.pop();
        }
    }
    return st.size() / 2;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(n, s) << endl;
    }

}