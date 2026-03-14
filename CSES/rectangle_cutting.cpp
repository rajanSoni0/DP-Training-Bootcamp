#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
vector<vector<int>> dp;
int solve(int i, int j) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = 1; k < j; k++) {
        ans = min(ans, 1 + solve(i, k) + solve(i, j - k));
    }

    for(int k = 1; k < i; k++) {
        ans = min(ans, 1 + solve(k, j) + solve(i - k, j));
    }

    return dp[i][j] = ans;
}
int main() {
    int a, b;
    cin >> a >> b;
    dp.assign(a + 1, vector<int> (b + 1, -1));
    int min_moves = solve(a, b);
    cout << min_moves << endl;
}