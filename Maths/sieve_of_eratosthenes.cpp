#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<bool> isPrimes(n + 1, true);
    isPrimes[0] = false;
    isPrimes[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(isPrimes[i]) {
            for(int j = i * i; j <= n; j += i) {
                isPrimes[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(isPrimes[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}