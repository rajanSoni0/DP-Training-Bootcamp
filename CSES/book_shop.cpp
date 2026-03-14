#include <bits/stdc++.h>
using namespace std;
// int solve(vector<int> &prices, vector<int> &pages, int idx, int x) {
//     if(idx == N || x == 0) return 0;
//     if(dp[idx][x] != -1) return dp[idx][x];
//     if(prices[idx] <= x) {
//         int pick = solve(prices, pages, idx + 1, x - prices[idx]) + pages[idx];
//         int notPick = solve(prices, pages, idx + 1, x);
//         return dp[idx][x] = max(pick, notPick);
//     }

//     return dp[idx][x] = solve(prices, pages, idx + 1, x);
// }

int solveTab(vector<int> &prices, vector<int> &pages, int n, int x) {
    vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 1; j <= x; j++) {
            if(prices[i] <= j) {
                int pick = dp[i + 1][j - prices[i]] + pages[i];
                int notPick = dp[i + 1][j];
                dp[i][j] = max(pick, notPick);
            }
            else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }
    return dp[0][x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices[i] = price;
    }

    for(int i = 0; i < n; i++) {
        int page;
        cin >> page;
        pages[i] = page;
    }

    cout << solveTab(prices, pages, n, x);

}