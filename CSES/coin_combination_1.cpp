#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    sort(coins.begin(), coins.end());

    const int mod = 1e9 + 7;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= x; i++) {
        for(int coin : coins) {
            if(coin > i) break;
            dp[i] = (dp[i] + dp[i - coin]) % mod;
        }
    }

    cout << dp[x] << "\n";
}