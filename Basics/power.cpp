#include<iostream>
using namespace std;
int fn(int x, int n) {
    if(n == 0) return 1;
    int half = fn(x, n / 2);
    return (n % 2 == 0 ? half * half : half * half * x);
}

int main() {
    cout << fn(5, 0) << endl;
}