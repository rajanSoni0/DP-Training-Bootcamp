#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
vector<int> dp;

int solve(vector<int> &coins, int x) {
    if(x == 0) return 0;
    if(dp[x] != -1) return dp[x];
    int ans = INT_MAX;
    for(int coin : coins) {
        if(coin <= x) {
            int sub = solve(coins, x - coin);
            if(sub != INT_MAX) {
                ans = min(ans, 1 + sub);
            }
            
        }
    }
    return dp[x] = ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins[i] = c;
    }
    dp.assign(x + 1, -1);
    int ans = solve(coins, x);
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}