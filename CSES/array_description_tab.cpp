#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
vector<vector<int>> dp;
int MOD = 1e9 + 7;
int solve(int n, int m, vector<int> &arr, int idx, int prev) {
    if(idx == n) return 1;

    for(int i = idx; i >= 0; i--) {
        long long ways = 0;
        if(arr[idx] != 0) {
            int x = arr[idx];
            if(idx == 0 || abs(x - prev) <= 1) {
                ways = dp[idx + 1][x];
            }
        }

        else {
            for(int x = 1; x <= m; x++) {
                if(idx == 0 || abs(x - prev) <= 1) {
                    ways = (ways + dp[idx + 1][x]) % MOD;
                }
            }
        }
        dp[i][prev] = ways % MOD;
    }
    

    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    dp.assign(n, vector<int> (m + 1, -1));
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        arr[i] = c;
    }
    cout << solve(n, m, arr, 0, 0);
}