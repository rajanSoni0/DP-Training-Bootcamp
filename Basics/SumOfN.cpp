#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
void fn(int n, int a, int b) {
    if(n == 0) return;
    int c = a + b;
    cout << c << " ";
    fn(n - 1, b, c);
}

int main() {
    cout << 0 << " " << 1 << " ";
    int n = 6;
    fn(n - 2, 0, 1);
}