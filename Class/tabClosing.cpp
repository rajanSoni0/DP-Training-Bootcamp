#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a;
        int b;
        int n;
        cin >> a >> b >> n;
        if(b *n <= a) cout << 1 << endl;
        else cout << 2 << endl;
    }
}