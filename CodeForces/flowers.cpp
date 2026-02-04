#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
using namespace std;
const int mod = 1e9 + 7;
// vector<long long> dp;
// long long solve(int low, int high, int k, int size) {
//     if(size > high) return 0;
//     if(dp[size] != -1) return dp[size];
    
//     long long red = solve(low, high, k, size + 1) + (size + 1 >= low && size + 1 <= high ? 1 : 0);
//     long long white = solve(low, high, k, size + k) + (size + k >= low && size + k <= high ? 1 : 0);
//     return dp[size] = ((red) % mod + (white) % mod) % mod;
// }
vector<long long> dp;
vector<long long> prefix;
void bottomUp(int low, int high, int k) {
    for (int i = 1; i < 1000000; i++) {
        dp[i] = dp[i - 1];
        
        if (i >= k)
            dp[i] = (dp[i] + dp[i - k]) % mod;
    }
    prefix[0] = dp[0];
    for(int i = 1; i < 1000000; i++) {
        prefix[i] = (prefix[i - 1] + dp[i]) % mod;

    }
}


int main() {
    int t;
    cin >> t;
    int k;
    cin >> k;
    dp.assign(1000000, 0);
    prefix.assign(1000000, 0);
    dp[0] = 1;
    bottomUp(1, 1e5, k);
    for(int i = 0; i < t; i++) {
        int low;
        int high;
        cin >> low >> high;
        long long ans = (prefix[high] - prefix[low - 1] + mod) % mod;
        cout << ans << endl;
    }
}
