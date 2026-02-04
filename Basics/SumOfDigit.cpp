#include<iostream>
using namespace std;
int fn(int n) {
    if(n < 10) return n;
    return (n % 10) + fn(n / 10);
}

int main() {
    int n = 6256;
    cout << fn(n) << endl;
}