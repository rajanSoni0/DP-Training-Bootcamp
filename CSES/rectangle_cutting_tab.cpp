#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
vector<vector<int>> dp;
int solve(int a, int b) {
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            if(i == j) continue;
            int ans = INT_MAX;
            for(int k = 1; k < j; k++) {
                ans = min(ans, 1 + dp[i][k] + dp[i][j - k]);
            }

            for(int k = 1; k < i; k++) {
                ans = min(ans, 1 + dp[k][j] + dp[i- k][j]);
            }

            dp[i][j] = ans;
        }
    }
    return dp[a][b];
}
int main() {
    int a, b;
    cin >> a >> b;
    dp.assign(a + 1, vector<int> (b + 1, 0));
    int min_moves = solve(a, b);
    cout << min_moves << endl;
}