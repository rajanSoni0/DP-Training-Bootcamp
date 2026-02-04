#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &s, int x) {
    if (s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }
    int top = s.top();
    s.pop();
    insert(s, top);
    s.push(top);
}
void reverse(stack<int> &s) {
    if(s.empty()) return;
    int top = s.top();
    s.pop();
    reverse(s);
    insert(s, top);
}
int main() {
    stack<int> s;
    for(int i = 0; i < 9; i++) {
        s.push(i);
    }
    reverse(s);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

}